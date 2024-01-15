{-
-- EPITECH PROJECT, 2023
-- Glados
-- File description:
-- Parser.hs
-}

module Parser (readExpr, readExprList) where

import Control.Monad
import Control.Monad.Except
import Data.Char (digitToInt, isDigit, isSpace)
import Data.Functor ((<&>))
import Numeric ()
import Text.ParserCombinators.Parsec hiding (spaces)
import DataSet

-- PARSER --
readExpr :: String -> ThrowsError LispVal
readExpr = readOrThrow parseExpr

readExprList :: String -> ThrowsError [LispVal]
readExprList = readOrThrow (endBy parseExpr spaces)

readOrThrow :: Parser a -> String -> ThrowsError a
readOrThrow parser input = case parse parser "lisp" input of
  Left err -> throwError $ Parser err
  Right val -> return val

parseExpr :: Parser LispVal
parseExpr =
    parseComment
    <|> parseAtom
    <|> parseString
    <|> parseNumber
    <|> parseBool
    <|> parseQuoted
    <|> parseBeginExpr
    <|> do
      _ <- char '('
      x <- try parseList <|> parseDottedList
      _ <- char ')'
      return x

parseBeginExpr :: Parser LispVal
parseBeginExpr = do
  _ <- try $ string "(begin"
  _ <- many1 space
  expressions <- sepBy parseExpr spaces
  _ <- char ')'
  return $ case expressions of
    [] -> LispVoid
    _ -> last expressions

parseComment :: Parser LispVal
parseComment = do
  _ <- char ';'
  _ <- many (noneOf "\n" <|> (eof >> return '\n'))
  return $ String ""

parseAtom :: Parser LispVal
parseAtom = do
  first <- letter <|> symbol
  rest <- many (letter <|> digit <|> symbol)
  let atom = first : rest
  return $ case atom of
    "#t" -> Bool True
    "#f" -> Bool False
    _ ->
      case atom of
        (c:_) | isDigit c -> Number (read atom)
        ('-':c:_) | not (isSpace c) -> Number (read atom)
        _ -> Atom atom

parseString :: Parser LispVal
parseString = do
  _ <- char '"'
  x <- many $ escapedChars <|> noneOf "\\\""
  _ <- char '"'
  return $ String x

escapedChars :: Parser Char
escapedChars = do
  _ <- char '\\'
  x <- oneOf "\\\"nrt"
  return $ case x of
    '\\' -> x
    '"' -> x
    'n' -> '\n'
    'r' -> '\r'
    't' -> '\t'
    _ -> x

parseNumber :: Parser LispVal
parseNumber = parseDecDef <|> parseDecQual <|> parseHex <|> parseBin <|> parseNegDecDef

parseDecDef :: Parser LispVal
parseDecDef = many1 digit <&> (Number . read)

parseNegDecDef :: Parser LispVal
parseNegDecDef = do
  _ <- char '-'
  x <- many1 digit
  return $ Number (read ('-' : x))

parseDecQual :: Parser LispVal
parseDecQual = do
  _ <- try $ string "#d"
  x <- many1 digit
  (return . Number . read) x

parseHex :: Parser LispVal
parseHex = do
  _ <- try $ string "#x"
  x <- many1 hexDigit
  return $ Number (hex2dec x)
  where
    hex2dec :: String -> Integer
    hex2dec [] = 0
    hex2dec xs = toInteger (digitToInt $ last xs) + 16 * hex2dec (init xs)

parseBin :: Parser LispVal
parseBin = do
  _ <- try $ string "#b"
  x <- many1 (oneOf "10")
  return $ Number (bin2dec x)
  where
    bin2dec :: String -> Integer
    bin2dec [] = 0
    bin2dec xs = toInteger (digitToInt $ last xs) + 2 * bin2dec (init xs)

parseBool :: Parser LispVal
parseBool = do
  _ <- char '#'
  (char 't' >> return (Bool True)) <|> (char 'f' >> return (Bool False))

parseList :: Parser LispVal
parseList = liftM List $ sepBy parseExpr spaces

parseDottedList :: Parser LispVal
parseDottedList = do
  _head <- endBy parseExpr spaces
  _tail <- char '.' >> spaces >> parseExpr
  return $ DottedList _head _tail

parseQuoted :: Parser LispVal
parseQuoted = do
  _ <- char '\''
  x <- parseExpr
  return $ List [Atom "quote", x]

spaces :: Parser () -- Matches (skips) spaces
spaces = skipMany1 space

symbol :: Parser Char
symbol = oneOf "!$%&|*+-/:<=>?@^_~"
