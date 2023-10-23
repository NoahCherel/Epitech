{-
-- EPITECH PROJECT, 2023
-- Untitled (Workspace)
-- File description:
-- Main
-}

import System.Environment
import Text.Read
import System.Exit

import RuleSet
import Args
import Display

exitError :: Int -> String -> IO ()
exitError code message =
    putStrLn message >>
    exitWith (ExitFailure code)

createNewLine :: String -> String -> Int -> String
createNewLine lastLine res rule =
    let tmp = take 3 lastLine
    in if length tmp == 3
        then createNewLine (tail lastLine) (applyRule rule tmp : res) rule
        else res

runGen :: [Int] -> Int -> [Char] -> Int -> IO ()
runGen s 0 _ _ = return ()
runGen s count lastL gen | gen > 0 =
    let newLine = createNewLine (' ':' ':lastL ++ "  ") [] (s !! 0)
    in runGen s count (reverse newLine) (gen - 1)
runGen s count lastL gen =
    dispRow lastL (s !! 3) (s !! 4) >>
    let newLine = createNewLine (' ':' ':lastL ++ "  ") [] (s !! 0)
    in runGen s (count - 1) (reverse newLine) gen

argsNotEmpty :: [String] -> Either String [String]
argsNotEmpty args = if length args == 0
    then Left "Invalid arguments"
    else Right args

mainbis :: [String] -> IO [Int]
mainbis nonEmptyArgs = do
    tmp <- checkArgs nonEmptyArgs [readMaybe "-84", readMaybe "0",
        readMaybe "-100", readMaybe "80", readMaybe "0"]
    processInputs tmp [] 0

invalidParams :: [Int] -> Bool
invalidParams paramsList = (-84 `elem` paramsList)

main :: IO ()
main = do
    args <- getArgs
    case argsNotEmpty args of
        Left errMsg -> exitError 84 errMsg
        Right nonEmptyArgs -> do
            paramsList <- mainbis nonEmptyArgs
            if invalidParams paramsList then exitError 84 "Invalid arguments"
            else runGen paramsList (paramsList !! 2) "*" (paramsList !! 1)
