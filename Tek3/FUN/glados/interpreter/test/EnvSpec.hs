-- file: test/EnvSpec.hs
{-# OPTIONS_GHC -Wno-incomplete-patterns #-}

module EnvSpec (spec) where

import Test.Hspec
import Control.Exception ()
import Data.IORef
import Control.Monad.Except
import Control.Monad.IO.Class()

import DataSet
import Env

lispErrorToString :: Either LispError LispVal -> String
lispErrorToString (Left (NumArgs expected _)) = "NumArgs: Expected " ++ show expected
lispErrorToString (Left (TypeMismatch _exp _)) = "TypeMismatch: Expected " ++ _exp
lispErrorToString (Right val) = "Right value: " ++ lispValToString val

lispValToString :: LispVal -> String
lispValToString (Number n) = show n

spec :: Spec
spec = do
    describe "nullEnv" $ do
        it "Returns an empty environment" $ do
            env <- nullEnv
            isBound env "foo" `shouldReturn` False

    describe "isBound" $ do
        it "Check if a variable is bound" $ do
            envRef <- liftIO $ newIORef [("x", undefined), ("y", undefined)]
            isBound envRef "x" `shouldReturn` True
            isBound envRef "y" `shouldReturn` True
            isBound envRef "z" `shouldReturn` False

    describe "defineVar" $ do
        it "Defines a new variable when it's not already defined" $ do
            env <- nullEnv
            _ <- runExceptT $ defineVar env "a" (Number 1)
            isBound env "a" `shouldReturn` True
        it "Redefines a variable when it's already defined" $ do
            env <- nullEnv
            _ <- runExceptT $ defineVar env "a" (Number 1)
            _ <- runExceptT $ defineVar env "a" (Number 2)
            isBound env "a" `shouldReturn` True

    describe "getVar" $ do
        it "Returns the value of a variable" $ do
            env <- nullEnv
            _ <- runExceptT $ defineVar env "a" (Number 1)
            val <- runExceptT $ getVar env "a"
            (lispErrorToString val) `shouldBe` "Right value: 1"

    describe "setVar" $ do
        it "Sets the value of a variable" $ do
            env <- nullEnv
            _ <- runExceptT $ defineVar env "a" (Number 1)
            _ <- runExceptT $ setVar env "a" (Number 2)
            val <- runExceptT $ getVar env "a"
            (lispErrorToString val) `shouldBe` "Right value: 2"

    describe "bindVars" $ do
        it "binds variables and retrieves them correctly" $ do
            env <- nullEnv
            newEnv <- bindVars env [("a", Number 1), ("b", Number 2)]
            isBound newEnv "a" `shouldReturn` True
            isBound newEnv "b" `shouldReturn` True
            isBound newEnv "c" `shouldReturn` False
