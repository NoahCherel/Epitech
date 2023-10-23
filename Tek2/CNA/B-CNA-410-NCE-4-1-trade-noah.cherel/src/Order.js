module.exports = class Order {
    constructor(type, pair, amount) {
        this.type = type;
        this.pair = pair;
        this.amount = amount;
    }

    toString() {
        return `${this.type} ${this.pair} ${this.amount}`;
    }
};