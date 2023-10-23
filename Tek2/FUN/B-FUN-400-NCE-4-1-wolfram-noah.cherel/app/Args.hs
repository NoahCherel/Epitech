{-
-- EPITECH PROJECT, 2023
-- Untitled (Workspace)
-- File description:
-- Args
-}

module Args (module Args) where

import Text.Read
import Data.List (elemIndex)

processInputs :: [Maybe Int] -> [Int] -> Int -> IO [Int]
processInputs s res 5 = return (reverse res)
processInputs s res index = case (s !! index) of
    Nothing -> processInputs s (-84:res) (index + 1)
    Just n -> processInputs s (getValue n index:res) (index + 1)

getValue :: Int -> Int -> Int
getValue 30 0 = 30
getValue 90 0 = 90
getValue 110 0 = 110
getValue n 1 | n >= 0 = n
getValue (-100) 2 = -1
getValue n 2 | n >= 0 = n
getValue n 3 | n >= 0 = n
getValue n 4 = n
getValue _ _ = -84

updateArgs :: [Maybe Int] -> Int -> Maybe Int -> [Maybe Int]
updateArgs s index newVal
    | index >= 0 && index < 5 = take index s ++ [newVal] ++ drop (index + 1) s
    | otherwise = replicate 5 Nothing

parseArgs :: [String] -> [Maybe Int] -> IO [Maybe Int]
parseArgs [] res = return res
parseArgs (x:s) res =
    case elemIndex x ["--rule", "--start", "--lines", "--window", "--move"] of
        Just index -> 
            case s of
                (val:rest) ->
                    let newVal = readMaybe val
                        nextRes = updateArgs res index newVal
                    in parseArgs rest nextRes
                _ -> return res
        _ -> return res

checkArgs :: [String] -> [Maybe Int] -> IO [Maybe Int]
checkArgs [] res = return res
checkArgs ("--rule" : arg : s) res = checkArgs s 
    (updateArgs res 0 (readMaybe arg))
checkArgs ("--start" : arg : s) res = checkArgs s 
    (updateArgs res 1 (readMaybe arg))
checkArgs ("--lines" : arg : s) res = checkArgs s
    (updateArgs res 2 (readMaybe arg))
checkArgs ("--window" : arg : s) res = checkArgs s
    (updateArgs res 3 (readMaybe arg))
checkArgs ("--move" : arg : s) res = checkArgs s
    (updateArgs res 4 (readMaybe arg))
checkArgs _ _ = return [Nothing, Nothing, Nothing, Nothing, Nothing]
