import React from 'react';
import { View, Text, SafeAreaView, StyleSheet, Image, Dimensions } from 'react-native';
import { useFonts } from 'expo-font';
import { Card } from 'react-native-paper'

const MyCard = ({title, data, mesure}) => {
    return(
        <View style={styles.cardView}>
            <Card style={styles.card}>
                <Text style={styles.cardText}>{title}</Text>
                <Text style={styles.cardText}>{data} {mesure}</Text>
            </Card>
        </View>
    )
}

const WeatherInfo = ({WeatherData}) => {
    const {
        name,
        weather: [{icon, description}],
        main: {temp, humidity, feels_like, temp_min, temp_max, pressure},
        wind: {speed},
        sys: {sunrise, sunset},
    } = WeatherData;

    return (
        <SafeAreaView style={(styles.container)}>
            <View style={(styles.header)}>
                <Text style={(styles.title)}>{name}</Text>
            </View>
            <View style={(styles.iconView)}>
                <Image source={{uri: `https://openweathermap.org/img/wn/${icon}@4x.png`}} style={{width: 200, height: 200}} />
                <Text style={(styles.description)}>{temp} °C</Text>
            </View>
            <View style={styles.cardContainer}>
                <MyCard title={"Humidité"} data={humidity} mesure={"%"}/>
                <MyCard title={"Ressenti"} data={feels_like} mesure={"°C"}/>
            </View>
            <View style={styles.cardContainer}>
                <MyCard title={"Vent"} data={speed} mesure={"m/s"}/>
                <MyCard title={"Pression"} data={pressure} mesure={"hPa"}/>
            </View>
        </SafeAreaView>
    )
};

export default WeatherInfo;

const styles = StyleSheet.create({
    container: {
        flex: 1,
    },
    header: {
        alignItems: 'center',
    },
    title: {
        width: '100%',
        textAlign: 'center',
        fontSize: 40,
        color: 'white',
    },
    iconView: {
        alignItems: 'center',
        justifyContent: 'center'
    },
    icon: {
        width: 200,
        height: 200,
    },
    description: {
        fontSize: 40,
        color: 'white',
    },
    tempView: {
        alignItems: 'center'
    },
    temp: {
        fontSize: 20,
        color: 'white',
    },
    windView: {
        alignItems: 'center'
    },
    wind: {
        fontSize: 20,
        color: 'white',
    },
    cardContainer: {
        flexDirection: "row",
        justifyContent: "center",
        alignItems: "center"
    },
    cardView: {
        flex: 1,
        alignItems: "center",
    },
    card: {
        backgroundColor: '#462964',
        alignItems: "center",
        justifyContent: "center",
        width: 150,
        height: 100,
        marginTop: 40,
        borderColor: '#8D89A6',
        borderWidth: 1,
    },
    cardText: {
        textAlign: "center",

        color: 'white',
        fontSize: 20,
    }

});
