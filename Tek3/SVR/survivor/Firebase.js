// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getFirestore, collection, getDocs } from 'firebase/firestore';
import { API_KEY_FIREBASE, AUTHDOMAIN, PROJECT_ID, STORAGE_BUCKET, MESSAGING_SENDER_ID, APPID } from '@env';
import 'firebase/firestore';
import 'firebase/auth';
import { getAuth } from "firebase/auth";

// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: API_KEY_FIREBASE,
  authDomain: AUTHDOMAIN,
  projectId: PROJECT_ID,
  storageBucket: STORAGE_BUCKET,
  messagingSenderId: MESSAGING_SENDER_ID,
  appId: APPID
};

// Initialize Firebase

const firebase = initializeApp(firebaseConfig);

const db = getFirestore(firebase);
const auth = getAuth(firebase);

export { db, auth };