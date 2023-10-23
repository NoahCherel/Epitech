{-
-- EPITECH PROJECT, 2023
-- Untitled (Workspace)
-- File description:
-- Display
-}

module Display (module Display) where

calIndex :: Int -> Int -> Int -> Int
calIndex win seg move = div win 2 - div seg 2
  +(if even seg && odd win then 1 else 0) + move

genpadd :: Int -> [Char] -> [Char]
genpadd count res = replicate count ' ' ++ res

addChars :: Int -> [Char] -> [Char] -> [Char] -> Int -> Int -> Int -> [Char]
addChars size ini res line cIndex sIndex endIndex
    | cIndex >= size  = res
    | not (null line) && cIndex >= sIndex && cIndex < endIndex  = 
        addChars size (tail ini) (head line : res) (tail line) (cIndex + 1)
        sIndex endIndex
    | not (null ini) = 
        addChars size (tail ini) (head ini : res) line (cIndex + 1)
        sIndex endIndex
    | otherwise = res

shiftStart :: [Char] -> Int -> [Char]
shiftStart start count
  | count + 2 > 1 = start
  | null start = start
  | otherwise = shiftStart (tail start) (count + 1)

dispRow :: [Char] -> Int -> Int -> IO ()
dispRow str win move = 
  let sIndex = calIndex win (length str) move
      (start, end) = if sIndex < 1
          then (sIndex, sIndex + length str)
          else if sIndex < win
            then (sIndex, sIndex + length str)
            else (0, 0)
  in putStrLn $ reverse $ addChars win (genpadd win []) []
    (shiftStart str sIndex) 0 start end