import React, { useState, useEffect } from 'react';
import {View, Text, StyleSheet, Image} from 'react-native';
import WeatherInfo from './WeatherInfo';
import Header from '../components/Header';
import { SafeAreaView } from 'react-native-safe-area-context';
import { API_KEY_METEO } from '@env';
import * as Location from 'expo-location';
import {Card} from "react-native-paper";

const apiKey = API_KEY_METEO;

const WeatherScreen = ({ navigation, main=false }) => {
  const [weatherData, setWeatherData] = useState(null);
  let [location, setLocation] = useState(null); // Use let instead of const for location
  let locationData = null;

  useEffect(() => {
    const fetchData = async () => {
      try {
        const foregroundPermission = await Location.requestForegroundPermissionsAsync();

        if (foregroundPermission.granted) {
          locationData = await Location.getCurrentPositionAsync({
            accuracy: Location.Accuracy.High,
          });

          if (locationData) {
            const { latitude, longitude } = locationData.coords;
            const apiUrl = `https://api.openweathermap.org/data/2.5/weather?lat=${latitude}&lon=${longitude}&appid=${apiKey}&units=metric&lang=fr`;

            const response = await fetch(apiUrl);
            if (!response.ok) {
              throw new Error('Network response was not ok');
            }

            const data = await response.json();
            setWeatherData(data);
          } else {
            console.error('Location data is missing or undefined.');
          }
        }
      } catch (error) {
        console.error('Error:', error);
        // You can display an error message to the user here.
      }
    };

    fetchData();
  }, []);

  if (main) {
    if (weatherData) {
      const {
        name,
        weather: [{icon, description}],
        main: {temp, humidity, feels_like, temp_min, temp_max, pressure},
        wind: {speed},
        sys: {sunrise, sunset},
      } = weatherData;

      return (
          <Card style={styles.card}>
            <View style={{flexDirection: "row", justifyContent: "flex-start", alignItems: "center"}}>
              <Image source={{uri: `https://openweathermap.org/img/wn/${icon}@4x.png`}} style={{ width: 80, height: 80}} />
              <View style={{justifyContent: "center", alignItems: "center"}}>
                <Text style={{color: '#F2FDFF', fontSize: 20, fontWeight:"bold"}}>{temp}°C</Text>
                <Text style={{color: '#F2FDFF', fontSize: 13 }}>Humidité</Text>
                <Text style={{color: '#F2FDFF', fontSize: 13 }}>{humidity}%</Text>
              </View>
            </View>
          </Card>
      )
    }
    else {
      return (
          <View>
            <Card style={{...styles.card, alignItems:"center"}}>
              <Text style={{color: 'white'}}>Chargement des données météo...</Text>
            </Card>
          </View>
      );
    }
  } else {
    return (
        <SafeAreaView style={styles.container}>
          <Header navigation={navigation}/>
          <View
              style={{flex: 9, justifyContent: 'center', alignItems: 'center'}}>
            {weatherData ? (
                <WeatherInfo WeatherData={weatherData}/>
            ) : (
                <Text style={{color: 'white'}}>Chargement des données météo...</Text>
            )}
          </View>
        </SafeAreaView>
    );
  }
};

export default WeatherScreen;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#0D1821',
  },
  card: {
    width: 200,
    height: 100,
    backgroundColor: '#462964',
    padding: 10,
    borderRadius: 20,
    borderColor: '#8D89A6',
    borderWidth: 1,
  }
});
