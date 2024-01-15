-- file: test/ParserSpec.hs
{-# OPTIONS_GHC -Wno-incomplete-patterns #-}

module ParserSpec (spec) where

import Test.Hspec
import Numeric ()

import DataSet
import Parser

lispValToString :: Either LispError LispVal -> String
lispValToString (Left _) = "Error: "
lispValToString (Right (String s)) = "String: " ++ s

spec :: Spec
spec = do
    describe "readExpr" $ do
        it "should parse a string correctly" $ do
            (lispValToString $ readExpr "\"hello\"") `shouldBe` "String: hello"
