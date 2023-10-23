{-
-- EPITECH PROJECT, 2023
-- Untitled (Workspace)
-- File description:
-- Main
-}

import System.Random
import Data.String
import Data.List
import Data.Char
import System.Environment
import System.IO
import System.Exit
import Data.Char

data Cluster = Cluster { avgClustcols :: [Int], dot :: [Pix] }
data Params = Params { colors :: Int, convergence :: Float, file_content :: String }
data Pix = Pix { position :: [Int], color :: [Int] }

retRandomPix :: [Pix] -> IO [Int]
retRandomPix str = do
    let len = length str
    i <- randomRIO (0, len - 1)
    let pix = str !! i
    return (color pix)

centroids :: [Cluster] -> [Int] -> Bool
centroids [] _ = True
centroids (x:xs) centroid
    | centroid == avgClustcols x = False
    | otherwise = centroids xs centroid

createClusts :: [Cluster] -> [Pix] -> Int -> IO [Cluster]
createClusts clusters content 0 = return clusters
createClusts clusters content nb =
    do
        centroid <- retRandomPix content
        if centroids clusters centroid
        then createClusts (clusters ++ [Cluster centroid []]) content (nb - 1)
        else createClusts clusters content nb

calcDist :: [Int] -> [Int] -> Float
calcDist [r1, g1, b1] [r2, g2, b2] =
    sqrt (fromIntegral ((r1 - r2) ^ 2 + (g1 - g2) ^ 2 + (b1 - b2) ^ 2))

calcDistToClusts :: [Cluster] -> Pix -> [Float] -> [Float]
calcDistToClusts [] _ dists = dists
calcDistToClusts (x:xs) point dists =
    let dist = calcDist (avgClustcols x) (color point)
    in calcDistToClusts xs point (dists ++ [dist])

addPixToClust :: Cluster -> Pix -> Cluster
addPixToClust cluster pix = cluster {dot = dot cluster ++ [pix]}

minIndexInClust :: [Float] -> Float -> Int -> Int
minIndexInClust [] _ _ = 0
minIndexInClust (x:xs) smallestDist index
    | x == smallestDist = index
    | otherwise = minIndexInClust xs smallestDist (index + 1)

repValInd :: [Cluster] -> Cluster -> Int -> [Cluster]
repValInd (x:xs) newCluster 0 = newCluster:xs
repValInd (x:xs) newCluster index = x:repValInd xs newCluster (index - 1)
repValInd [] _ _ = []

nearestCluster :: [Cluster] -> Pix -> [Float] -> [Cluster]
nearestCluster clusters point dist =
    let smallestDist = minIndexInClust dist (minimum dist) 0
    in repValInd clusters
        (addPixToClust (clusters !! smallestDist) point)
        smallestDist

updateClustWithPix :: [Cluster] -> [Pix] -> [Cluster]
updateClustWithPix clusters [] = clusters
updateClustWithPix clusters (x:xs) =
  updateClustWithPix (nearestCluster clusters x dist) xs
    where dist = calcDistToClusts clusters x []

calcAvgColor :: [Pix] -> [Int] -> Int -> [Int]
calcAvgColor [] [r, g, b] nb = [r `div` nb, g `div` nb, b `div` nb]
calcAvgColor (x:xs) [r, g, b] nb =
  let [r', g', b'] = color x
  in calcAvgColor xs [r + r', g + g', b + b'] nb

calcClust :: Cluster -> Cluster
calcClust newCluster =
  let oldDots = dot newCluster
      numDots = length oldDots
      newClustColor = calcAvgColor oldDots [0, 0, 0] numDots
  in newCluster {avgClustcols = newClustColor, dot = []}

updateClusters :: [Cluster] -> [Cluster] -> [Cluster]
updateClusters [] newClusters = newClusters
updateClusters (oldCluster:remainingClusters) newClusters =
    updateClusters remainingClusters (newClusters ++ [calcClust oldCluster])

distToClusts :: [Cluster] -> [Cluster] -> [Float] -> [Float]
distToClusts [] _ dists = dists
distToClusts (oldCluster:remOldClusts) (newClust:remNewClusts) dists =
    let newDist = calcDist (avgClustcols oldCluster) (avgClustcols newClust)
    in distToClusts remOldClusts remNewClusts (dists ++ [newDist])

isConverged :: [Float] -> Float -> Bool
isConverged [] _ = True
isConverged (dist:remainingDists) threshold
    | dist <= threshold = isConverged remainingDists threshold
    | otherwise = False

runAlgoKmean :: [Cluster] -> Params -> [Pix] -> [Cluster]
runAlgoKmean clusters params points = go clusters
  where
    go cs =
      let newCs = updateClusters cs []
          distances = distToClusts cs newCs []
      in if isConverged distances (convergence params)
         then cs
         else go (updateClustWithPix newCs points)

parsePixFile :: String -> Either String [Pix]
parsePixFile text =
    parseLines (remSpace (lines text))

parseLines :: [String] -> Either String [Pix]
parseLines lines = go lines []
  where
    go [] acc = Right acc
    go (x:xs) acc =
      case checkLn x >>= processArgs of
        Right parsed -> go xs (appendToEnd acc parsed)
        Left err -> Left err

appendToEnd :: [Pix] -> Pix -> [Pix]
appendToEnd xs x = xs ++ [x]

checkLn :: String -> Either String String
checkLn line
    | checkSetup line = Right line
    | otherwise = Left "Parsing: One of the line is invalid"

checkSetup :: String -> Bool
checkSetup line = head line == '(' && last line == ')'

remSpace :: [String] -> [String]
remSpace = filter (not . null)

processArgs :: String -> Either String Pix
processArgs text = do
    let infos = words text
        posi = removecharbisbis $ head infos
        cols = removecharbisbis $ infos !! 1
    pos <- retPos posi
    col <- retColors cols
    return Pix { position = pos, color = col }
  where removecharbisbis = filter (`notElem` "()")

retPos :: [Char] -> Either String [Int]
retPos pos = case mapM readMaybeInt sep of
               Just [x,y] -> Right [x,y]
               _ -> Left "Parsing: One of the position is invalid"
  where sep = words $ map removecharbis pos

removecharbis :: Char -> Char
removecharbis c | c `elem` ",()" = ' '
             | otherwise = c

readMaybeInt :: String -> Maybe Int
readMaybeInt s = case reads s of
                   [(x,"")] -> Just x
                   _ -> Nothing

retColors :: [Char] -> Either String [Int]
retColors col =
    let sep = words $ map removechar col
    in if length sep == 3 && checkIfNum sep
    then case checkSizeValue [read $ head sep :: Int,
                              read $ sep !! 1 :: Int,
                              read $ sep !! 2 :: Int] of
        Right val -> Right val
        Left str -> Left str
    else Left "Parsing: One of the color is invalid"

checkIfNum :: [String] -> Bool 
checkIfNum [a,b] = checkFloat a && checkFloat b
checkIfNum [a,b,c] = checkFloat a && checkFloat b && checkFloat c
checkIfNum _ = False

checkSizeValue :: [Int] -> Either String [Int]
checkSizeValue [a,b,c]
    | any (<0) [a,b,c] || any (>255) [a,b,c] =
        Left "Parsing: The color value must be between 0 and 255"
    | otherwise = Right [a,b,c]
checkSizeValue _ = Left "Parsing: Invalid number of arguments"

removechar :: Char -> Char
removechar ',' = ' '
removechar x = x

checkFloat :: String -> Bool
checkFloat s = case reads s :: [(Float, String)] of
    [(_, "")] -> True
    _         -> False

getPos :: Pix -> String
getPos c =
    "(" ++ show (head (position c)) ++ "," ++ show (position c !! 1) ++ ") "

getRgb :: Pix -> String
getRgb c =
    "(" ++ show (head (color c)) ++ "," ++ show (color c !! 1) ++ ","
    ++ show (color c !! 2) ++ ")"

dispDots :: [Pix] -> IO ()
dispDots [] = return ()
dispDots (x:xs) = 
    let position = getPos x
        colors = getRgb x
        output = position ++ colors
    in putStrLn output >> dispDots xs

dispClust :: [Cluster] -> IO ()
dispClust [] = return ()
dispClust (x:xs) = 
    putStrLn "--" >>
    dispClustRgb (avgClustcols x) >>
    putStrLn "-" >>
    dispDots (dot x) >>
    dispClust xs

dispClustRgb :: [Int] -> IO ()
dispClustRgb [r,g,b] =
    putStrLn $ "(" ++ show r ++ "," ++ show g ++ "," ++ show b ++ ")"

runProg :: [Pix] -> Params -> IO ()
runProg contents opt = do
    clusters <- createClusts [] contents (colors opt)
    let setClusters = updateClustWithPix clusters contents
        in dispClust $ runAlgoKmean setClusters opt contents

main :: IO ()
main = do
    opt <- getOpt
    contents <- readFile (file_content opt)
    runProgram (parseLines $ lines contents) opt

getOpt :: IO Params
getOpt = do
    params <- getArgs
    return $ argsCheck params (Params 0 0 "")

runProgram :: Either String [Pix] -> Params -> IO ()
runProgram (Left str) _ = putStrLn str
runProgram (Right res) opt = runProg res opt

help :: String
help = "help: ./compressor n l f\n\
       \twhere n is the number of colors in the final image,\n\
       \t      l a limit for the comparison of colors\n\
       \t      f is the file containing the colors to compress"

argsCheck :: [String] -> Params -> Params
argsCheck ("-n" : val:xs) opt
    | all isDigit val = argsCheck xs opt { colors = read val }
argsCheck ("-l" : val:xs) opt
    | checkFloat val = argsCheck xs opt { convergence = read val }
argsCheck ("-f" : val:xs) opt = opt { file_content = val }
argsCheck (_ : xs) opt = argsCheck xs opt
argsCheck [] opt = opt

paramsCheck :: Params -> Either String Params
paramsCheck opt
    | colors opt == 0 
        || convergence opt == 0 
        || file_content opt == "" 
        = Left help
    | otherwise = Right opt
