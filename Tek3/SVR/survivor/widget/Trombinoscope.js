import React, { useState, useEffect } from 'react';
import {View, Text, StyleSheet, TouchableOpacity, Image} from 'react-native';
import axios from 'axios';
import { API_KEY_JOKES } from '@env';
import Blagues from 'blagues-api';
import { Card, Button } from 'react-native-paper';
import { X_GROUP_AUTH } from '@env';
import { useDataContext } from '../Context';
import {useNavigation, useRoute} from "@react-navigation/native";
import {Buffer} from "buffer";

const Trombinoscope = () => {
    const data = useDataContext();
    const [nb, setNb] = useState(1);
    const navigation = useNavigation();
    const [employeesData, setEmployeesData] = useState([]);
    const [employeeImages, setEmployeeImages] = useState({});
    const route = useRoute();
    const { images } = route.params;
    const goToTrombi = () => {
        navigation.navigate('Combined');
    }

    useEffect(() => {
        getEmployees();
    }, []);

    useEffect(() => {
        if (employeesData.length > 0) {
            getEmployeeImages();
        }
    }, [employeesData]);

    const getEmployees = async () => {
        if (!data.data) {
            throw new Error('Token is null');
        }

        const headers = {
            'accept': 'application/json',
            'X-Group-Authorization': X_GROUP_AUTH,
            'Authorization': `Bearer ${data.data}`,
        };

        try {
            const response = await axios.get('https://masurao.fr/api/employees', { headers });
            setEmployeesData(response.data);
            console.log("GetEmployees success");
        } catch (error) {
            console.error('Error:', error);
        }
    };

    const getEmployeeImages = async () => {
        if (!data.data) {
            throw new Error('Token is null');
        }

        const headers = {
            'accept': 'image/png',
            'X-Group-Authorization': X_GROUP_AUTH,
            'Authorization': `Bearer ${data.data}`,
        };

        try {
            const employeeImageRequests = employeesData.map(async (employee) => {
                const response = await axios.get(`https://masurao.fr/api/employees/${employee.id}/image`, {
                    headers,
                    responseType: 'arraybuffer',
                });

                const base64ImageData = Buffer.from(response.data, 'binary').toString('base64');
                return { id: employee.id, image: base64ImageData };
            });

            const employeeImages = await Promise.all(employeeImageRequests);

            const imageMap = employeeImages.reduce((acc, { id, image }) => {
                acc[id] = image;
                return acc;
            }, {});

            setEmployeeImages(imageMap);

            console.log("GetImages success");
        } catch (error) {
            console.error('Error:', error);
        }
    };

    setTimeout(() => {
        setNb(nb + 1);
        if (nb >= employeeImages.length + 1) {
            setNb(1);
        }

    }, 3000);

    return (
        <TouchableOpacity
            onPress={goToTrombi}
            style={styles.container}>
            <Card style={styles.card}>
                <View style={{alignItems: 'center'}}>
                    <Image source={{ uri: `data:image/png;base64,${employeeImages[nb]}` }}
                           style={styles.image}/>
                </View>
            </Card>
        </TouchableOpacity>
    );
}

export default Trombinoscope;

const styles = StyleSheet.create({
    container: {
        width: '80%',
        height: '20%',
        marginTop: 20,
    },

    card: {
        backgroundColor: '#462964',
        borderRadius: 20,
        padding: 10,
        height: 200,
        borderColor: '#8D89A6',
        borderWidth: 1,
    },
    image: {
        width: '60%',
        height: '100%',
        borderRadius: 20,
    }
});
