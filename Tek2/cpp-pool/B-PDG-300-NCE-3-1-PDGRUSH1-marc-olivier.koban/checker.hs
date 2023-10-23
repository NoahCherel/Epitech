{-
-- EPITECH PROJECT, 2023
-- checker.hs
-- File description:
-- Paradigm seminar Rush 01
-}

import Data.List
import System.Environment
import System.Exit

pushswap_checker :: [Int] -> [String] -> ([Int], [Int])
pushswap_checker l_a ops
  | null l_a = ([], [])
  | invalidInput = ([84], [84])
  | otherwise = foldl applyOperations (l_a, []) ops
  where
    invalidInput =
      any (\x -> notElem x ["sa", "sb", "sc", "pa", "pb", "ra", "rb", "rr",
                            "rra", "rrb", "rrr"]) ops

applyOperations :: ([Int], [Int]) -> String -> ([Int], [Int])
applyOperations (l_a, l_b) "sa" = (swap l_a, l_b)
applyOperations (l_a, l_b) "sb" = (l_a, swap l_b)
applyOperations (l_a, l_b) "sc" = (swap l_a, swap l_b)
applyOperations (l_a, l_b) "pa" = let x = head l_b in (x:l_a, tail l_b)
applyOperations (l_a, l_b) "pb" = (tail l_a, x:l_b) where x = head l_a
applyOperations (l_a, l_b) "ra" = (rotate l_a, l_b)
applyOperations (l_a, l_b) "rb" = (l_a, rotate l_b)
applyOperations (l_a, l_b) "rr" = (rotate l_a, rotate l_b)
applyOperations (l_a, l_b) "rra" = (reverseRotate l_a, l_b)
applyOperations (l_a, l_b) "rrb" = (l_a, reverseRotate l_b)
applyOperations (l_a, l_b) "rrr" = (reverseRotate l_a, reverseRotate l_b)

swap :: [a] -> [a]
swap (x:y:xs) = y:x:xs
swap xs = xs

rotate :: [a] -> [a]
rotate (x:xs) = xs ++ [x]
rotate xs = xs

reverseRotate :: [a] -> [a]
reverseRotate xs = last xs : init xs

main :: IO ()
main = getArgs >>= \args -> getLine >>= \line ->
  let l_a = map read args :: [Int]
      ops = words line
      (result_a, result_b) = pushswap_checker l_a ops
      sorted_a = sort l_a
      output = if result_a == sorted_a && null result_b then "OK"
      else "KO: ([" ++ (intercalate "," (map show result_a)) ++
        "],[" ++ (intercalate "," (map show result_b)) ++ "])"
  in if result_a == [84] && result_b == [84] then exitWith (ExitFailure 84)
     else putStrLn output
