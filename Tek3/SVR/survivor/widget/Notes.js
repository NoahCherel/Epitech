import React, { useState, useRef, useEffect } from 'react';
import { View, Text, TouchableOpacity, TextInput, StyleSheet, FlatList } from 'react-native';
import { useNavigation } from '@react-navigation/native'; // Import useNavigation from React Navigation
import AddNoteScreen from '../components/AddNoteScreen';
import Header from '../components/Header';
import { db } from '../Firebase';
import { getDocs, collection, addDoc, serverTimestamp, doc , query, where} from "firebase/firestore";

const Note = ({ note, onEditPress }) => {
    const [isEditing, setIsEditing] = useState(false);
    const [noteText, setNoteText] = useState(note.text);

    const handleEditPress = () => {
    setIsEditing(!isEditing);
    };

    const handleNoteTextChange = (text) => {
    setNoteText(text);
    note.text = text;
    };

    return (
        <SafeAreaView>
            <TouchableOpacity onPress={handleEditPress}>
                <View style={styles.noteContainer}>
                {isEditing ? (
                    <TextInput
                    style={styles.noteInput}
                    value={noteText}
                    onChangeText={handleNoteTextChange}
                    autoFocus
                    />
                ) : (
                    <Text style={styles.noteText}>{noteText || '+'}</Text>
                )}
                </View>
            </TouchableOpacity>
        </SafeAreaView>
    );
};

const NoteGrid = () => {
    const [notes, setNotes] = useState([]);
    const newNoteRef = useRef(null);
    const navigation = useNavigation();
    const Notes = collection(db, 'notes');

    const addNewNote = () => {
        navigation.navigate('AddNoteScreen');
        getNotes();
    };

    const getNotes = async () => {
        console.log("test");
        try {
            const q = query(Notes, where("author", "==", 74));
            const querySnapshot = await getDocs(q);
            console.log("Notes: ", querySnapshot.docs.map((doc) => doc.data()));
            setNotes(querySnapshot.docs.map((doc) => doc.data()));
        } catch (error) {
            console.log("Error getting documents: ", error);
        }
    };

    console.log("before");
    useEffect(() => {
        getNotes();
    }, []);

    return (
        <View style={{ height: '100%', backgroundColor: '#0D1821' }}>
            <Header navigation={ navigation } style={{ height: "10%" }} />
            <View style={{ height: "90%" }}>
                <FlatList
                    data={notes}
                    renderItem={({ item }) => (
                        <View style={{
                            borderWidth: 1,
                            borderColor: '#8D89A6',
                            borderRadius: 25,
                            backgroundColor: '#462964',
                            padding: 10,
                            margin: 10,
                        }} >
                            <Text style={styles.noteText}>{item.title}</Text>
                            <Text style={styles.noteText}>{item.description}</Text>
                        </View>
                    )}
                />
                <TouchableOpacity onPress={addNewNote} style={styles.addButton}>
                <Text style={styles.addButtonText}>+</Text>
                </TouchableOpacity>
            </View>
        </View>
    );
};

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: '#0D1821',
    },
    headerContainer: {
        height: '10%',
    },

    addButton: {
        width: 50,
        height: 50,
        borderRadius: 25,
        backgroundColor: 'blue',
        justifyContent: 'center',
        alignItems: 'center',
        position: 'absolute',
        bottom: 20,
        right: 20,
    },
    addButtonText: {
        fontSize: 30,
        color: 'white',
    },
    noteContainer: {
        width: 100,
        height: 100,
        backgroundColor: '#0D1821',
        justifyContent: 'center',
        alignItems: 'center',
        borderWidth: 1,
        borderColor: '#8D89A6',
    },
    noteText: {
        fontSize: 24,
        color: '#F2FDFF',
    },
    noteInput: {
        fontSize: 24,
        paddingHorizontal: 5,
        minWidth: 80,
        color: '#F2FDFF',
    },
});

export default NoteGrid;
