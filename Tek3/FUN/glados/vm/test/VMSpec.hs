-- file: test/VMSpec.hs

module VMSpec (spec) where

import Test.Hspec
import System.Process

spec :: Spec
spec = do
  describe "add" $ do
    it "Doit renvoyer un fichier avec 7" $ do
      let command = "../glados_vm ../examples/VM/add.txt"
      _ <- readProcess "bash" ["-c", command] ""
      result <- readFile "../examples/VM/add.txt.res"
      result `shouldBe` "7"
    
  describe "sub" $ do
    it "Doit renvoyer un fichier avec 5" $ do
      let command = "../glados_vm ../examples/VM/sub.txt"
      _ <- readProcess "bash" ["-c", command] ""
      result <- readFile "../examples/VM/sub.txt.res"
      result `shouldBe` "5"

  describe "mult" $ do
    it "Doit renvoyer un fichier avec 42" $ do
      let command = "../glados_vm ../examples/VM/mult.txt"
      _ <- readProcess "bash" ["-c", command] ""
      result <- readFile "../examples/VM/mult.txt.res"
      result `shouldBe` "42"

  describe "divi" $ do
    it "Doit renvoyer un fichier avec 0" $ do
      let command = "../glados_vm ../examples/VM/divi.txt"
      _ <- readProcess "bash" ["-c", command] ""
      result <- readFile "../examples/VM/divi.txt.res"
      result `shouldBe` "0"

  describe "new" $ do
    it "Doit renvoyer un fichier avec 3" $ do
      let command = "../glados_vm ../examples/VM/new.txt"
      _ <- readProcess "bash" ["-c", command] ""
      result <- readFile "../examples/VM/new.txt.res"
      result `shouldBe` "3"

  describe "neg" $ do
    it "Doit renvoyer un fichier avec -10" $ do
      let command = "../glados_vm ../examples/VM/neg.txt"
      _ <- readProcess "bash" ["-c", command] ""
      result <- readFile "../examples/VM/neg.txt.res"
      result `shouldBe` "-10"

  describe "factorial" $ do
    it "Doit renvoyer un fichier avec 120" $ do
      let command = "../glados_vm ../examples/VM/factorial.txt"
      _ <- readProcess "bash" ["-c", command] ""
      result <- readFile "../examples/VM/factorial.txt.res"
      result `shouldBe` "120"

  describe "fibo" $ do
    it "Doit renvoyer un fichier avec 55" $ do
      let command = "../glados_vm ../examples/VM/fibo.txt"
      _ <- readProcess "bash" ["-c", command] ""
      result <- readFile "../examples/VM/fibo.txt.res"
      result `shouldBe` "55"

  describe "complex" $ do
    it "Doit renvoyer un fichier avec 10" $ do
      let command = "../glados_vm ../examples/VM/complex.txt"
      _ <- readProcess "bash" ["-c", command] ""
      result <- readFile "../examples/VM/complex.txt.res"
      result `shouldBe` "10"
