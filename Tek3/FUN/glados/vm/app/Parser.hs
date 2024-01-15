--
-- EPITECH PROJECT, 2023
-- vm
-- File description:
-- Parser
--

module Parser (
    splitLines,
    checkMain,
    parseWord,
    stripLeadingWhitespace,
    parseValue,
    parseString,
    parseBoolean,
    parseDigits,
    parseFunctions,
    bytecodesAssembler,
    parseFunctionDefinition
) where

import Data.Char
import DataSet
import Data.Map (Map, fromList, lookup)

-- PARSE --

-- | Splits a string into a list of strings, each representing a line.
-- splitLines :: String -> [String]
splitLines :: String -> [String]
splitLines "" = []
splitLines input =
    let (line, rest) = break (== '\n') input
    in case rest of
        ""     -> [line]
        (_:remaining) -> line : splitLines remaining


-- | Checks if the main function is present in the list of strings.
-- Returns either an error message or the list of strings after the main function.
-- checkMain :: [String] -> Either String [String]
checkMain :: [String] -> Either String [String]
checkMain [] = Left "[ERROR] Main function not found"
checkMain ("main:":restOfLines) = Right restOfLines
checkMain (_:xs) = checkMain xs

-- | Parses a word from a string and returns a tuple with the word and the rest of the string.
-- parseWord :: String -> (String, String)
parseWord :: String -> (String, String)
parseWord input= (firstWord, stripLeadingWhitespace rest)
  where
    (firstWord, rest) = break (\c -> c == ' ' || c == '\t') input

-- | Removes leading whitespace from a string.
-- stripLeadingWhitespace :: String -> String
stripLeadingWhitespace :: String -> String
stripLeadingWhitespace = dropWhile (\c -> c == ' ' || c == '\t')

-- | Parses a string value from a string.
-- Returns either an error message or a TextValue.
-- parseValue :: String -> Either String NewLangVal
parseValue :: String -> Either String NewLangVal
parseValue inputString =
  case stripLeadingWhitespace inputString of
    indentedStr ->
      case parseString indentedStr of
        Right (textValue, _) -> Right (TextValue textValue)
        _ ->
          case parseDigits indentedStr of
            ([], _) -> handleBoolOrBuiltIn indentedStr
            (integerStr, _) -> Right (IntegerValue (read integerStr :: Int))
  where
    handleBoolOrBuiltIn string' =
      case parseBoolean string' of
        Right boolValue -> Right (BoolValue boolValue)
        _ ->
          case parseFunctions string' of
            Right builtinFunction -> Right (BuiltInFunction builtinFunction)
            Left errorValue -> error errorValue

-- | Parses a string value from a string.
-- Returns either an error message or a tuple with the string value and the rest of the string.
-- parseString :: String -> Either String (String, String)
parseString :: String -> Either String (String, String)
parseString ('"':rest) = extractString rest
parseString _ = Left "[ERROR] String not found"

-- | Parses a boolean value from a string.
-- Returns either an error message or a BoolValue.
-- parseBoolean :: String -> Either String Bool
parseBoolean :: String -> Either String Bool
parseBoolean string = case words $ _stripLeadingWhitespace string of
    ["true"] -> Right True
    ["false"] -> Right False
    _ -> Left "[ERROR] Bool not found"
  where
    _stripLeadingWhitespace = dropWhile isSpace

extractString :: String -> Either String (String, String)
extractString [] = Left "[ERROR] String not found"
extractString xs = Right (takeWhile (/= '"') xs, dropWhile (/= '"') xs)

-- | Parses an integer value from a string.
-- Returns a tuple with the integer value and the rest of the string.
-- parseDigits :: String -> (String, String)
parseDigits :: String -> (String, String)
parseDigits [] = ("", "")
parseDigits (currentChar:remainingChars)
    | isDigit currentChar = let (digitsBefore, digitsAfter) = parseDigits remainingChars in (currentChar : digitsBefore, digitsAfter)
    | otherwise = ("", currentChar : remainingChars)
-- | Parses a function from a string.
-- Returns either an error message or a BuiltInFunction or a NotFunction.
-- parseFunctions :: String -> Either String NewLangFunc
parseFunctions :: String -> Either String NewLangFunc
parseFunctions string = case Data.Map.lookup (head $ words string) func of
    Just _func -> case words string of
        [] -> Left "No function name provided"
        [_] -> Right _func
        (_:_) -> Right (NotFunction _func)
    Nothing -> error "[ERROR] Function not found"
  where
    func :: Map String NewLangFunc
    func = fromList [
        ("add", AddFunction),
        ("sub", SubFunction),
        ("mul", MulFunction),
        ("div", DivFunction),
        ("eq", EqqFunction),
        ("less", LessFunction),
        ("not", NotFunction undefined)
      ]

-- | Assembles a list of strings into a list of bytecodes.
-- bytecodesAssembler :: [String] -> Bytecodes -> Bytecodes
bytecodesAssembler :: [String] -> Bytecodes -> Bytecodes
bytecodesAssembler [] bytecodeList = bytecodeList
bytecodesAssembler (line:_lines) bytecodeList
    | null (stripLeadingWhitespace line) = bytecodesAssembler _lines bytecodeList  -- Skip empty lines
    | instruction == "push" = case parseValue rest of
        Right value -> bytecodesAssembler _lines (bytecodeList ++ [PushOperation value])
        Left errorValue -> error errorValue
    | instruction == "call" = bytecodesAssembler _lines (bytecodeList ++ [CallOperation])
    | instruction == "ret" = bytecodesAssembler _lines (bytecodeList ++ [ReturnOperation])
    | instruction == "jmpiffalse" = case parseValue rest of
        Right (IntegerValue value) -> bytecodesAssembler _lines (bytecodeList ++ [ConditionalJumpOperation value])
        _ -> error "Error: not a numberValue"
    | instruction == "pusharg" = case parseValue rest of
        Right (IntegerValue value) -> bytecodesAssembler _lines (bytecodeList ++ [PushArgumentOperation value])
        _ -> error "Error: not a IntegerValue"
    | instruction == "pushenv" = bytecodesAssembler _lines (bytecodeList ++ [PushEnvironmentOperation $ fst (parseWord (stripLeadingWhitespace rest))])
    | instruction == "pushvar" = bytecodesAssembler _lines (bytecodeList ++ [PushVariableOperation $ fst (parseWord (stripLeadingWhitespace rest))])
    | instruction == "changevar" = case parseWord $ stripLeadingWhitespace rest of
        (name, rest') -> case parseValue rest' of
            Right value -> bytecodesAssembler _lines (bytecodeList ++ [ModifyVariableOperation name value])
            Left errorValue -> error errorValue
    | otherwise = bytecodeList
    where (instruction, rest) = parseWord $ stripLeadingWhitespace line

-- | Parses a function definition from a string.
-- Returns either an error message or a tuple with the function name and the number of arguments.
-- parseFunctionDefinition :: String -> Either String (String, Int)
parseFunctionDefinition :: String -> Either String (String, Int)
parseFunctionDefinition line =
  case (parseWord $ stripLeadingWhitespace line) of
    (name, rest) ->
      case parseDigits $ stripLeadingWhitespace rest of
        (nb, rest') ->
          case parseWord $ stripLeadingWhitespace rest' of
            (colon, _) ->
              if colon == ":"
                then Right (name, read nb :: Int)
                else Left "[ERROR] Function definition must be of the form \"name: nb\""
