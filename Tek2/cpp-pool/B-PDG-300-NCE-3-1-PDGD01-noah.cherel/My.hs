{-
-- EPITECH PROJECT, 2023
-- My.hs
-- File description:
-- Day 1
-}

-- Task 1
mySucc :: Int -> Int
mySucc x = x + 1

-- Task 2
myIsNeg :: Int -> Bool
myIsNeg x = if x < 0 then True else False

-- Task 3
myAbs :: Int -> Int
myAbs x = if x < 0 then x * (-1) else x

-- Task 4
myMin :: Int -> Int -> Int
myMin x y = if x < y then x else y

-- Task 5
myMax :: Int -> Int -> Int
myMax x y = if x > y then x else y

-- Task 6
myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

-- Task 7
myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

-- Task 8
myFst :: (a, b) -> a
myFst (a, b) = a

-- Task 9
mySnd :: (a, b) -> b
mySnd (a, b) = b

-- Task 10
mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

-- Task 11
myHead :: [a] -> a
myHead [] = error "myHead: empty list"
myHead (x:_) = x

-- Task 12
myTail :: [a] -> [a]
myTail [] = error "myTail: empty list"
myTail (_:xs) = xs

-- Task 13
myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

-- Task 14
myNth :: [a] -> Int -> a
myNth [] _ = error "Index is too large or negative"
myNth (x:_) 0 = x
myNth (_:xs) n = myNth xs (n - 1)

-- Task 15
myTake :: Int -> [a] -> [a]
myTake _ [] = []
myTake 0 _  = []
myTake n (x:xs) = x : myTake (n - 1) xs

-- Task 16
myDrop :: Int -> [a] -> [a]
myDrop _ [] = []
myDrop 0 xs = xs
myDrop n (_:xs) = myDrop (n - 1) xs

-- Task 17
myAppend :: [a] -> [a] -> [a]
myAppend [] ys = ys
myAppend (x:xs) ys = x : myAppend xs ys

-- Task 18
myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

-- Task 19
myInit :: [a] -> [a]
myInit [] = error "myInit: empty list"
myInit [x] = []
myInit (x:xs) = x : myInit xs

-- Task 20
myLast :: [a] -> a
myLast [] = error "myLast: empty list"
myLast[x] = x
myLast(_:xs) = myLast xs

-- Task 21
myZip :: [a] -> [b] -> [(a, b)]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

-- Task 22
myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x, y):xs) = (x : myFst (myUnzip xs), y : mySnd (myUnzip xs))

-- Task 23
myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (x:xs) = f x : myMap f xs

-- Task 24
myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter p (x:xs)
 | p x = x :myFilter p xs
 | otherwise = myFilter p xs

-- Task 25
myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ acc [] = acc
myFoldl f acc (x:xs) = myFoldl f (f acc x) xs

-- Task 26
myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ acc [] = acc
myFoldr f acc (x:xs) = f x (myFoldr f acc xs)

-- Task 27
myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition p (x:xs)
 | p x = (x : myFst (myPartition p xs), mySnd (myPartition p xs))
 | otherwise = (myFst (myPartition p xs), x : mySnd (myPartition p xs))