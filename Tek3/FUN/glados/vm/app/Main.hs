--
-- EPITECH PROJECT, 2023
-- Untitled (Workspace)
-- File description:
-- Main
--

module Main (main) where

import System.Environment
import DataSet
import VirtualMachine
import Utils
import Parser

-- MAIN --
-- | The main function of the program. It takes a filename as an argument and executes the code in the file.
-- If the execution is successful, it writes the result to a file with the same name as the input file and the extension ".res".
-- If there is an error during the execution or the filename argument is not provided, it prints an error message.
main :: IO ()
main = do
    args <- getArgs
    case args of
        [filename] -> do
            result <- withFileHandling filename
            case result of
                Left errorValue -> putStrLn errorValue
                Right content -> do
                    case executeCode (splitLines content) of
                        Left errorValue -> putStrLn errorValue
                        Right _result -> writeResultToFile (filename ++ ".res") _result
        _ -> putStrLn "Usage: ./glados_vm [filename]."

-- | Given a list of strings and an environment, this function parses each string to check if it is a valid function definition. If it is, it adds the function to the environment with its corresponding bytecode. The resulting environment is returned.
-- setupEnvironment :: [String] -- ^ List of strings to parse and add to the environment
--                  -> Environment -- ^ Current environment
--                  -> Environment -- ^ Updated environment with added functions and their bytecodes

setupEnvironment :: [String] -> Environment -> Environment
setupEnvironment [] environment = environment
setupEnvironment (x:xs) environment = case parseFunctionDefinition x of
    Right (name, nb) -> setupEnvironment xs (environment ++ [(name, (nb, bytecodesAssembler xs []))])
    Left _ -> setupEnvironment xs environment

-- | Executes the given code and returns the result as an 'Either' value.
-- If the code is valid, it returns the result wrapped in a 'Right' value.
-- If the code is invalid, it returns an error message wrapped in a 'Left' value.
executeCode :: [String] -> Either String NewLangVal
executeCode code = case checkMain code of
    Right _main -> interpretBytecodes [] (setupEnvironment code []) [] (bytecodesAssembler _main []) []
    Left errorValue -> error errorValue
