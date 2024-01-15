import React from "react";
import { TouchableOpacity, Text } from "react-native";
import { Entypo } from '@expo/vector-icons';

const DrawerTrigger = ({ navigation }) => {
    const openDrawer = () => {
        navigation.openDrawer();
    }

    return (
        <TouchableOpacity onPress={openDrawer}>
            <Entypo name="menu" size={48} color="white" />
        </TouchableOpacity>
    );
};

export default DrawerTrigger;
