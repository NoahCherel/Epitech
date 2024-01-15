import React, { useState, useEffect } from 'react';
import { View, Text, Button, StyleSheet, FlatList, Image, TouchableOpacity, SafeAreaView } from 'react-native';
import Svg, { Circle, Line } from 'react-native-svg';
import { format } from 'date-fns';
import { fr } from 'date-fns/locale';
import Header from '../components/Header';
import {Card} from "react-native-paper";

const AnalogClock = ( { navigation } ) => {

    const [currentTime, setCurrentTime] = useState(new Date());

    useEffect(() => {
        const intervalId = setInterval(() => {
            setCurrentTime(new Date());
        }, 1000);

        return () => clearInterval(intervalId);
    }, []);

    const clockSize = 190; // Diameter of the clock face
    const centerX = clockSize / 2; // X-coordinate of the clock center
    const centerY = clockSize / 2; // Y-coordinate of the clock center
    const clockRadius = clockSize / 2 - 10; // Radius of the clock face
    const hourHandLength = clockRadius * 0.5; // Length of the hour hand
    const minuteHandLength = clockRadius * 0.7; // Length of the minute hand
    const secondHandLength = clockRadius * 0.8; // Length of the second hand

    const hour = currentTime.getHours() % 12;
    const minute = currentTime.getMinutes();
    const second = currentTime.getSeconds();
    const formattedDate = format(currentTime, 'EEEE d MMMM yyyy', { locale: fr });
    const greetingMessage = "Bonne journée !"; // Greeting message in French

    // Calculate the angles for hour, minute, and second hands
    const hourAngle = ((hour + minute / 60) * 360 / 12) % 360;
    const minuteAngle = ((minute + second / 60) * 360 / 60) % 360;
    const secondAngle = (second * 360 / 60) % 360;

    return (
        <View style={styles.wrapper}>
            <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center' }}>
                <Svg height={clockSize} width={clockSize}>
                    {/* Clock face */}
                    <Circle
                        cx={centerX}
                        cy={centerY}
                        r={clockRadius}
                        stroke="black" // Clock border color
                        strokeWidth="8"
                        fill="white"
                    />
                    {/* Hour markers */}
                    {Array.from({ length: 12 }).map((_, index) => {
                        const angle = (index * 360) / 12;
                        const markerX = centerX + (clockRadius - 20) * Math.cos((angle - 90) * (Math.PI / 180));
                        const markerY = centerY + (clockRadius - 20) * Math.sin((angle - 90) * (Math.PI / 180));
                        return (
                            <Circle
                                key={index}
                                cx={markerX}
                                cy={markerY}
                                r="6"
                                fill="black" // Marker color
                            />
                        );
                    })}
                    {/* Hour hand */}
                    <Line
                        x1={centerX}
                        y1={centerY}
                        x2={centerX + hourHandLength * Math.cos((hourAngle - 90) * (Math.PI / 180))}
                        y2={centerY + hourHandLength * Math.sin((hourAngle - 90) * (Math.PI / 180))}
                        stroke="red" // Hour hand color
                        strokeWidth="8"
                    />
                    {/* Minute hand */}
                    <Line
                        x1={centerX}
                        y1={centerY}
                        x2={centerX + minuteHandLength * Math.cos((minuteAngle - 90) * (Math.PI / 180))}
                        y2={centerY + minuteHandLength * Math.sin((minuteAngle - 90) * (Math.PI / 180))}
                        stroke="black" // Minute hand color
                        strokeWidth="6"
                    />
                    {/* Second hand */}
                    <Line
                        x1={centerX}
                        y1={centerY}
                        x2={centerX + secondHandLength * Math.cos((secondAngle - 90) * (Math.PI / 180))}
                        y2={centerY + secondHandLength * Math.sin((secondAngle - 90) * (Math.PI / 180))}
                        stroke="black" // Second hand color
                        strokeWidth="4"
                    />
                    {/* Central circle */}
                    <Circle cx={centerX} cy={centerY} r="10" fill="black" />
                </Svg>
            </View>
        </View>
    );
};

const styles = StyleSheet.create({
    wrapper: {
        flex: 1,
        backgroundColor: '#0D1821', // Background color
    },
    header: {
        height: 75,
    },
    dateText: {
        marginTop: 10, // Spacing between clock and date
        fontSize: 20, // Date font size
        color: '#F2FDFF', // Date text color
        fontWeight: 'bold', // Date text bold
        textTransform: 'capitalize', // Capitalize the date text
    },
    greetingText: {
        marginTop: 10, // Spacing between date and greeting
        fontSize: 18, // Greeting font size
        color: '#F2FDFF', // Greeting text color
    },
});

export default AnalogClock;
