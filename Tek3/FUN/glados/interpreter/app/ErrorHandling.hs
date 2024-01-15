{-
-- EPITECH PROJECT, 2023
-- Glados
-- File description:
-- ErrorHandling.hs
-}

{-# OPTIONS_GHC -Wno-incomplete-patterns #-}

module ErrorHandling (trapError, liftThrows, extractValue) where

import Control.Monad.Except
import DataSet

-- ERROR HANDLING --
trapError :: (MonadError e m, Show e) => m String -> m String
trapError action = catchError action (return . show)

liftThrows :: ThrowsError a -> IOThrowsError a
liftThrows (Left err) = throwError err
liftThrows (Right val) = return val

extractValue :: ThrowsError a -> a
extractValue (Right val) = val
