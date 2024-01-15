/*import React, { useEffect, useState } from "react";
import { View, Text, Button, StyleSheet, FlatList, Image, TouchableOpacity, SafeAreaView, TextInput } from 'react-native';
import { useRoute } from '@react-navigation/native';
import { Entypo } from '@expo/vector-icons';
import axios from 'axios';
<<<<<<<< HEAD:widgets/Chat.js
import Header from '../Header';
========
import Header from '../Header'
>>>>>>>> e07fc9aac15ec54f1ac10a4416d4ebb52b4aba7c:widget/Chat.js
import { useDataContext } from '../Context';
import { db } from '../Firebase';
import { collection, addDoc, serverTimestamp } from "firebase/firestore";
import { get } from "react-native/Libraries/TurboModule/TurboModuleRegistry";
import { X_GROUP_AUTH } from '@env';

const Chat = ({ navigation }) => {
    const { data } = useDataContext();
    //console.log("access_token: ", data);
    const XGroupAuth = X_GROUP_AUTH;
    const [employeesData, setEmployeesData] = useState([]);
    const Users = collection(db, 'users');
    const Messages = collection(db, 'messages');
    const [message, setMessage] = useState('');

    const getName = async () => {
        const headers = {
            'accept': 'application/json',
            'X-Group-Authorization': XGroupAuth,
            'Authorization': 'Bearer ' + data
        };
        const response = await axios.get('https://masurao.fr/api/employees/me', { headers });
        console.log(response.data);
    };
    getName();

    // Utiliser pour ajouter les premiers utilisateurs, ne pas utiliser par la suite
    const sync = async () => {
        if (!data) {
            throw new Error('Token is null');
        }

        const headers = {
            'accept': 'application/json',
            'X-Group-Authorization': XGroupAuth,
            'Authorization': `Bearer ${data}`,
        };

        try {
            const response = await axios.get('https://masurao.fr/api/employees', { headers });
            setEmployeesData(response.data);
            console.log("GetEmployees success");
            const employeeGetAll = employeesData.map(async (employee) => {
                console.log("employee: ", employee.id)
                const response = await axios.get(`https://masurao.fr/api/employees/${employee.id}`, { headers });
                console.log(response.data)
                const dataToAdd = {
                    birth_date: response.data.birth_date,
                    email: response.data.email,
                    gender: response.data.gender,
                    id: response.data.id,
                    name: response.data.name,
                    surname: response.data.surname,
                    work: response.data.work,
                    privacy: false,
                    admin: false
                };
                addDoc(Users, dataToAdd).then((docRef) => {
                    console.log("Document written with ID: ", docRef.id);
                }).catch((error) => {
                    console.error("Error adding document: ", error);
                });
                console.log("GetEmployee success");
            });
        } catch (error) {
            console.error('Error:', error);
        };

    };

    const sendMessage = async () => {
        if (message == "") return;

        await addDoc(Messages, {
            content: message,
            createdAt: serverTimestamp()
        })
    };

    return (
        <SafeAreaView style={styles.container}>
            <Header style={styles.header} navigation={ navigation }/>
            <TextInput
                placeholder="Entez un message..."
                value={message}
                onChangeText={(text) => setMessage(text)}
            />
            <Button title="Envoyer" onPress={() => console.log(message)} />
        </SafeAreaView>
    )
}*/
import { auth } from "../Firebase";
import React, { useState, useEffect, useLayoutEffect } from "react";
import { View, Text, Button, StyleSheet, FlatList, Image, TouchableOpacity, SafeAreaView, TextInput } from 'react-native';
import { AntDesign } from '@expo/vector-icons';
import { GiftedChat } from "react-native-gifted-chat";
import { db } from "../Firebase";
import { collection, addDoc, onSnapshot } from "firebase/firestore";
import Header from "../components/Header";
import { query, orderBy } from "firebase/firestore";

const Chat = ({ navigation }) => {
    const [messages, setMessages] = useState([])
    const chats = collection(db, 'chats');

    const appendMessages = (messages) => {
        setMessages((previousMessages) => GiftedChat.append(previousMessages, messages))
    }

    useLayoutEffect(() => {
        const q = query(collection(db, 'chats'), orderBy('createdAt', 'desc'));
        const unsubscribe = onSnapshot(q, (snapshot) => setMessages(
            snapshot.docs.map(doc => ({
                _id: doc.data()._id,
                createdAt: doc.data().createdAt.toDate(),
                text: doc.data().text,
                user: doc.data().user,
            }))
        ));

        return () => {
            unsubscribe();
        };
    }, [])

    const SignOut = () => {
        auth.signOut().then(() => {
            navigation.navigate('Login');
        }).catch((error) => {
            console.log(error);
        });
    };

    const onSend = (newMessages = []) => {
        const { _id, createdAt, text, user } = newMessages[0];
        const message = {
            _id,
            createdAt,
            text,
            user
        };

        // Update Firestore with the new message
        addDoc(chats, message)
            .then((docRef) => {
                console.log("Document written with ID: ", docRef.id);
            })
            .catch((error) => {
                console.error("Error adding document: ", error);
            });

        // Don't update the state directly here
        // GiftedChat should manage its own state
    }



    return (
        <View style={styles.container}>
            <View style={styles.header}>
                <Header navigation={ navigation }/>
            </View>
            <GiftedChat
                messages={messages}
                showAvatarForEveryMessage={true}
                onSend={messages => onSend(messages)}
                user={{
                    _id: auth.currentUser.email,
                    name: auth.currentUser.displayName,
                    avatar: auth.currentUser.photoURL
                }}
            />

        </View>
    )
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: '#0D1821'
    },
    header: {
        height: 75,
    }
});

export default Chat
