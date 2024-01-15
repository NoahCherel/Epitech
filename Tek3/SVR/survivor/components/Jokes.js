import React, { useState, useEffect } from 'react';
import {View, Text, StyleSheet, TouchableOpacity} from 'react-native';
import axios from 'axios';
import { API_KEY_JOKES } from '@env';
import Blagues from 'blagues-api';
import { Card, Button } from 'react-native-paper';

const JokeScreen = () => {
  const [joke, setJoke] = useState('');
  const [answer, setAnswer] = useState('');
  const [showAnswer, setShowAnswer] = useState(joke);

  const fetchJoke = async () => {
    const blague = new Blagues(API_KEY_JOKES);
    const randomJoke = await blague.randomCategorized(
        blague.categories.DEV,
    );
    //const randomJoke = await blague.random();
    //console.log(randomJoke);
    setJoke(randomJoke.joke);
    setShowAnswer(randomJoke.joke);
    setAnswer(randomJoke.answer);
  };

  useEffect(() => {
    fetchJoke();
  }, []);

  const switchAnswer = () => {
    if (showAnswer === answer)
      fetchJoke();
    else
      setShowAnswer(answer);
  }

  const getStyle = () => {
    if (showAnswer === answer)
      return styles.answer;
    else
      return styles.joke;
  }

  return (
      <TouchableOpacity onPress={switchAnswer} style={styles.container}>
        <Card style={styles.card}>
          <Text style={getStyle()}>{showAnswer}</Text>
        </Card>
      </TouchableOpacity>
  );
};

export default JokeScreen;

const styles = StyleSheet.create({
  container: {
    width: '80%',
  },

  card: {
    backgroundColor: '#462964',
    borderRadius: 20,
    padding: 10,
    borderColor: '#8D89A6',
    borderWidth: 1,
  },
  joke: {
    fontSize: 13,
    color: '#F2FDFF',
    textAlign: 'center',
    fontWeight: 'bold',
  },
  answer: {
    fontSize: 13,
    fontStyle: 'italic',
    color: '#F2FDFF',
    textAlign: 'center',
  },
  button: {
    width: 80,
    height: 40,
    backgroundColor: '#462964',
    alignItems : 'center',
    borderRadius: 20,
  },
  buttonText: {
    fontSize: 12,
    color: '#F2FDFF',
  }
});
