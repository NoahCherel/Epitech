import React, { useState } from 'react';
import { View, StyleSheet, Text, TextInput } from 'react-native';
import { Calendar } from 'react-native-calendars';
import Header from '../components/Header';
import { Button } from 'react-native-paper';
const CalendarScreen = ({ navigation }) => {
  const [selectedDate, setSelectedDate] = useState(null);
  const [tasks, setTasks] = useState({});
  const [newTask, setNewTask] = useState('');
  const [eventDates, setEventDates] = useState(['2023-03-16', '2023-03-18']);
  const mount = {
    '01': 'January',
    '02': 'February',
    '03': 'March',
    '04': 'April',
    '05': 'May',
    '06': 'June',
    '07': 'July',
    '08': 'August',
    '09': 'September',
    '10': 'October',
    '11': 'November',
    '12': 'December',
  }

  // Function to handle adding a task to the selected date
  const addTask = () => {
    if (selectedDate && newTask) {
      setTasks({
        ...tasks,
        [selectedDate]: [...(tasks[selectedDate] || []), newTask],
      });
      setNewTask('');
    }
  };

  // Function to generate marked dates with custom styles
  const generateMarkedDates = () => {
    const marked = {};
    eventDates.forEach((date) => {
      marked[date] = { marked: true, dotColor: 'blue' };
    });
    return marked;
  };

  const parseDate = (date) => {
    const year = date.substring(0, 4);
    const month = date.substring(5, 7);
    const day = date.substring(8, 10);
    return `${day} ${mount[month]} ${year}`;
  }

  return (
      <View style={styles.container}>
        {/* Header component */}
        <View style={styles.headerContainer}>
          <Header navigation={navigation} />
        </View>

        <View style={styles.calendarContainer}>
          <Calendar
              markedDates={{
                ...generateMarkedDates(), // Add custom styles to days with events
                [selectedDate]: { selected: true, marked: true, selectedColor: '#462964' },
              }}
              onDayPress={(day) => setSelectedDate(day.dateString)}
              theme={{
                backgroundColor: '#0D1821',
                calendarBackground: '#0D1821',
                selectedDayTextColor: '#F2FDFF',
                selectedDayBackgroundColor: '#462964',
                todayTextColor: '#462964',
                dayTextColor: '#F2FDFF',
              }}
          />
        </View>

        <View style={styles.bottomContainer}>
          {selectedDate && (
              <View style={{alignItems: 'center'
              }}>
                <Text style={styles.selectedDateText}> {parseDate(selectedDate)}</Text>
                <View style={{flexDirection: 'row', justifyContent: 'center', alignItems: 'center', marginTop: 10}}>
                  <TextInput
                      style={styles.taskInput}
                      placeholder="Enter a task"
                      value={newTask}
                      onChangeText={(text) => setNewTask(text)}
                      placeholderTextColor={'#F2FDFF'}
                  />
                  <Button label="Add" onPress={addTask} style={styles.button} >
                    <Text style={{color: '#F2FDFF'}}> + </Text>
                  </Button>
                </View>
              </View>
          )}

          {tasks[selectedDate] && (
              <View style={{marginTop: 20}}>
                {tasks[selectedDate].map((task, index) => (
                    <Text key={index} style={styles.taskItem}>
                      {task}
                    </Text>
                ))}
              </View>
          )}
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
  calendarContainer: {
    flex: 1, // Make the calendar container expand to fill available space
    justifyContent: 'flex-end', // Center vertically
    backgroundColor: '#0D1821'
  },
  bottomContainer: {
    flex: 1, // Make the bottom container expand to fill available space
    justifyContent: 'flex-start', // Align items at the top
    alignItems: 'center', // Center horizontally
    textAlign: 'center',
  },
  selectedDateText: {
    fontSize: 18,
    fontWeight: 'bold',
    marginTop: 16,
    color: '#F2FDFF',
  },
  taskInput: {
    borderWidth: 1,
    borderColor: 'gray',
    padding: 8,
    borderRadius: 20,
    color: '#F2FDFF',
    textAlign: 'center',
    width: 200,
  },
  tasksText: {
    fontSize: 16,
    fontWeight: 'bold',
    marginTop: 16,
    color: '#F2FDFF',
  },
  taskItem: {
    fontSize: 14,
    marginTop: 8,
    color: '#F2FDFF',
  },
  button: {
    backgroundColor: '#462964',
    marginLeft: 10,
    borderRadius: 20,
    height: 40,
    borderColor: '#8D89A6',
    borderWidth: 1,
  }
});

export default CalendarScreen;
