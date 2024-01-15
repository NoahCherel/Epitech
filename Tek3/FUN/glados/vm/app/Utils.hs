--
-- EPITECH PROJECT, 2023
-- vm
-- File description:
-- Utils
--

module Utils (
    withFileHandling,
    writeResultToFile
) where

import DataSet
import Control.Exception

-- | Reads the contents of a file and returns it as a 'String' wrapped in an 'Either' type.
-- If the file is empty, returns a 'Left' with an error message.
-- If an error occurs while reading the file, returns a 'Left' with an error message.
-- Otherwise, returns a 'Right' with the contents of the file.
withFileHandling :: FilePath -> IO (Either String String)
withFileHandling filename = handle errorHandler $ do
    contents <- readFile filename
    if null contents
        then return (Left $ "File " ++ filename ++ " is empty.")
        else return (Right contents)
  where
    errorHandler :: IOError -> IO (Either String String)
    errorHandler e = return (Left $ "An error occurred: " ++ show e)


-- | Writes the result of a computation to a file.
-- The result is converted to a 'String' using 'show' before being written to the file.
-- Prints a message to the console indicating where the result was saved.
writeResultToFile :: String -> NewLangVal -> IO ()
writeResultToFile filename result = do
    writeFile filename (show result)
    putStrLn $ "Result saved to " ++ filename
