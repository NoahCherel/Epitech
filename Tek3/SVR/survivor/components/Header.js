import React from "react";
import {Image, StyleSheet, TouchableOpacity, View} from 'react-native';
import DrawerTrigger from './DrawerTrigger';
import { Card } from 'react-native-paper';
import {access} from "@babel/core/lib/config/validation/option-assertions";
const Header = ({ navigation }) => {

    const routeToMain = () => {
        if (navigation.state !== 'Main')
            navigation.navigate('Main', {navigation});
    }

    return (
        <View style={styles.header}>
            <Card style={styles.card}>
                <DrawerTrigger navigation={navigation} />
            </Card>
            <TouchableOpacity style={styles.touchable} onPress={() => routeToMain()}>
                <Image style={styles.logo} source={require('../assets/logo_survivor.png')} />
            </TouchableOpacity>
        </View>
    );
};

export default Header;

const styles = StyleSheet.create({
    header: {
        flex: 1,
        backgroundColor: '#0D1821',
        flexDirection: 'row',
        justifyContent: 'space-between',
    },

    card: {
        margin: '3%',
        backgroundColor: '#462964',
        alignItems: 'center',
        justifyContent: 'center',
        borderColor: '#8D89A6',
        borderWidth: 1,
    },

    touchable: {
        margin: '3%',
        width: '12%',
    },

    logo: {
        width: '100%',
        height: '100%',
    }
});
