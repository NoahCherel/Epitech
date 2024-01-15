import React, {Component, useState} from 'react';
import {
  Alert,
  TextInput,
  View,
  StyleSheet,
  Text,
  TouchableOpacity,
  Image
} from 'react-native';
import Icon from 'react-native-vector-icons/FontAwesome'; // Import the icon library
import { Svg, Path } from 'react-native-svg'; // Import SVG components
import { Dialog } from "react-native-paper";
import {X_GROUP_AUTH} from "@env";
import {useDataContext} from "../Context";
import axios from "axios";
import {collection} from "firebase/firestore";
import {db} from "../Firebase";

const App = (props) => {

  const { setSharedData } = useDataContext();
  const Users = collection(db, 'users');

  const [credentials, setCredentials] = useState({
    email: '',
    password: '',
  });

  const onLogin = () => {
    const headers = {
      'X-Group-Authorization': X_GROUP_AUTH,
    };


    try {
      console.log(credentials);
      console.log(headers);

      axios.post('https://masurao.fr/api/employees/login', credentials, {headers})
          .then((response) => {
            //console.log(response.data);
            //console.log("Test1: " + response.data.access_token);
            setSharedData(response.data.access_token);
            //console.log("Login success " + response.data.access_token);
            props.navigation.navigate('Main', {
              username: credentials.email,
              password: credentials.password
            });
          }).catch((error) => {
            Alert.alert('Invalid credentials', 'Please check your username and password.');
            console.log('Err: ', error.response.data);
          }
      );
    } catch (error) {
      console.error('Error:', error);
    }
  }

  return (
      <View style={styles.container}>
        <Image source={require("../assets/logo_survivor.png")} style={styles.image}></Image>
        {/*<Text style={{ fontSize: 30, fontWeight: 'bold', marginBottom: 30, alignItems: 'center' , color:'#F2FDFF'}}>Login</Text>*/}

        {/* Username input */}
        <View style={styles.inputContainer}>
          <Icon name="user" size={24} color="#462964" style={styles.icon} />
          <TextInput
              value={credentials.email}
              onChangeText={(text) => setCredentials({...credentials, email: text})}
              placeholder={'Identifiant'}
              placeholderTextColor={'#F2FDFF'}
              selectionColor={'#F2FDFF'}
              style={styles.input}
          />
        </View>

        {/* Password input */}
        <View style={styles.inputContainer}>
          <Icon name="lock" size={24} color="#462964" style={styles.icon} />
          <TextInput
              value={credentials.password}
              onChangeText={(password) => setCredentials({...credentials, password: password})}
              placeholder={'Mot de passe'}
              placeholderTextColor={'#F2FDFF'}
              secureTextEntry={true}
              style={styles.input}
              selectionState={false}
              aria-selected={false}
          />
        </View>
        <View style={styles.loginContainer}>
          <TouchableOpacity style={styles.loginButton} onPress={onLogin.bind()}>
            <Text style={{ color: '#F2FDFF' }}>Connexion</Text>
          </TouchableOpacity>
        </View>
      </View>
  );

}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    backgroundColor: '#0D1821',
  },

  alert: {
    backgroundColor: '#F2FDFF',
  },

  image: {
    aspectRatio: 0.6,
    resizeMode: 'contain'
  },

  inputContainer: {
    flexDirection: 'row',
    alignItems: 'center',
  },

  loginContainer: {
    flexDirection: "row",
    alignItems: "center",
    justifyContent: "center"
  },

  input: {
    color: '#F2FDFF',
    "width": 250,
    "height": 44,
    "padding": 10,
    "borderWidth": 1,
    "borderStyle": "solid", // Use "solid" for the border style
    "borderColor": "rgba(0, 0, 0, 0.2)", // Set border color separately
    "backgroundColor": "#462964",
    "marginBottom": 20,
    "borderRadius": 26,
    "fontWeight": "light",
  },

  icon: {
    marginRight: 10, // Spacing between icon and input field
    marginBottom: 20,
  },

  loginButton: {
    width: 100,
    height: 44,
    marginBottom: 20, // Add space above the button
    borderRadius: 26,
    "padding": 10,
    "borderWidth": 1,
    "borderStyle": "solid", // Use "solid" for the border style
    backgroundColor: '#462964', // Background color of the button
    alignItems: 'center',
    "fontWeight": "light",
  },
});

export default App;
