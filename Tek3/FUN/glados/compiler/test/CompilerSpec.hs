-- file: test/CompilerSpec.hs

module CompilerSpec (spec) where

import Test.Hspec
import System.Process

spec :: Spec
spec = do
  describe "basic" $ do
    it "Doit compiler basic.py" $ do
      let command = "../glados_compiler ../examples/compiler/basic.py"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "main:\n    push 42\n    ret\n\n"

  describe "add" $ do
    it "Doit compiler add.py" $ do
      let command = "../glados_compiler ../examples/compiler/add.py"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "main:\n    push 2\n    push 3\n    pushenv add\n    call\n    ret\nadd 2:\n    pusharg 0\n    pusharg 1\n    push add\n    call\n    ret\n\n"

  describe "sub" $ do
    it "Doit compiler sub.py" $ do
      let command = "../glados_compiler ../examples/compiler/sub.py"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "main:\n    push 2\n    push 3\n    pushenv sub\n    call\n    ret\nsub 2:\n    pusharg 0\n    pusharg 1\n    push sub\n    call\n    ret\n\n"

  describe "mult" $ do
    it "Doit compiler mult.py" $ do
      let command = "../glados_compiler ../examples/compiler/mult.py"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "main:\n    push 2\n    push 3\n    pushenv mul\n    call\n    ret\nmul 2:\n    pusharg 1\n    pusharg 0\n    push mul\n    call\n    ret\n\n"

  describe "div" $ do
    it "Doit compiler div.py" $ do
      let command = "../glados_compiler ../examples/compiler/div.py"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "main:\n    push 8\n    push 4\n    pushenv div\n    call\n    ret\ndiv 2:\n    pusharg 1\n    pusharg 0\n    push div\n    call\n    ret\n\n"

  describe "complex" $ do
    it "Doit compiler complex.py" $ do
      let command = "../glados_compiler ../examples/compiler/complex.py"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "main:\n    push 2\n    push 3\n    pushenv add\n    call\n    push 2\n    pushenv mul\n    call\n    ret\nadd 2:\n    pusharg 0\n    pusharg 1\n    push add\n    call\n    ret\nmul 2:\n    pusharg 1\n    pusharg 0\n    push mul\n    call\n    ret\n\n"
