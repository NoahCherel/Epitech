import React from 'react';
import { View, Text, TouchableOpacity, StyleSheet } from 'react-native';
import { DrawerContentScrollView, DrawerItemList, DrawerItem } from '@react-navigation/drawer';
import axios from "axios";
import {useRoute} from "@react-navigation/native";

const CustomDrawerContent = (props) => {

    return (
        <DrawerContentScrollView {...props} style={styles.container}>

            <DrawerItemList {...props}/>

        </DrawerContentScrollView>
    );
};

const styles = StyleSheet.create({
    container: {
        backgroundColor: '#462964',
        width: '100%',
        borderBlockColor: '#0D1821',
    },
});

export default CustomDrawerContent;
