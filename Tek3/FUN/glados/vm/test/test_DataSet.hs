module EnvSpec where

import Test.Hspec

import DataSet

-- Not used for now
spec :: Spec
spec = do
  describe "Operation" $ do
    it "PushOperation should show the correct value" $ do
      show (PushOperation (IntegerValue 42)) `shouldBe` "PushOperation 42"
    it "CallOperation should show the correct value" $ do
      show CallOperation `shouldBe` "CallOperation"
    it "ConditionalJumpOperation should show the correct value" $ do
      show (ConditionalJumpOperation 10) `shouldBe` "ConditionalJumpOperation 10"
    it "PushArgumentOperation should show the correct value" $ do
      show (PushArgumentOperation 2) `shouldBe` "PushArgumentOperation 2"
    it "PushEnvironmentOperation should show the correct value" $ do
      show (PushEnvironmentOperation "foo") `shouldBe` "PushEnvironmentOperation \"foo\""
    it "PushVariableOperation should show the correct value" $ do
      show (PushVariableOperation "bar") `shouldBe` "PushVariableOperation \"bar\""
    it "ModifyVariableOperation should show the correct value" $ do
      show (ModifyVariableOperation "baz" (IntegerValue 42)) `shouldBe` "ModifyVariableOperation \"baz\" 42"
    it "ReturnOperation should show the correct value" $ do
      show ReturnOperation `shouldBe` "ReturnOperation"

  describe "NewLangVal" $ do
    it "IntegerValue should show the correct value" $ do
      show (IntegerValue 42) `shouldBe` "42"
    it "TextValue should show the correct value" $ do
      show (TextValue "hello") `shouldBe` "hello"
    it "BoolValue should show the correct value" $ do
      show (BoolValue True) `shouldBe` "True"
    it "BuiltInFunction should show the correct value" $ do
      show (BuiltInFunction AddFunction) `shouldBe` "<BI func> AddFunction"
    it "CustomFunction should show the correct value" $ do
      show (CustomFunction "foo" 2 [PushOperation (IntegerValue 1), PushOperation (IntegerValue 2)]) `shouldBe` "<func> foo <params> 2 <bytecodes> [PushOperation 1,PushOperation 2]"

  describe "NewLangVal" $ do
    it "IntegerValue should be equal to itself" $ do
      IntegerValue 42 `shouldBe` IntegerValue 42
    it "TextValue should be equal to itself" $ do
      TextValue "hello" `shouldBe` TextValue "hello"
    it "BoolValue should be equal to itself" $ do
      BoolValue True `shouldBe` BoolValue True
    it "BuiltInFunction should be equal to itself" $ do
      BuiltInFunction AddFunction `shouldBe` BuiltInFunction AddFunction
    it "CustomFunction should be equal to itself" $ do
      CustomFunction "foo" 2 [PushOperation (IntegerValue 1), PushOperation (IntegerValue 2)] `shouldBe` CustomFunction "foo" 2 [PushOperation (IntegerValue 1), PushOperation (IntegerValue 2)]
