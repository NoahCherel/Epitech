import React, { useEffect, useState } from 'react';
import { View, Image, StyleSheet } from 'react-native';
import axios from 'axios';
import { useRoute } from '@react-navigation/native';
import { Buffer } from 'buffer';
import { X_GROUP_AUTH } from '@env';

const Images = () => {
  const [imageData, setImageData] = useState(null);
  const route = useRoute();
  const { access_token } = route.params;
  const XGroupAuth = X_GROUP_AUTH;

  useEffect(() => {
    getImages();
  }, []);

  const getImages = async () => {
    if (!access_token) {
      throw new Error('Token is null');
    }

    const headers = {
      'accept': 'image/png',
      'X-Group-Authorization': XGroupAuth,
      'Authorization': `Bearer ${access_token}`,
    };

    try {
      const response = await axios.get('https://masurao.fr/api/employees/1/image', {
        headers,
        responseType: 'arraybuffer', // Specify the response type as 'arraybuffer'
      });

      // Convert binary data to Base64
      const base64ImageData = Buffer.from(response.data, 'binary').toString('base64');

      setImageData(base64ImageData);
      console.log("GetImages success");
    } catch (error) {
      console.error('Error:', error);
    }
  };

  return (
    <View style={styles.container}>
      {imageData && (
        <Image
          source={{ uri: `data:image/png;base64,${imageData}` }}
          style={styles.image}
        />
      )}
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  image: {
    width: 200, // Set the width as needed
    height: 200, // Set the height as needed
  },
});

export default Images;