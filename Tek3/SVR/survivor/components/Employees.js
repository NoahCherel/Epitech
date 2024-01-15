import React, { useEffect, useState } from 'react';
import { View, Text, StyleSheet, FlatList } from 'react-native';
import axios from 'axios';
import { useRoute } from '@react-navigation/native';
import { X_GROUP_AUTH } from '@env';

const EmployeesPage = () => {
  const [employeesData, setEmployeesData] = useState([]);
  const route = useRoute();
  const { access_token } = route.params;
  const XGroupAuth = X_GROUP_AUTH;

  useEffect(() => {
    getEmployees();
  }, []);

  const getEmployees = async () => {
    if (!access_token) {
      throw new Error('Token is null');
    }

    const headers = {
      'accept': 'application/json',
      'X-Group-Authorization': XGroupAuth,
      'Authorization': 'Bearer ' + access_token,
    };

    try {
      const response = await axios.get('https://masurao.fr/api/employees', { headers });
      setEmployeesData(response.data);
      console.log("GetEmployees success");
    } catch (error) {
      console.error('Error:', error);
    }
  };

  return (
    <View style={styles.container}>
      <Text style={styles.header}>Employee List</Text>
      <FlatList
        data={employeesData}
        keyExtractor={(item) => item.id.toString()}
        renderItem={({ item }) => (
          <View style={styles.employeeItem}>
            <Text>Employee ID: {item.id}</Text>
            <Text>Email: {item.email}</Text>
            <Text>Name: {item.name}</Text>
            <Text>Surname: {item.surname}</Text>
          </View>
        )}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  header: {
    fontSize: 20,
    fontWeight: 'bold',
    marginBottom: 10,
  },
  employeeItem: {
    borderBottomWidth: 1,
    borderColor: '#ccc',
    paddingVertical: 10,
    paddingHorizontal: 20,
  },
});

export default EmployeesPage;
