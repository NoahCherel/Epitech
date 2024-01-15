import React from "react";
import { createStackNavigator } from "@react-navigation/stack";
import LoginScreen from './Login';
import MainScreen from './MainScreen';
import WeatherScreen from './widgets/WeatherScreen';
import CalendarScreen from './widgets/CalendarScreen';
import AddNoteScreen from "./widgets/AddNoteScreen";

const Stack = createStackNavigator();

const StackNavigator = () => {
    return (
        <Stack.Navigator initialRouteName="Login" screenOptions={{ headerShown: false }}>
            <Stack.Screen name="Login" component={LoginScreen} />
            <Stack.Screen name="Main" component={MainScreen} />
            <Stack.Screen name="Weather" component={WeatherScreen} />
            <Stack.Screen name="CalendarScreen" component={CalendarScreen} />

        </Stack.Navigator>
    );
};

export default StackNavigator;
