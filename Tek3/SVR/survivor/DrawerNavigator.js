import React from 'react';
import { createDrawerNavigator} from '@react-navigation/drawer';
import { NavigationContainer } from '@react-navigation/native';
import StackNavigator from './StackNavigator';
import LoginScreen from './Login';
import MainScreen from './MainScreen';
import Profile from './Profile';

import WeatherScreen from './widgets/WeatherScreen';
import Combined from './widgets/Combined';
import { DataContextProvider } from './Context';
import CalendarScreen from './widgets/CalendarScreen';
import Chat from './widgets/Chat';
import NewsPage from './widgets/NewsPage';
import Notes from './widgets/Notes';
import AddNoteScreen from './widgets/AddNoteScreen';
import InitFCM from './widgets/InitFCM';
import DateTime from './widget/DateTime';

const Drawer = createDrawerNavigator();

const DrawerNavigator = () => {
    return (
        <NavigationContainer>
            <DataContextProvider>
                <Drawer.Navigator initialRouteName="Login" screenOptions={{ headerShown: false }}>
                    <Drawer.Screen name="Login" component={LoginScreen} options={{ drawerItemStyle: { display : "none"} }} />
                    <Drawer.Screen name="Main" component={MainScreen} />
                    <Drawer.Screen name="Weather" component={WeatherScreen} />
                    <Drawer.Screen name="Profile" component={Profile} />
                    <Drawer.Screen name="Combined" component={Combined} />
                    <Drawer.Screen name="CalendarScreen" component={CalendarScreen} />
                    <Drawer.Screen name="Chat" component={Chat} />
                    <Drawer.Screen name="NewsPage" component={NewsPage} />
                    <Drawer.Screen name="Notes" component={Notes} />
                    <Drawer.Screen name="AddNoteScreen" component={AddNoteScreen} options={{ drawerItemStyle: { display : "none"} }} />
                    <Drawer.Screen name="InitFCM" component={InitFCM} />
                    <Drawer.Screen name="DateTime" component={DateTime} />
                </Drawer.Navigator>
            </DataContextProvider>
        </NavigationContainer>
    )
};

export default DrawerNavigator;
