import React, {useEffect, useState} from "react";
import { View, Text, Image, StyleSheet, FlatList, TextInput, TouchableOpacity } from 'react-native';
import axios from "axios";
import Header from "../components/Header";
import employees from "../components/Employees";
import {Buffer} from "buffer";
import { X_GROUP_AUTH } from '@env';
import {useDataContext} from "../Context";

const TeamProfile = ({ route, navigation }) => {
    const { access_token, employee } = route.params;
    const XGroupAuth = X_GROUP_AUTH;

    const data = useDataContext();
    const [nb, setNb] = useState(1);
    // const navigation = useNavigation();
    const [employeesData, setEmployeesData] = useState([]);
    const [employeeImages, setEmployeeImages] = useState({});
    const [employeeProfile, setEmployeeProfile] = useState({});



    useEffect(() => {
        getEmployees();
        fetchEmployeeProfile(employee.id);
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

    const fetchEmployeeProfile = async (employeeId) => {
        if (!data.data) {
            throw new Error('Token is null');
        }

        const headers = {
            'accept': 'application/json',
            'X-Group-Authorization': X_GROUP_AUTH,
            'Authorization': `Bearer ${data.data}`,
        };

        try {
            const response = await axios.get(`https://masurao.fr/api/employees/${employeeId}`, { headers });
            setEmployeeProfile(response.data);
        } catch (error) {
            console.error('Error fetching employee profile:', error);
        }
    };
    console.log(employee);

    return (
        <View style={styles.container}>
            <View style={styles.header}>
                <Header navigation={navigation}/>
            </View>
            <View style={{alignItems: 'center', marginTop: 20}}>
                <Image
                    source={{ uri: `data:image/png;base64,${employeeImages[employee.id]}` }}
                    style={styles.image}
                />
            </View>
            <View style={styles.data}>
                <Text style={styles.textFont}>{employee.name} {employee.surname} </Text>
                <Text style={styles.textFont}>Work: {employeeProfile.work}</Text>
                <Text style={styles.textFont}>Birth Date: {employeeProfile.birth_date}</Text>
                <Text style={styles.textFont}>Email: {employee.email}</Text>
                <View style={{alignItems: 'center', marginTop: 20}}>
                    <TouchableOpacity style={styles.loginButton} onPress={() => navigation.navigate('Combined')} >
                        <Text style={{ color: '#F2FDFF', fontWeight: 'bold', fontSize: 20}}>Back</Text>
                    </TouchableOpacity>
                </View>
            </View>
        </View>
    );
};

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: '#0D1821',
    },
    data : {
        marginTop: 50,
        flex: 1,
        backgroundColor: '#462964',
        borderTopLeftRadius: 30,
        borderTopRightRadius: 30,
    },
    textFont : {
        marginTop: 15,
        color: '#F2FDFF',
        fontWeight: 'bold',
        fontSize: 20,
        textAlign: 'center',
    },
    header: {
        height: 70,
    },
    image: {
        width: 250,
        height: 350,
        borderRadius: 30,
    },
    loginContainer: {
        flex: 1,
    },
    loginButton: {
        width: 100,
        height: 44,
        padding: 5,
        marginBottom: 20, // Add space above the button
        borderRadius: 26,
        backgroundColor: '#0D1821', // Background color of the button
        alignItems: 'center',
    },
});

export default TeamProfile;
