import React from 'react';
import { createDrawerNavigator} from '@react-navigation/drawer';
import { NavigationContainer } from '@react-navigation/native';
import StackNavigator from './StackNavigator';
import LoginScreen from '../pages/Login';
import MainScreen from '../pages/MainScreen';
import WeatherScreen from '../widget/WeatherScreen';
import Profile from '../pages/Profile';
import TeamProfile from "../pages/TeamProfile";
import Combined from './Combined';
import Notes from '../widget/Notes';
import { DataContextProvider } from '../Context';
import CalendarScreen from '../widget/CalendarScreen';
import { Dimensions, StatusBar, Text, TouchableOpacity, View } from "react-native";
import CustomDrawerContent from "./DrawerContent";
import drawerItem from "react-native-paper/src/components/Drawer/DrawerItem";
import InitFCM from "../widget/InitFCM";
import AddNoteScreen from "./AddNoteScreen";
import NewsPage from "../widget/NewsPage";
import DateTime from "../widget/DateTime";
import Chat from "../widget/Chat";

const Drawer = createDrawerNavigator();

const CustomDrawerItem = ({ label, focused, onPress }) => {

    return (
        <TouchableOpacity onPress={onPress}>
            <Text style={{ color: 'white', fontSize: 16, fontWeight: 'bold' }}>{label}</Text>
        </TouchableOpacity>
    );
};


const DrawerNavigator = () => {
    return (
        <NavigationContainer>
            <StatusBar barStyle="light-content" hidden={false}/>
            <DataContextProvider>
                <Drawer.Navigator
                    initialRouteName="Login"
                    screenOptions={{ headerShown: false }}
                    drawerContent={props => <CustomDrawerContent {...props} />}
                >
                    <Drawer.Screen name="Login" component={LoginScreen}
                                    options={{
                                        drawerItemStyle: { display : "none"}
                                    }}/>
                    <Drawer.Screen name="Main" component={MainScreen}
                                    options={{
                                        drawerLabel: "Accueil",
                                        drawerLabelStyle: { color: 'white', fontSize: 16, fontWeight: 'bold' },
                                    }}/>
                    <Drawer.Screen name="Weather" component={WeatherScreen}
                                    options={{
                                        drawerLabel: "Météo",
                                        drawerLabelStyle: { color: 'white', fontSize: 16, fontWeight: 'bold' },
                                    }}/>
                    <Drawer.Screen name="Profile" component={Profile}
                                    options={{
                                        drawerLabel: "Profile",
                                        drawerLabelStyle: { color: 'white', fontSize: 16, fontWeight: 'bold' },
                                    }}/>
                    <Drawer.Screen name="Combined" component={Combined}
                                    options={{
                                        drawerLabel: "Trombinoscope",
                                        drawerLabelStyle: { color: 'white', fontSize: 16, fontWeight: 'bold' },
                                    }}/>
                    <Drawer.Screen name="CalendarScreen" component={CalendarScreen}
                                    options={{
                                        drawerLabel: "Calendrier",
                                        drawerLabelStyle: { color: 'white', fontSize: 16, fontWeight: 'bold' },
                                    }}/>
                    <Drawer.Screen name="Notes" component={Notes}
                                    options={{
                                        drawerLabel: "Notes",
                                        drawerLabelStyle: { color: 'white', fontSize: 16, fontWeight: 'bold' },
                                    }}/>
                    <Drawer.Screen name="NewsPage" component={NewsPage}
                                    options={{
                                        drawerLabel: "Informations",
                                        drawerLabelStyle: { color: 'white', fontSize: 16, fontWeight: 'bold' },
                                    }}/>

                    <Drawer.Screen name="DateTime" component={DateTime}
                                    options={{
                                        drawerLabel: "Date et Heure",
                                        drawerLabelStyle: { color: 'white', fontSize: 16, fontWeight: 'bold' },
                                    }}/>
                    <Drawer.Screen name="Chat" component={Chat}
                                        options={{
                                        drawerLabel: "Discussion",
                                        drawerLabelStyle: { color: 'white', fontSize: 16, fontWeight: 'bold' },
                                    }}/>
                    <Drawer.Screen name="InitFCM" component={InitFCM}
                                    options={{
                                        drawerLabel: "InitFCM",
                                        drawerLabelStyle: { display: "none" },
                                    }}/>
                    <Drawer.Screen name="AddNoteScreen" component={AddNoteScreen}
                                    options={{
                                        drawerLabelStyle: { display: "none"},
                                    }}/>
                    <Drawer.Screen name="TeamProfile" component={TeamProfile}
                                    options={{
                                        drawerItemStyle: { display : "none"}
                                    }} />
                </Drawer.Navigator>
            </DataContextProvider>
        </NavigationContainer>

    )
};

const styles = {
    wrapper: {
        flex: 1,
        backgroundColor: '#462964',
    },
    header: {
        flex: 1,
        backgroundColor: '#462964',
    },
}
export default DrawerNavigator;
