import React, { Component, useContext, useState } from 'react';
import { Alert, TextInput, View, StyleSheet, Text, TouchableOpacity } from 'react-native';
import Icon from 'react-native-vector-icons/FontAwesome'; // Import the icon library
import { Svg, Path } from 'react-native-svg'; // Import SVG components
import axios from 'axios';
import { useDataContext } from './Context';
import { db } from './Firebase';
import { collection, addDoc, where, query, getDocs, Firestore } from "firebase/firestore";
import { X_GROUP_AUTH } from '@env';


class WavyBackground extends Component {
  render() {
    return (
      <Svg viewBox= "0 0 500 200" style={{ position: 'absolute', top: 0, left: 0 , flex: 1, width: '100%', height: '150', zIndex: -1}}>
          <Path d="M 0 50 C 150 150 300 0 500 80 L 500 0 L 0 0" fill="rgb(57, 27, 112)"></Path>
          <Path d="M 0 50 C 150 150 330 -30 500 50 L 500 0 L 0 0" fill="#0E7452" opacity="0.8"></Path>
          <Path d="M 0 50 C 215 150 250 0 500 100 L 500 0 L 0 0" fill="#0E7452" opacity="0.5"></Path>
      </Svg>
    );
  }
}

export default App = (props) => {
  const XGroupAuth = X_GROUP_AUTH;
  const { setSharedData } = useDataContext();
  const Users = collection(db, 'users');
  //const [token, setToken] = useContext(Context);

  const [credentials, setCredentials] = useState({
    email: '',
    password: '',
  });

  const onLogin = () => {
    const headers = {
      'accept': 'application/json',
      'X-Group-Authorization': XGroupAuth,
      'Content-Type': 'application/json',
      'Access-Control-Allow-Origin': '*',
    };

    console.log("Test: " + credentials.email + " " + credentials.password);
    try {
      axios.post('https://masurao.fr/api/employees/login', credentials, { headers })
        .then((response) => {
          //console.log(response.data);
          //console.log("Test1: " + response.data.access_token);
          setSharedData(response.data.access_token);
          //console.log("Login success " + response.data.access_token);
          props.navigation.navigate('Main', { username: credentials.email, password: credentials.password });
        }).catch((error) => {
          Alert.alert('Invalid credentials', 'Please check your username and password.');
          console.log('Err: ', error.response.data);
        }
        );
      props.navigation.navigate('Main', { username: credentials.email, password: credentials.password });
    } catch (error) {
      console.error('Error:', error);
    };

  };

  return (
    <View style={styles.container}>
      {/* Wavy Background */}
      <WavyBackground />

      {/* Rest of your content */}
      <View style={styles.content}>
        <Text style={{ fontSize: 30, fontWeight: 'bold', marginBottom: 30, alignItems: 'center' }}>Login</Text>

        {/* Username input */}
        <View style={styles.inputContainer}>
          <Icon name="user" size={24} color="#000" style={styles.icon} />
          <TextInput
            value={credentials.email}
            onChangeText={(text) => setCredentials({ ...credentials, email: text })}
            placeholder={'Email'}
            style={styles.input}
          />
        </View>

        {/* Password input */}
        <View style={styles.inputContainer}>
          <Icon name="lock" size={24} color="#000" style={styles.icon} />
          <TextInput
            value={credentials.password}
            onChangeText={(text) => setCredentials({ ...credentials, password: text })}
            placeholder={'Password'}
            secureTextEntry={true}
            style={styles.input}
          />
        </View>

        <TouchableOpacity style={styles.loginButton} onPress={onLogin.bind()}>
          <Text style={{ color: '#fff' }}>Login</Text>
        </TouchableOpacity>
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1, // Take up the whole screen
    alignItems: 'center',
    justifyContent: 'center',
    backgroundColor: 'transparent',

  },

  inputContainer: {
    flexDirection: 'row',
    alignItems: 'center',
  },

  input: {
  "width": 250,
  "height": 44,
  "padding": 10,
  "borderWidth": 1,
  "borderStyle": "solid", // Use "solid" for the border style
  "borderColor": "rgba(0, 0, 0, 0.2)", // Set border color separately
  "backgroundColor": "#fff",
  "marginBottom": 20,
  "borderRadius": 26,
  "fontWeight": "light"
},

  icon: {
    marginRight: 10, // Spacing between icon and input field
    marginBottom: 20,
  },

  loginButton: {
    width: 300,
    height: 44,
    marginBottom: 20, // Add space above the button
    borderRadius: 26,
    "padding": 10,
    "borderWidth": 1,
    "borderStyle": "solid", // Use "solid" for the border style
    backgroundColor: '#841584', // Background color of the button
    alignItems: 'center',
    "fontWeight": "light",
  },
});
