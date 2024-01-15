import React, { useEffect, useState } from 'react';
import { View, Text, Button, StyleSheet, FlatList, Image, TouchableOpacity, SafeAreaView, ViewBase} from 'react-native';
import { useRoute } from '@react-navigation/native';
import axios from 'axios';
import Header from '../components/Header'
import { useDataContext } from '../Context';
import { X_GROUP_AUTH } from '@env';
import Jokes from '../components/Jokes'
import Trombi from "../widget/Trombinoscope";
import Weather from "../widget/WeatherScreen";
import { createUserWithEmailAndPassword, updateProfile, signInWithEmailAndPassword } from "firebase/auth";
import { getIdToken } from "firebase/auth";
import { auth, db } from '../Firebase';
import DateTime from "../widget/DateTimeCard";

export default function MainScreen({ navigation }) {
    const { setSharedData } = useDataContext();
    const { data } = useDataContext();
    //const { data } = useDataContext();
    //const [data, setData] = useState([]);
    const [access_token, setToken] = useState(null);
    const XGroupAuth = X_GROUP_AUTH;
    const route = useRoute();
    const { username, password } = route.params;
    const email = username;
    const [idset, setIdSet] = useState(null);


    const headers = {
        'accept': 'application/json',
        'X-Group-Authorization': XGroupAuth,
        'Content-Type': 'application/json',
        'Access-Control-Allow-Origin': '*',
        'Authorization': 'Bearer ' + data,
    };

    const getInfoMe = async () => {
        if (!data) {
            throw new Error('Token is null');
        }

        const headers = {
            'accept': 'application/json',
            'X-Group-Authorization': XGroupAuth,
            'Authorization': 'Bearer ' + access_token,
        };

        try {
            axios.get('https://masurao.fr/api/employees/me', { headers })
                .then((response) => {
                    //console.log(response.data);
                    setData(response.data);
                    console.log("GetInfoMe success")
                })
                .catch((error) => {
                        console.log(error);
                    }
                );
        } catch (error) {
            console.error('Error:', error);
        }
    };

    const getImages = async () => {

        const headers = {
            'accept': 'image/png',
            'X-Group-Authorization': XGroupAuth,
            'Authorization': `Bearer ${data}`,
        };

        try {
            const response = await axios.get(`https://masurao.fr/api/employees/${idset}/image`, {
                headers,
                responseType: 'arraybuffer',
            });

            const base64ImageData = Buffer.from(response.data, 'binary').toString('base64');
            setImageData(base64ImageData);
            console.log("GetImages success");
        } catch (error) {
            console.error('Idset: ', idset);
            console.error('Error Img:', error);
        }
    };

    const register = () => {
        createUserWithEmailAndPassword(auth, email, password)
            .then((userCredential) => {
                const user = userCredential.user;
                //console.log("avatar: ", imageData);

                getIdToken(user)
                    .then((idToken) => {

                        const avatar = imageData;
                        if (!avatar) {
                            throw new Error('Avatar is null');
                        }
                        updateProfile(user, {
                            displayName: username,
                            photoURL: avatar,
                        })
                            .then(() => {
                                console.log("Profile updated");
                            })
                            .catch((error) => {
                                console.log("Error: ", error);
                            });
                    })
                    .catch((error) => {
                        console.log("Error getting ID token: ", error);
                    });
            })
            .catch((error) => {
                const errorCode = error.code;
                const errorMessage = error.message;
                console.log("Error: ", errorCode, errorMessage);
            });
    };

    const signIn = () => {
        signInWithEmailAndPassword(auth, email, password)
            .then((userCredential) => {
                const user = userCredential.user;
                console.log("User signed in: ", user);
            })
            .catch((error) => {
                const errorCode = error.code;
                const errorMessage = error.message;
                console.log("Error: ", errorCode, errorMessage);
            });
    };

    useEffect(() => {
            if (data) {
                getInfoMe();
                getImages();
            }
            register();
            signIn();
        }
        , [data]);

    return (
        <SafeAreaView style={styles.wrapper}>
            <View style={styles.header}>
                <Header navigation={navigation} style={styles.header} />
            </View>
            <View style={styles.container}>
                <Jokes />
                <View style={styles.basic}>
                    <DateTime/>
                    <Weather main={true}/>
                </View>
                <Trombi/>
            </View>
        </SafeAreaView>
    );
}

const styles = StyleSheet.create({
    wrapper: {
        flex: 1,
        backgroundColor: '#0D1821',
        justifyContent: 'flex-start',
    },

    header: {
        height: 75,
    },

    container: {
        alignItems: 'center',
        justifyContent: 'flex-start',
        height: '50%',
    },

    basic: {
        flex: 1,
        alignItems: 'center',
        justifyContent: 'center',
        flexDirection: 'row',
    },

    mainText: {
        color: 'white',
        fontWeight: 'bold',
        fontSize: 20,
    },
});
