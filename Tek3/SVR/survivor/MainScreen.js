import React, { useContext, useEffect, useState } from 'react';
import { View, Text, Button, StyleSheet, FlatList, Image, TouchableOpacity, SafeAreaView } from 'react-native';
import { useRoute } from '@react-navigation/native';
import axios from 'axios';
import Header from './Header'
import { useDataContext } from './Context';
import { auth, db } from './Firebase';
import { X_GROUP_AUTH } from '@env';
import Jokes from './components/Jokes'
import { createUserWithEmailAndPassword, updateProfile, signInWithEmailAndPassword } from "firebase/auth";
import { getIdToken } from "firebase/auth";
import { Buffer } from 'buffer';
import { id } from 'date-fns/locale';

export default function MainScreen({ navigation }) {
  const { data, setData } = useDataContext();
  const [imageData, setImageData] = useState(null);
  const [access_token, setToken] = useState(null);
  const [idToken, setIdToken] = useState(null);
  const [idset, setIdSet] = useState(null);

  const XGroupAuth = X_GROUP_AUTH;
  const route = useRoute();
  const { username, password } = route.params;
  const email = username;

  const getInfoMe = async () => {
    if (!data) {
      throw new Error('Token is null');
    }

    const headers = {
      'accept': 'application/json',
      'X-Group-Authorization': XGroupAuth,
      'Authorization': 'Bearer ' + data,
    };

    try {
      const response = await axios.get('https://masurao.fr/api/employees/me', { headers });
      console.log('GetInfoMe success');
      setIdSet(response.data.id);
      console.log("Idset: ", idset);

    } catch (error) {
      console.error('Error:', error);
    }
  };
const login = async () => {
    try {
      const q = query(Users, where("email", "==", username));
      console.log(q);
      const querySnapshot = await getDocs(q);
      console.log(querySnapshot);
      console.log(querySnapshot.size);

      if (querySnapshot.size == 0) {
        console.log('No matching documents.');
        const response = await axios.get('https://masurao.fr/api/employees/me', { headers });
        console.log(response.data);
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
      }
    } catch (error) {
      console.error('Error:', error);
    };
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
        console.log("avatar: ", imageData);

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
        //console.log("User signed in: ", user);
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
      <Header navigation={navigation} style={{ height : '10%'}} />
      <View style={styles.container}>
        <Text>Blague du jour!</Text>
        <Jokes />
        <Button title="Logout" onPress={() => navigation.navigate('Login')} />
        <Button title="Go to Profile" onPress={() => navigation.navigate('Profile', { access_token: data })} />
        <Button title="Go to Combined" onPress={() => navigation.navigate('Combined', { access_token: data })} />
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  wrapper: {
    height: '100%',
  },
  header: {
    width: '100%',
    backgroundColor: '#98029D',
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-between',
  },
  menu: {
    margin: '10px'
  },
  username: {
  },
  logout: {
    margin: '10px'
  },
  mainText: {
    color: 'white',
    fontWeight: 'bold',
    fontSize: 20,
    fontFamily: 'Verdana'
  },
  container: {
    height: '90%',
    alignItems: 'center',
    justifyContent: 'center',
    backgroundColor: '#ecf0f1',
    padding: 16,
  },
  grid: {
    alignItems: 'center',
    justifyContent: 'flex-start',
  },
  image: {
    margin: 8,
  },
});
