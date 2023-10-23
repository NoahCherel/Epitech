{-
-- EPITECH PROJECT, 2023
-- Tree.hs
-- File description:
-- Day 3
-}

data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving Show

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node left y right)
    | x < y = Node (addInTree x left) y right
    | x > y = Node left y (addInTree x right)
    | otherwise = Node left y right

instance Functor Tree where
    fmap f Empty = Empty
    fmap f (Node left x right) = Node (fmap f left) (f x) (fmap f right)

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (x:xs) = addInTree x (listToTree xs)

treeToList :: (Ord a) => Tree a -> [a]   
treeToList Empty= []
treeToList (Node left x right) = treeToList left ++ [x] ++ treeToList right

