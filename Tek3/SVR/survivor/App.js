/*import React from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import LoginScreen from './Login';
import MainScreen from './MainScreen';
import Profile from './Profile';
import WeatherScreen from './WeatherScreen';

const Stack = createStackNavigator();

export default function App() {
  return (
    <NavigationContainer>
      <Stack.Navigator initialRouteName="Login" screenOptions={{ headerShown: false }}>
        <Stack.Screen name="Login" component={LoginScreen} />
        <Stack.Screen name="Main" component={MainScreen} />
        <Stack.Screen name="Profile" component={Profile} />
        <Stack.Screen name="Weather" component={WeatherScreen} />
      </Stack.Navigator>
    </NavigationContainer>
  );
}*/


import 'react-native-gesture-handler';
import React from 'react';
import DrawerNavigator from './components/DrawerNavigator';
import StackNavigator from "./components/StackNavigator";
import {StatusBar} from "react-native";
import { LogBox } from 'react-native';

LogBox.ignoreAllLogs();

const App = () => {
  return (
      <DrawerNavigator />
  );
};

export default App;
/*
import 'react-native-gesture-handler';
import React from 'react';
import { createAppContainer } from '@react-navigation/native';
import { createDrawerNavigator } from '@react-navigation/drawer';

import MainScreen from './MainScreen';
import WeatherScreen from './WeatherScreen';
import Login from './Login';

const DrawerNavigator = createDrawerNavigator({
  Login,
  MainScreen,
  WeatherScreen
});

export default creaeAppContainer(DrawerNavigator);*/
