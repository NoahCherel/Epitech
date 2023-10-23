// Import the required modules
const Order = require('./Order');

function calculateSellAmount(btcAmount, btcPrice) {
  return btcAmount * btcPrice;
}

class Strategy {
  constructor() {}

  execute(gameSettings, state) {
    let dollars = state.stacks['USDT'];
    const btcChart = state.charts['USDT_BTC'];
    let btcAmount = state.stacks['BTC'];
    const lastBtcClosePrice = btcChart.getCandleAt(state.date).close;
    const transactionFee = gameSettings.transactionFee;

    // Calculate Bollinger Bands for BTC
    const btcBbPeriod = 20;
    const btcBbStdDev = 2;
    let btcPriceData = btcChart.getCandles().map(candle => candle.close);
    const btcBb = calculateBollingerBands(btcPriceData, btcBbPeriod, btcBbStdDev);
    const btcMiddleBand = btcBb.middleBand;
    const btcUpperBand = btcBb.upperBand;
    const btcLowerBand = btcBb.lowerBand;

    // Calculate RSI for BTC
    const btcRsiPeriod = 14;
    const btcRsi = calculateRsi(btcPriceData, btcRsiPeriod);
    const lastBtcRsi = btcRsi[btcRsi.length - 1];

    const btcBuyThreshold = btcLowerBand[btcLowerBand.length - 1];
    const btcSellThreshold = btcUpperBand[btcUpperBand.length - 1];

    // Decide whether to buy or sell BTC based on Bollinger Bands, RSI, and trend confirmation
    const currentTrend = determineTrend(btcMiddleBand);
    const isTrendingUp = currentTrend === 'up';
    const isTrendingDown = currentTrend === 'down';

    // Flag to track the goal status
    let goalMet = false;

    // Console log for debugging
    if (lastBtcClosePrice <= btcBuyThreshold && lastBtcRsi < 90) {
      console.error("Buying BTC")
      console.error("For the bot to buy, the price must be below: ", btcBuyThreshold);
      console.error("For the bot to sell, the price must be above: ", btcSellThreshold);
      console.error("The current price is: ", lastBtcClosePrice);
      console.error("The current RSI is: ", lastBtcRsi);
      console.error("The current trend is: ", currentTrend);
    }

    if (lastBtcClosePrice >= btcSellThreshold && lastBtcRsi > 30 && isTrendingDown) {
      console.error("Selling BTC")
      console.error("For the bot to buy, the price must be below: ", btcBuyThreshold);
      console.error("For the bot to sell, the price must be above: ", btcSellThreshold);
      console.error("The current price is: ", lastBtcClosePrice);
      console.error("The current RSI is: ", lastBtcRsi);
      console.error("The current trend is: ", currentTrend);
    }

    if (lastBtcClosePrice <= btcBuyThreshold && lastBtcRsi < 90) {
      btcAmount = calculatePositionSize(dollars, lastBtcClosePrice);

      // Check if the goal is met
      if (dollars > 1020 || calculateSellAmount(btcAmount, lastBtcClosePrice) > 1020) {
        goalMet = true;
        // sell all BTC
        if (state.stacks['BTC'] > 0) {
          btcAmount = state.stacks['BTC'];
          const btcOrder = new Order('sell', 'USDT_BTC', btcAmount);
          const transactionCost = calculateTransactionCost(btcAmount, lastBtcClosePrice, transactionFee);
          dollars += btcAmount * lastBtcClosePrice - transactionCost;
          return btcOrder.toString();
        }
      }

      if (goalMet) {
        return 'pass';
      }

      if (btcAmount < 0.01) {
        return 'pass';
      }
      const btcOrder = new Order('buy', 'USDT_BTC', btcAmount);
      const transactionCost = calculateTransactionCost(btcAmount, lastBtcClosePrice, transactionFee);
      dollars -= btcAmount * lastBtcClosePrice + transactionCost;

      return btcOrder.toString();
    } else if (lastBtcClosePrice >= btcSellThreshold && lastBtcRsi > 30) {
      const sellAmount = Math.min(btcAmount, calculatePositionSize(dollars, lastBtcClosePrice));

      // Check if the goal is met
      if (dollars > 1020 || calculateSellAmount(btcAmount, lastBtcClosePrice) > 1020) {
        goalMet = true;
        // sell all BTC
        if (state.stacks['BTC'] > 0) {
          btcAmount = state.stacks['BTC'];
          const btcOrder = new Order('sell', 'USDT_BTC', btcAmount);
          const transactionCost = calculateTransactionCost(btcAmount, lastBtcClosePrice, transactionFee);
          dollars += btcAmount * lastBtcClosePrice - transactionCost;
          return btcOrder.toString();
        }
      }

      if (goalMet) {
        return 'pass';
      }

      if (sellAmount < 0.01) {
        return 'pass';
      }
      const btcOrder = new Order('sell', 'USDT_BTC', sellAmount);
      const transactionCost = calculateTransactionCost(sellAmount, lastBtcClosePrice, transactionFee);
      dollars += sellAmount * lastBtcClosePrice - transactionCost;

      return btcOrder.toString();
    }

    // If the goal is met, stop trading and pass till the end
    // Check if the goal is met
    if (dollars > 1020 || calculateSellAmount(btcAmount, lastBtcClosePrice) > 1020) {
      goalMet = true;
      // sell all BTC
      if (state.stacks['BTC'] > 0) {
        btcAmount = state.stacks['BTC'];
        const btcOrder = new Order('sell', 'USDT_BTC', btcAmount);
        const transactionCost = calculateTransactionCost(btcAmount, lastBtcClosePrice, transactionFee);
        dollars += btcAmount * lastBtcClosePrice - transactionCost;
        return btcOrder.toString();
      }
    }

    return 'pass';
  }
}

function calculateBollingerBands(priceData, period, stddev) {
    const middleBand = [];
    const upperBand = [];
    const lowerBand = [];
  
    for (let i = period - 1; i < priceData.length; i++) {
      const slice = priceData.slice(i - period + 1, i + 1);
      const average = slice.reduce((acc, val) => acc + val, 0) / period;
      const stdDev = Math.sqrt(
        slice
          .map(val => Math.pow(val - average, 2))
          .reduce((acc, val) => acc + val, 0) / period
      );
      middleBand.push(average);
      upperBand.push(average + stddev * stdDev);
      lowerBand.push(average - stddev * stdDev);
    }
  
    return {
      middleBand,
      upperBand,
      lowerBand,
    };
  }
  
  /**
   * Calculates the average of an array of numbers.
   * @param {number[]} data - Array of numbers.
   * @returns {number} Average value.
   */
  function calculateAverage(data) {
    return data.reduce((acc, val) => acc + val, 0) / data.length;
  }
  
  /**
   * Calculates the Relative Strength Index (RSI) for a given price data array and period.
   * @param {number[]} priceData - Array of price data.
   * @param {number} period - RSI period.
   * @returns {number[]} Array of RSI values.
   */
  function calculateRsi(priceData, period) {
    const changes = [];
    for (let i = 1; i < priceData.length; i++) {
      changes.push(priceData[i] - priceData[i - 1]);
    }
  
    const gains = changes.map(change => (change > 0 ? change : 0));
    const losses = changes.map(change => (change < 0 ? Math.abs(change) : 0));
  
    let averageGain = calculateAverage(gains.slice(0, period));
    let averageLoss = calculateAverage(losses.slice(0, period));
  
    const rsiValues = [];
    rsiValues.push(100 - 100 / (1 + averageGain / averageLoss));
  
    for (let i = period; i < priceData.length - 1; i++) {
      const currentGain = gains[i];
      const currentLoss = losses[i];
  
      averageGain = (averageGain * (period - 1) + currentGain) / period;
      averageLoss = (averageLoss * (period - 1) + currentLoss) / period;
  
      rsiValues.push(100 - 100 / (1 + averageGain / averageLoss));
    }
  
    return rsiValues;
  }

// Determines the current trend based on the middle band.
function determineTrend(middleBand) {
  const currentPrice = middleBand[middleBand.length - 1];
  const previousPrice = middleBand[middleBand.length - 2];
  if (currentPrice > previousPrice) {
    return 'up';
  } else if (currentPrice < previousPrice) {
    return 'down';
  } else {
    return 'neutral';
  }
}

// Calculates the position size based on available dollars and the current price.
function calculatePositionSize(dollars, currentPrice) {
  const maxPositionSize = dollars / currentPrice;
  // Adjust the maximum position size based on your risk management rules
  const positionSize = Math.min(maxPositionSize, 0.1);
  return positionSize;
}

// Calculates the transaction cost for a given trade.
function calculateTransactionCost(amount, price, fee) {
  const cost = amount * price;
  const transactionCost = cost * fee;
  return transactionCost;
}

module.exports = Strategy;
