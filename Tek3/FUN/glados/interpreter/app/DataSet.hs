{-
-- EPITECH PROJECT, 2023
-- Glados
-- File description:
-- DataSet.hs
-}

{-# OPTIONS_GHC -Wno-partial-fields #-}

module DataSet (LispVal(..), LispError(..), ThrowsError, IOThrowsError, Env) where

import Control.Monad.Except
import Data.IORef
import System.IO
import Text.ParserCombinators.Parsec hiding (spaces)

-- SYNONYMS --
type ThrowsError = Either LispError
type IOThrowsError = ExceptT LispError IO
type Env = IORef [(String, IORef LispVal)]

-- DATA --
data LispVal -- All Possible Lisp Values (Show defined)
  = Atom String
  | List [LispVal]
  | DottedList [LispVal] LispVal
  | Number Integer
  | String String
  | Bool Bool
  | PrimitiveFunc ([LispVal] -> ThrowsError LispVal)
  | Func {params :: [String], vararg :: Maybe String, body :: [LispVal], closure :: Env}
  | IOFunc ([LispVal] -> IOThrowsError LispVal)
  | Port Handle
  | LispVoid

data LispError -- Parse Time / Run Time errors
  = NumArgs Integer [LispVal]
  | TypeMismatch String LispVal
  | Parser ParseError
  | BadSpecialForm String LispVal
  | NotFunction String String
  | UnboundVar String String String
  | Default String
