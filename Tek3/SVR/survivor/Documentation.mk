BizFaces
Langage: React Native
API: Masurao, Blagues-api.fr, newsapi.org
Packages:
		"@expo/ngrok": "^4.1.0",
        "@expo/webpack-config": "^19.0.0",
        "@react-native-firebase/app": "^18.4.0",
        "@react-native-firebase/messaging": "^18.4.0",
        "@react-navigation/drawer": "^6.6.3",
        "@react-navigation/native": "^6.1.7",
        "@react-navigation/stack": "^6.3.17",
        "axios": "^1.5.0",
        "blagues-api": "^2.1.1",
        "expo": "~49.0.8",
        "expo-device": "^5.6.0",
        "expo-location": "~16.1.0",
        "expo-notifications": "~0.20.1",
        "expo-status-bar": "~1.6.0",
        "firebase": "^10.3.1",
        "react": "18.2.0",
        "react-dom": "18.2.0",
        "react-native": "0.72.4",
        "react-native-calendars": "^1.1301.0",
        "react-native-dotenv": "^3.4.9",
        "react-native-gesture-handler": "~2.12.0",
        "react-native-reanimated": "~3.3.0",
        "react-native-svg": "13.9.0",
        "react-native-vector-icons": "^10.0.0",
        "react-native-web": "^0.19.8",
        "react-native-webview": "13.2.2"

Dépendances:	@babel/core-7.20.0
        		@expo/ngrok-4.1.0

App.js: Entrypoint de l'application
Context.js: Sauvegarde du token utilisateur
DrawerNavigator.js: Contient le DrawerNavigation (Menu latéral)
DrawerTrigger.js: Component permettant d'ouvrir le DrawerNavigation
StackNavigator.js: Gestion de la navigation
DateTime.js: Affiche la date et l'heure, non utilisé
Header.js: Component Header de l'application, à utiliser dans les pages pour faire apparaitre le header
	Les nouvelles pages ajoutées au DrawerNavigation sont automatiquement ajoutées au Header
	Le Header contient un DrawerTrigger et un bouton de déconnexion
Login.js: Première page de l'application, permet de se connecter, donne ensuite sur MainScreen.js
MainScreen.js: Page principale
Profile.js: Page de profil de l'utilisateur connecté
Combined.js: Page avec tous les employés et qui affiche des informations sur eux
Employees.js: Gestion des employés, non utilisé
Images.js: Gestion des images, non utilisé
WeatherScreen.js: Page de météo, utilise la géolocalisation pour afficher la météo de l'utilisateur
WeatherInfo.js: Gestion de la météo
CalendarScreen.js: Page de calendrier
Jokes.js: Component utilisant l'api de Blagues-api.fr pour afficher des blagues
NewsPage.js: Page de news, utilise l'api de newsapi.org pour afficher des news,
			aucune recherche par défaut donc vérifier de bien chercher des news pour avoir des résultats.
			Clicker sur une news ouvre un webview avec la news
InitFCM.js: Initialisation de Firebase Cloud Messaging, permet de recevoir des notifications
Notes.js: Gestion des notes, en cours de développement
Chat.js: Gestion du chat, en cours de développement


Méthode pour ajouter un Widget:
- Créer un fichier .js dans le dossier Widgets
- Ajouter le widget dans le DrawerNavigator
- C'est tout, le widget est maintenant accessible depuis le DrawerNavigation

A savoir:
Un .env avec les variables d'environnement est nécessaire pour faire fonctionner l'application
en l'occurrence
API_KEY_METEO= Insertion de la clé API de https://openweathermap.org/
X_GROUP_AUTH= API Key de Masurao
API_KEY_FIREBASE= Insertion de la clé API de Firebase
AUTHDOMAIN= Insertion de l'authdomain de Firebase
PROJECT_ID= Insertion du project ID de Firebase
STORAGE_BUCKET= Insertion du storage bucket de Firebase
MESSAGING_SENDER_ID= Insertion du messaging sender ID de Firebase
APPID= Insertion de l'app ID de Firebase
PROJECT_ID_EXPO= Insertion du project ID de EXPO
API_KEY_JOKES=  Insertion de la clé API de https://www.blagues-api.fr/