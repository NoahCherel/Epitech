import React, { useEffect, useState } from 'react';
import { View, Text, StyleSheet, FlatList, ActivityIndicator, TouchableOpacity, Image, TextInput, Linking } from 'react-native';
import axios from 'axios';
import Header from '../components/Header';
import { WebView } from 'react-native-webview';
import { API_KEY_NEWS } from '@env';

function NewsPage({ navigation }) {
  const [newsData, setNewsData] = useState([]);
  const [selectedNews, setSelectedNews] = useState(null);
  const [isLoading, setIsLoading] = useState(true);
  const [searchText, setSearchText] = useState('France');
  const [showWebView, setShowWebView] = useState(false); // Add state to control WebView visibility
  const [webViewUrl, setWebViewUrl] = useState(''); // Store the URL for the WebView
  const apiKey = API_KEY_NEWS;

  useEffect(() => {
    fetchNews();
  }, []);

  const fetchNews = async () => {
    try {
      const response = await axios.get(`https://newsapi.org/v2/everything?q=${searchText}&apiKey=${apiKey}`);
      setNewsData(response.data.articles);
      setIsLoading(false);
    } catch (error) {
      console.error('Error fetching news:', error);
    }
  };

  const navigateToNewsDetails = (item) => {
    setSelectedNews(item);
  };

  const handleSearch = () => {
    fetchNews();
  };

  const openSourceLink = (url) => {
    setWebViewUrl(url);
    setShowWebView(true);
  };

  const closeWebView = () => {
    setShowWebView(false);
    setWebViewUrl('');
  };

  return (
      <View style={styles.container}>
        <View style={styles.headerContainer}>
          <Header navigation={navigation} />
        </View>
        <TextInput
            style={styles.searchInput}
            placeholder="Search news"
            value={searchText}
            onChangeText={(text) => setSearchText(text)}
            onSubmitEditing={handleSearch}
        />
        {isLoading ? (
            <ActivityIndicator size="large" color="#007bff" />
        ) : selectedNews ? (
            <View style={styles.newsDetailsContainer}>
              <Image source={{ uri: selectedNews.urlToImage }} style={styles.selectedNewsImage} />
              <Text style={styles.selectedNewsTitle}>{selectedNews.title}</Text>
              <Text style={styles.selectedNewsAuthor}>Author: {selectedNews.author}</Text>
              <TouchableOpacity
                  style={styles.sourceLinkButton}
                  onPress={() => openSourceLink(selectedNews.url)}
              >
                <Text style={styles.sourceLinkText}>Open Source</Text>
              </TouchableOpacity>
              <Text style={styles.selectedNewsDescription}>{selectedNews.description}</Text>
              <Text style={styles.selectedNewsPublishedAt}>Published At: {selectedNews.publishedAt}</Text>
              <TouchableOpacity
                  style={styles.backButton}
                  onPress={() => setSelectedNews(null)}
              >
                <Text style={styles.backButtonText}>Go Back</Text>
              </TouchableOpacity>
            </View>
        ) : (
            <FlatList
                data={newsData}
                keyExtractor={(item, index) => index.toString()}
                renderItem={({ item }) => (
                    <TouchableOpacity style={styles.newsItem} onPress={() => navigateToNewsDetails(item)}>
                      <Text style={styles.newsTitle}>{item.title}</Text>
                      <Image source={{ uri: item.urlToImage }} style={styles.newsImage} />
                      <Text style={styles.newsDescription}>{item.description}</Text>
                    </TouchableOpacity>
                )}
            />
        )}

        {/* WebView */}
        {showWebView && (
            <View style={styles.webViewContainer}>
              <WebView source={{ uri: webViewUrl }} />
              <TouchableOpacity
                  style={styles.closeWebViewButton}
                  onPress={closeWebView}
              >
                <Text style={styles.closeWebViewText}>Close WebView</Text>
              </TouchableOpacity>
            </View>
        )}
      </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#0D1821',
  },

  headerContainer: {
    height: '10%',
  },

  searchInput: {
    backgroundColor: 'white',
    borderRadius: 8,
    paddingHorizontal: 10,
    margin: 10,
    fontSize: 16,
  },

  newsItem: {
    backgroundColor: '#462964',
    padding: 10,
    borderRadius: 20,
    elevation: 3,
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.3,
    shadowRadius: 2,
    margin: 10,
  },

  newsTitle: {
    fontSize: 18,
    fontWeight: 'bold',
    marginBottom: 5,
    color: '#F2FDFF',
  },

  newsImage: {
    width: '100%',
    height: 200,
    borderRadius: 8,
    marginBottom: 5,
  },

  newsDescription: {
    fontSize: 16,
    color: '#F2FDFF',
  },

  newsDetailsContainer: {
    padding: 10,
    backgroundColor: '#462964',
    justifyContent: 'flex-end'
  },

  selectedNewsImage: {
    width: '100%',
    height: 200,
    borderRadius: 8,
    marginBottom: 10,
  },

  selectedNewsTitle: {
    fontSize: 24,
    fontWeight: 'bold',
    marginBottom: 10,
    color: '#F2FDFF',
  },

  selectedNewsAuthor: {
    fontSize: 18,
    marginBottom: 5,
    color: '#F2FDFF',
  },

  sourceLinkButton: {
    backgroundColor: '#9C54D5',
    padding: 10,
    borderRadius: 8,
    alignItems: 'center',
    marginTop: 10,
  },

  sourceLinkText: {
    fontSize: 16,
    color: '#F2FDFF',
  },

  selectedNewsDescription: {
    marginTop: 20,
    fontSize: 18,
    marginBottom: 10,
    color: '#F2FDFF',
    textAlign: 'center',
  },

  selectedNewsPublishedAt: {
    fontSize: 10,
    marginTop: 20,
    marginBottom: 5,
    color: '#F2FDFF',
  },

  backButton: {
    backgroundColor: '#9C54D5',
    padding: 10,
    borderRadius: 8,
    alignItems: 'center',
    marginTop: 5,
  },

  backButtonText: {
    fontSize: 16,
    color: 'white',
  },

  webViewContainer: {
    flex: 1,
    position: 'absolute',
    top: 0,
    left: 0,
    right: 0,
    bottom: 0,
    zIndex: 1, // Ensure the WebView is rendered on top of other elements
  },

  closeWebViewButton: {
    backgroundColor: '#007bff',
    padding: 10,
    borderRadius: 8,
    alignItems: 'center',
    position: 'absolute',
    bottom: 0,
    left: 0,
    right: 0,
  },

  closeWebViewText: {
    fontSize: 16,
    color: 'white',
  },
});

export default NewsPage;
