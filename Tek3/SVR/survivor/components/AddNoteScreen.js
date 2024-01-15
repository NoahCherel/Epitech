import React, { useState, useContext, cloneElement } from 'react';

import { View, Text, TextInput, StyleSheet } from 'react-native';
import Header from './Header';
import { Button } from 'react-native-paper';
import { db } from '../Firebase';
import { collection, addDoc, serverTimestamp, doc } from "firebase/firestore";
import axios from 'axios';
import { X_GROUP_AUTH } from '@env';
const XGroupAuth = X_GROUP_AUTH;
import { useDataContext } from '../Context';

const AddNoteScreen = ({ navigation }) => {
    const [title, setTitle] = useState('');
    const [description, setDescription] = useState('');
    const { data } = useDataContext();
    const Users = collection(db, 'users');
    const Notes = collection(db, 'notes');
    const handleSaveNote = async () => {
        const headers = {
            'accept': 'application/json',
            'X-Group-Authorization': XGroupAuth,
            'Authorization': 'Bearer ' + data
        };

        try {
            //const response = await axios.get('https://masurao.fr/api/employees/me', { headers });
            const dataToAdd = {
                title: title,
                description: description,
                author: 74
            };
            console.log(dataToAdd);
            const docRef = await addDoc(Notes, dataToAdd);
            /*addDoc(Notes, dataToAdd).then((docRef) => {
              console.log("Document written with ID: ", docRef.id);
            }).catch((error) => {
              console.error("Error adding document: ", error);
            });*/
            //console.log(response.data);
            console.log("Document written with ID: ", docRef.id);
            navigation.navigate('Notes');
        } catch (error) {
            console.error(error);
        }
    };

    return (

        <View style={styles.container}>
            <View style={styles.headerContainer}>
                <Header navigation={navigation} />
            </View>


            <Text style={styles.label}>Title:</Text>
            <TextInput
                style={styles.input}
                value={title}
                onChangeText={setTitle}
                placeholderTextColor={'#F2FDFF'}
                placeholder="Enter a Title"
            />

            <Text style={styles.label}>Description:</Text>
            <TextInput
                style={styles.input}
                value={description}
                onChangeText={setDescription}
                placeholder="Enter a Description"
                placeholderTextColor={'#F2FDFF'}
                multiline
            />

            <View style={{alignItems: 'center'}}>
                <Button onPress={handleSaveNote} style={styles.button} >
                    <Text style={{ color: '#F2FDFF', fontWeight: 'bold' }}>Save</Text>
                </Button>
            </View>
        </View>
    );
};

const styles = StyleSheet.create({
    container: {
        flex: 1,
        justifyContent: "flex-start",
        backgroundColor: '#0D1821',
    },
    headerContainer: {
        height: 74,
    },
    label: {
        fontSize: 16,
        marginTop: 20,
        marginBottom: 8,
        color: '#F2FDFF',
        fontWeight: 'bold',
    },
    input: {
        fontSize: 16,
        borderColor: 'gray',
        borderRadius: 20,
        padding: 8,
        marginBottom: 16,
        backgroundColor: '#462964',
        textAlign: 'center',
        color: '#F2FDFF',
    },
    button: {
        width: 100,
        marginTop: 50,
        backgroundColor: '#462964',
    }
});

export default AddNoteScreen;
