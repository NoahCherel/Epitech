import React, { createContext, useContext, useState } from 'react';

export const DataContext = createContext();

export const useDataContext = () => {
  const context = useContext(DataContext);
  if (!context) {
    throw new Error('useDataContext must be used within a DataContextProvider');
  }
  return context;
};

export const DataContextProvider = ({ children }) => {
  const [data, setData] = useState(null);

  const setSharedData = (newData) => {
    setData(newData);
  };

  return (
    <DataContext.Provider value={{ data, setSharedData }}>
      {children}
    </DataContext.Provider>
  );
};
