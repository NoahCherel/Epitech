-- file: test/ErrorSpec.hs

module ErrorSpec (spec) where

import Test.Hspec
import Control.Exception ()
import Control.Monad.Except

import DataSet()
import ErrorHandling

spec :: Spec
spec = do
    describe "trapError" $ do
        it "should return the result for a successful computation" $ do
            let action = return "A result" :: Except String String
                trappedAction = trapError action
            runExcept trappedAction `shouldBe` Right "A result"
