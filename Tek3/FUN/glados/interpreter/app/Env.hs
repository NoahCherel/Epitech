{-
-- EPITECH PROJECT, 2023
-- Glados
-- File description:
-- Env.hs
-}

module Env (nullEnv, isBound, defineVar, getVar, setVar, bindVars, Env) where

import Control.Monad.Except
import Data.Functor ((<&>))
import Data.IORef
import qualified Data.Maybe
import System.Exit (exitWith, ExitCode(..))
import DataSet

-- ENV --
nullEnv :: IO Env
nullEnv = newIORef []

isBound :: Env -> String -> IO Bool
isBound envRef var = readIORef envRef <&> (Data.Maybe.isJust . lookup var)

defineVar :: Env -> String -> LispVal -> IOThrowsError LispVal
defineVar envRef var value = do
  alreadyDefined <- liftIO $ isBound envRef var
  if alreadyDefined
    then setVar envRef var value >> return value
    else liftIO $ do
      valueRef <- newIORef value
      env <- readIORef envRef
      writeIORef envRef ((var, valueRef) : env)
      return LispVoid

getVar :: Env -> String -> IOThrowsError LispVal
getVar envRef var = do
  env <- liftIO $ readIORef envRef
  maybe
    (do
      liftIO $ putStrLn $ "*** ERROR : variable " ++ var ++ " is not bound."
      liftIO $ exitWith (ExitFailure 84)
    )
    (liftIO . readIORef)
    (lookup var env)

setVar :: Env -> String -> LispVal -> IOThrowsError LispVal
setVar envRef var value = do
  env <- liftIO $ readIORef envRef
  maybe
    (throwError $ UnboundVar "*** ERROR : variable " var " is not bound.")
    (liftIO . flip writeIORef value)
    (lookup var env)
  return value

bindVars :: Env -> [(String, LispVal)] -> IO Env
bindVars envRef newBindings = readIORef envRef >>= extendEnv newBindings >>= newIORef
  where
    extendEnv bindings env = liftM (++ env) (mapM addBinding bindings)
    addBinding (var, value) = do
      ref <- newIORef value
      return (var, ref)
