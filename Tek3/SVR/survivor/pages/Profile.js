import React, { useEffect, useState } from 'react';
import { View, Text, StyleSheet, Button, ActivityIndicator, Image } from 'react-native';
import axios from 'axios';
import { Buffer } from 'buffer';
import { useDataContext } from '../Context';
import Header from '../components/Header';
import { X_GROUP_AUTH } from '@env';

function ProfilePage({ navigation }) {
  const { data } = useDataContext();
  //console.log(data);
  const [profileData, setProfileData] = useState(null);
  const [imageData, setImageData] = useState(null);
  const [isLoading, setIsLoading] = useState(true);
  //const route = useRoute();
  //const { access_token } = route.params;
  const XGroupAuth = X_GROUP_AUTH;

  useEffect(() => {
    getInfoMe();
    getImages();
  }, []);

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
      setProfileData(response.data);
      setIsLoading(false);
      console.log('GetInfoMe success');
      console.log(response.data);

      // Call getImages after setting profileData
      //getImages();
    } catch (error) {
      console.error('Error:', error);
    }
  };

  const getImages = async () => {
    if (!data || !profileData) { // Check if profileData is null
      throw new Error('Token or profile data is null');
    }

    const headers = {
      'accept': 'image/png',
      'X-Group-Authorization': XGroupAuth,
      'Authorization': `Bearer ${data}`,
    };

    try {
      //console.log("profileData.id: " + profileData.id);

      const id = profileData.id;
      const response = await axios.get('https://masurao.fr/api/employees/' + id + '/image', {
        headers,
        responseType: 'arraybuffer',
      });

      const base64ImageData = Buffer.from(response.data, 'binary').toString('base64');
      setImageData(base64ImageData);
      console.log("GetImages success");
    } catch (error) {
      console.error('Error of Img:', error);
    }
  };
  return (
      <View style={styles.wrapper}>
        <View style={styles.header}>
          <Header navigation={navigation} />
        </View>
        <View style={styles.container}>
          {isLoading ? (
              <ActivityIndicator size="large" color="#007bff" />
          ) : profileData ? (
              <View style={styles.profileContainer}>
                <Image
                    source={{ uri: `data:image/png;base64,${imageData}` }}
                    style={styles.profileImage}
                />
                <View style={{backgroundColor: '#462964', width: '100%', alignItems: 'center', borderTopLeftRadius: 20, borderTopRightRadius: 20}}>
                  <Text style={styles.value}>{profileData.name}</Text>
                  <Text style={styles.value}>{profileData.surname}</Text>
                  <Text style={styles.value}>{profileData.email}</Text>
                  <Text style={styles.value}>{profileData.birth_date}</Text>
                  <Text style={styles.value}>{profileData.gender}</Text>
                  <Text style={styles.value}>{profileData.work}</Text>
                </View>
              </View>
          ) : (
              <Text>Error loading profile data.</Text>
          )}
        </View>
      </View>
  );
}

const styles = StyleSheet.create({
  wrapper: {
    flex: 1,
  },
  container: {
    flex: 1,
    backgroundColor: '#0D1821',
    alignItems: 'center',
    height: '100%',
    justifyContent: 'flex-end',

  },
  profileContainer: {
    backgroundColor: '#0D1821',
    width: '100%',
    alignItems: 'center',
  },
  profileImage: {
    width: 150,
    height: 150,
    borderRadius: 75,
    marginBottom: 60,
  },
  header: {
    height: 75,
  },
  label: {
    fontSize: 18,
    fontWeight: 'bold',
    marginTop: 10,
    color: '#F2FDFF',
  },
  value: {
    color: '#F2FDFF',
    fontSize: 16,
    marginBottom: 20,
    marginTop: 20,
  },
});

export default ProfilePage;
