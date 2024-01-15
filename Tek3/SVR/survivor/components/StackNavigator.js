import React from "react";
import { createStackNavigator } from "@react-navigation/stack";
import LoginScreen from '../pages/Login';
import MainScreen from '../pages/MainScreen';
import WeatherScreen from '../widget/WeatherScreen';
import CalendarScreen from '../widget/CalendarScreen';
import header from "./Header";
import TeamProfile from "../pages/TeamProfile";

const Stack = createStackNavigator();

const StackNavigator = () => {
    return (
        <Stack.Navigator initialRouteName="Login" screenOptions={{ headerShown: false }}>
            <Stack.Screen name="Login" component={LoginScreen}/>
            <Stack.Screen name="Main" component={MainScreen}/>
            <Stack.Screen name="Weather" component={WeatherScreen} />
            <Stack.Screen name="CalendarScreen" component={CalendarScreen} />
            <Stack.Screen name="Calendar" component={CalendarScreen} />
            <Stack.Screen name="TeamProfile" component={TeamProfile} initialParams={{access_token: "1", employeeId: "1", navigation: "1"}}/>

        </Stack.Navigator>
    );
};

export default StackNavigator;
