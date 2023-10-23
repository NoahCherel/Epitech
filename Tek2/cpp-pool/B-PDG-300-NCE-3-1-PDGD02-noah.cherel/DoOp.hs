{-
-- EPITECH PROJECT, 2023
-- DoOp.hs
-- File description:
-- Day 2
-}

--main :: IO ()
--main = return ()

import System.Exit
import System.Environment

-- Task 01
myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem x (y:ys) = if x == y then True else myElem x ys

-- Task 02
safeDiv :: Int -> Int -> Maybe Int
safeDiv x y = if y == 0 then Nothing else Just (x `div` y)

-- Task 03
safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:_) 0 = Just x
safeNth (_:xs) n = safeNth xs (n - 1)

-- Task 04
safeSucc :: Maybe Int -> Maybe Int
safeSucc (Just x) = Just (x + 1)
safeSucc Nothing = Nothing

-- Task 05
myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup _ [] = Nothing
myLookup x ((a, b):xs) = if x == a then Just b else myLookup x xs

-- Task 06
maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing _ = Nothing
maybeDo _ _ Nothing = Nothing
maybeDo f (Just x) (Just y) = Just (f x y)

-- Task 07
readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt (x:xs) = if x >= '0' && x <= '9' 
    then Just (read (x:xs) :: Int) else Nothing

-- Task 08
getLineLength :: IO Int
getLineLength = do
    str <- getLine
    return (length str)

-- Task 09
printAndGetLength :: String -> IO Int
printAndGetLength str = let len = length str in do
    str <- putStrLn str
    return len


-- Task 10
printBox :: Int -> IO ()
printBox n
    | n <= 0    = return ()
    | otherwise = putStrLn topLine
                >> mapM_ putStrLn wallLines
                >> putStrLn topLine
    where
        topLine = "+" ++ replicate (n * 2 - 2) '-' ++ "+"
        wallLines = [ "|" ++ replicate (n * 2 - 2) ' ' ++ "|" | _ <- [1..n-2] ]

-- Task 11
concatLines :: Int -> IO String
concatLines n
    | n <= 0 = return ""
    | otherwise = do
        str <- getLine
        str2 <- concatLines (n - 1)
        return (str ++ str2)

-- Task 12
getInt :: IO (Maybe Int)
getInt = do
    str <- getLine
    return (readInt str)
    if readInt str == Nothing then return Nothing else return (readInt str)

-- Task 13

doop :: Integer -> String -> Integer -> IO ()
doop x op y
    | op `elem` ["+"] = putStrLn $ show (x + y)
    | op `elem` ["-"] = putStrLn $ show (x - y)
    | op `elem` ["*"] = if y == 0
            then exitWith (ExitFailure 84) else putStrLn $ show (x * y)
    | op `elem` ["/"] = if y == 0
            then exitWith (ExitFailure 84) else putStrLn $ show (x `div` y)
    | op `elem` ["%"] = if y == 0
            then exitWith (ExitFailure 84) else putStrLn $ show (x `mod` y)
    | otherwise = exitWith (ExitFailure 84)

main :: IO ()
main = do
  args <- getArgs
  case args of
    [xStr, op, yStr] ->
      let x = read xStr
          y = read yStr
      in doop x op y
    _ -> exitWith (ExitFailure 84)
