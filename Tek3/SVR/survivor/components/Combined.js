import React, { useEffect, useState } from 'react';
import {View, Text, Image, StyleSheet, FlatList, TextInput, TouchableOpacity, Pressable} from 'react-native';
// modal
import axios from 'axios';
import {useRoute, useNavigation} from '@react-navigation/native';
import { Buffer } from 'buffer';

import Header from './Header';
import Icon from "react-native-vector-icons/FontAwesome";
import { Modal, Portal, Button, PaperProvider } from 'react-native-paper';
import { useDataContext } from "../Context";
import { X_GROUP_AUTH } from "@env";

const CombinedPage = ({ route, navigation }) => {
  const [employeesData, setEmployeesData] = useState([]);
  const [employeeImages, setEmployeeImages] = useState({});
  const [searchQuery, setSearchQuery] = useState('');
  const [selectedEmployee, setSelectedEmployee] = useState(null);
  const [employeeProfile, setEmployeeProfile] = useState(null);
  const data = useDataContext();
  const access_token = data.data;

  useEffect(() => {
    getEmployees();
  }, []);

  useEffect(() => {
    if (employeesData.length > 0) {
      getEmployeeImages();
    }
  }, [employeesData]);

  const getEmployees = async () => {
    if (!access_token) {
      throw new Error('Token is null');
    }

    const headers = {
      'accept': 'application/json',
      'X-Group-Authorization': X_GROUP_AUTH,
      'Authorization': `Bearer ${access_token}`,
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
    if (!access_token) {
      throw new Error('Token is null');
    }

    const headers = {
      'accept': 'image/png',
      'X-Group-Authorization': X_GROUP_AUTH,
      'Authorization': `Bearer ${access_token}`,
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
    if (!access_token) {
      throw new Error('Token is null');
    }

    const headers = {
      'accept': 'application/json',
      'X-Group-Authorization': X_GROUP_AUTH,
      'Authorization': `Bearer ${access_token}`,
    };

    try {
      return await axios.get(`https://masurao.fr/api/employees/${employeeId}`, { headers });
      // setEmployeeProfile(response.data);
      // return(employeeProfile);
    } catch (error) {
      console.error('Error fetching employee profile:', error);
    }
  };

  const handleEmployeePress = (employee) => {
    setSelectedEmployee(employee);
    // Fetch the employee profile data when an employee is selected
    return fetchEmployeeProfile(employee.id);
  };

  const closeModal = () => {
    setSelectedEmployee(null);
    // Clear the employee profile data when closing the modal
    setEmployeeProfile(null);
  };

  const filteredEmployees = employeesData.filter((employee) => {
    const fullName = `${employee.name} ${employee.surname}`;
    return fullName.toLowerCase().includes(searchQuery.toLowerCase());
  });

  const searchBar = () => {
    return (
        <View style={styles.searchBar}>
          <Icon name="search" style={styles.icon} />
          <TextInput
              style={styles.searchBar}
              placeholder="Rechercher"
              placeholderTextColor="#462964"
              marginLeft={30}
              value={searchQuery}
              onChangeText={(text) => setSearchQuery(text)}
          />
        </View>
    )
  }

  const flatList = () => {
    return (
        <FlatList
            data={filteredEmployees}
            keyExtractor={(item) => item.id.toString()}
            renderItem={({ item }) => (
                <View>
                  <TouchableOpacity style={styles.employeeItem} onPress={() => navigation.navigate('TeamProfile', { data: data, employee: item, navigation: navigation })}>
                    <Image
                        source={{ uri: `data:image/png;base64,${employeeImages[item.id]}` }}
                        style={styles.image}
                    />
                    <View style={styles.employeeInfo}>
                      <Text style={styles.employeeName}>{item.name} {item.surname}</Text>
                      <Text style={styles.employeeEmail}>{item.email}</Text>
                    </View>
                  </TouchableOpacity>
                </View>

            )}
        />
    )
  }

  const employeeNavigation = ( item ) => {
    console.log(item);
    navigation.navigate('TeamProfile', {data, item, navigation});
  }

  return (
      <View style={styles.container}>
        <View style={styles.header}>
          <Header navigation={navigation} />
        </View>
        {searchBar()}
        <View style={styles.containerTrombi}>
          {flatList()}
        </View>
      </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#0D1821',
  },
  containerTrombi: {
    flex: 1,
  },
  header: {
    height: 70,
    marginBottom: 20,
  },
  searchBar: {
    color : '#462964',
    height: 48,
    borderWidth: 0,
    borderColor: '#F2FDFF',
    borderRadius: 20,
    paddingHorizontal: 10,
    marginBottom: 15,
    fontSize: 18,
    backgroundColor: '#F2FDFF',
    fontWeight: 'bold',
  },
  employeeItem: {
    backgroundColor: '#462964',
    borderRadius: 20,
    padding: 16,
    marginBottom: 16,
    flexDirection: 'row',
    borderColor: '#8D89A6',
    borderWidth: 1,
    alignItems: 'center',
    shadowColor: '#000',
    shadowOffset: {
      width: 0,
      height: 2,
    },
    shadowOpacity: 0.2,
    shadowRadius: 2,
    elevation: 2,
  },
  image: {
    width: 80,
    height: 80,
    borderRadius: 40,
    marginRight: 16,
  },
  employeeInfo: {
    flex: 1,
  },
  employeeName: {
    fontSize: 18,
    fontWeight: 'bold',
    color: '#F2FDFF',
  },
  employeeEmail: {
    fontSize: 16,
    color: '#F2FDFF',
  },
  employeeID: {
    fontSize: 14,
    color: '#F2FDFF',
  },
  modalContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: 'rgba(0, 0, 0, 0.5)',
  },
  modalContent: {
    backgroundColor: 'white',
    padding: 20,
    borderRadius: 8,
    width: '80%',
  },
  modalTitle: {
    fontSize: 20,
    fontWeight: 'bold',
    marginBottom: 10,
  },
  closeButton: {
    position: 'absolute',
    marginTop: 20,
    top: 20,
    right: 20,
    backgroundColor: 'white',
    padding: 10,
    borderRadius: 8,
  },
  closeButtonText: {
    fontSize: 18,
    color: '#333',
  },
  icon: {
    zIndex: 1,
    fontSize: 25,
    top: 10,
    position: 'absolute',
    left: 15,
  }
});

export default CombinedPage;
