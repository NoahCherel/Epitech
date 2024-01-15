--
-- EPITECH PROJECT, 2023
-- Untitled (Workspace)
-- File description:
-- Main
--

{-|
Module      : Main
Description : Entry point of the compiler.

This module contains the entry point of the compiler. It enables the use of LambdaCase and BlockArguments language extensions.
This module contains the main function of the compiler, which imports System.Environment, Data.Char, Data.List, and Text.Read.
FILEPATH: /home/noahcherel/Public/B-FUN-500-NCE-5-1-glados-nathan.tranchant/compiler/app/Main.hs
-}

{-# LANGUAGE LambdaCase #-}
{-# LANGUAGE BlockArguments #-}

import System.Environment
import Data.Char
import Data.List (isPrefixOf, isInfixOf)
import Text.Read (readMaybe)

-- | Defines the 'Statement' data type which represents either a 'Return' statement with a string value or an 'Assignment' statement with a variable name and an optional string value.
-- The 'Assignment' statement can be used to assign a value to a variable or to declare a new variable with an optional initial value.
data Statement = Return String
              | Assignment String (Maybe String)  -- Change the type to Maybe String for string values
              deriving (Show)

-- | Represents a function with a name and a list of statements.
data Function = Function String [Statement] deriving Show

-- | Represents an expression in the programming language.
--data Expression
    -- | A value expression.
    -- = Value String
    -- | A binary operation expression.
    -- | BinOp String Expression Expression
data Expression = Value String | BinOp String Expression Expression

-- Trim leading and trailing whitespace from a string
trim :: String -> String
trim = f . f
   where f = reverse . dropWhile isSpace

-- Split a string into lines and trim leading/trailing whitespace
splitLines :: String -> [String]
splitLines = map (_trim . dropWhile isSpace) . lines
  where
    _trim = f . f
    f = reverse . dropWhile isSpace

-- | Parses a string into a Statement data type.
--   If the string contains "return", it returns a Return statement with the value after "return".
--   If the string contains "=", it returns an Assignment statement with the variable name and the parsed expression.
--   If the string does not match any of the above, it returns an Assignment statement with an error message.
parseStatement :: String -> Statement
parseStatement line
    | "return" `isPrefixOf` line = Return (dropWhile isSpace $ drop 6 line)
    | "=" `isInfixOf` line =  -- Check for variable assignment
        let (var, rest) = break (== '=') line
            (var', val') = (trim var, trim $ drop 1 rest)
            result = case parseExpression val' of
                Just expr -> Just $ showExpression expr
                Nothing -> Just val'
        in Assignment var' result
    | otherwise =
        let errorMessage = "Unsupported statement: " ++ line
        in Assignment "error" (Just errorMessage)

-- | Parses a string into an expression.
-- The string must be in the form of "lhs operator rhs" or "value".
-- Supported operators are +, -, *, and /.
-- If the string is not a valid expression, returns Nothing.
parseExpression :: String -> Maybe Expression
parseExpression str = case words str of
    [lhs, "+", rhs] -> Just $ BinOp "+" (Value lhs) (Value rhs)
    [lhs, "-", rhs] -> Just $ BinOp "-" (Value lhs) (Value rhs)
    [lhs, "*", rhs] -> Just $ BinOp "*" (Value lhs) (Value rhs)
    [lhs, "/", rhs] -> Just $ BinOp "/" (Value lhs) (Value rhs)
    [val] | all isDigit val -> Just $ Value val
    _ -> Nothing

-- | Converts an 'Expression' to a 'String' representation.
--   If the expression is a 'Value', returns the value as a 'String'.
--   If the expression is a 'BinOp', returns the left-hand side, the operator, and the right-hand side
--   concatenated with spaces.
showExpression :: Expression -> String
showExpression (Value val) = val
showExpression (BinOp op lhs rhs) = showExpression lhs ++ " " ++ op ++ " " ++ showExpression rhs

-- Parse a function from a list of lines
parseFunction :: [String] -> Function
parseFunction (nameLine:stmtLines) =
    case words nameLine of
        ("def":name:_) -> Function name (map parseStatement stmtLines)
        _ -> error "Invalid function format"
parseFunction _ = error "Invalid function format"

-- | Compiles a statement to its corresponding assembly code.
--   For an assignment statement, it generates code to evaluate the right-hand side expression
--   and store the result in the variable. For a return statement, it generates code to return
--   from the current function.
compileStatement :: Statement -> String
compileStatement (Assignment _ value) =
    case value of
        Just str ->
            case parseExpression str of
                Just (BinOp "+" _ _) -> "    pushenv add\n" ++"    call\n"
                Just (BinOp "-" _ _) -> "    pushenv sub\n" ++"    call\n"
                Just (BinOp "*" _ _) -> "    pushenv mul\n" ++"    call\n"
                Just (BinOp "/" _ _) -> "    pushenv div\n" ++"    call\n"
                _ -> case readMaybe str :: Maybe Int of
                       Just intVal -> "    push " ++ show intVal ++ "\n"
                       Nothing -> error $ "Invalid integer: " ++ show str
        Nothing -> let errorMessage = "Unsupported value: " ++ show value
                   in error errorMessage
compileStatement (Return _) =
    "    ret"

-- Check if the code involves a specific operator and generate a function accordingly
generateFunctionIfNeeded :: String -> [Statement] -> String
generateFunctionIfNeeded operator stmts
    | containsOperator = generateFunction operator
    | otherwise = ""
    where
        containsOperator = any (isOperatorAssignment operator) stmts

-- | Checks if a given statement is an operator assignment with the specified operator.
-- |
-- | >>> isOperatorAssignment "+" (Assignment "x" (Just "y + z"))
-- | True
-- |
-- | >>> isOperatorAssignment "-" (Assignment "x" (Just "y + z"))
-- | False
isOperatorAssignment :: String -> Statement -> Bool
isOperatorAssignment operator (Assignment _ (Just str)) =
    case parseExpression str of
        Just (BinOp op _ _) -> operator == op
        _ -> False
isOperatorAssignment _ _ = False

-- | This function takes a string as input and returns a string that represents the corresponding assembly code for the arithmetic operation.
generateFunction :: String -> String
generateFunction "+" = "add 2:\n" ++ "    pusharg 0\n" ++ "    pusharg 1\n" ++ "    push add\n" ++ "    call\n" ++ "    ret"
generateFunction "-" = "sub 2:\n" ++ "    pusharg 0\n" ++ "    pusharg 1\n" ++ "    push sub\n" ++ "    call\n" ++ "    ret"
generateFunction "*" = "mul 2:\n" ++ "    pusharg 1\n" ++ "    pusharg 0\n" ++ "    push mul\n" ++ "    call\n" ++ "    ret"
generateFunction "/" = "div 2:\n" ++ "    pusharg 1\n" ++ "    pusharg 0\n" ++ "    push div\n" ++ "    call\n" ++ "    ret"
generateFunction _ = ""

-- | Generates a addition function if needed based on a list of statements.
generateAddFunctionIfNeeded :: [Statement] -> String
generateAddFunctionIfNeeded stmts = generateFunctionIfNeeded "+" stmts

-- | Generates a substraction function if needed based on a list of statements.
generateSubFunctionIfNeeded :: [Statement] -> String
generateSubFunctionIfNeeded stmts = generateFunctionIfNeeded "-" stmts

-- | Generates a multiplication function if needed based on a list of statements.
generateMulFunctionIfNeeded :: [Statement] -> String
generateMulFunctionIfNeeded stmts = generateFunctionIfNeeded "*" stmts

-- | Generates a division function if needed based on a list of statements.
generateDivFunctionIfNeeded :: [Statement] -> String
generateDivFunctionIfNeeded stmts = generateFunctionIfNeeded "/" stmts

-- Compile a function to assembly-like code
compile :: Function -> String
compile (Function name stmts) =
    let functionName = removeParenthesis name
    in functionName ++ "\n" ++
       concatMap compileStatement stmts

-- Function that removes () from the name
removeParenthesis :: String -> String
removeParenthesis name = filter (\x -> x /= '(' && x /= ')') name

-- | The main function reads a file, parses the function, generates the necessary functions for add, sub, mul, and div, compiles the function and concatenates the non-empty function results.
-- | The result is printed to the console.
main :: IO ()
main = do
    args <- getArgs
    case args of
        [filename] -> do
            input <- readFile filename
            let _lines = splitLines input
            let function = parseFunction _lines

            -- Generate function strings
            let addFunc = generateAddFunctionIfNeeded (case function of Function _ stmts -> stmts)
            let subFunc = generateSubFunctionIfNeeded (case function of Function _ stmts -> stmts)
            let mulFunc = generateMulFunctionIfNeeded (case function of Function _ stmts -> stmts)
            let divFunc = generateDivFunctionIfNeeded (case function of Function _ stmts -> stmts)

            -- Concatenate the non-empty function results
            let functions = [addFunc, subFunc, mulFunc, divFunc]
            let result = unlines $ compile function : filter (not . null) functions

            putStrLn result
        _ -> putStrLn "Usage: ./compiler <filename>"
