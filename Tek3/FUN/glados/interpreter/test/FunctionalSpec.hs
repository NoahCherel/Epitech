-- file: test/FunctionalSpec.hs

module FunctionalSpec (spec) where

import Test.Hspec
import System.Process

spec :: Spec
spec = do
  describe "comment" $ do
    it "Doit renvoyer 5" $ do
      let command = "../glados ../examples/comment.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "5\n"

  describe "simple_cal" $ do
    it "Doit renvoyer 5" $ do
      let command = "../glados ../examples/simple_calc.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "5\n"

  describe "simple_cal2" $ do
    it "Doit renvoyer 20" $ do
      let command = "../glados ../examples/simple_calc2.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "20\n"

  describe "simple_cal3" $ do
    it "Doit renvoyer 3" $ do
      let command = "../glados ../examples/simple_calc3.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "3\n"

  describe "simple_cal4" $ do
    it "Doit renvoyer 4" $ do
      let command = "../glados ../examples/simple_calc4.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "5\n"

  describe "simple_foo" $ do
    it "Doit renvoyer 42" $ do
      let command = "../glados ../examples/simple_foo.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "42\n"

  describe "simple_if" $ do
    it "Doit renvoyer \"false\"" $ do
      let command = "../glados ../examples/simple_if.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "false\n"

  describe "simple_if2" $ do
    it "Doit renvoyer \"true\"" $ do
      let command = "../glados ../examples/simple_if2.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "true\n"

  describe "simple_if3" $ do
    it "Doit renvoyer \"true\"" $ do
      let command = "../glados ../examples/simple_if3.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "true\n"

  describe "simple_lambda" $ do
    it "Doit renvoyer 25" $ do
      let command = "../glados ../examples/simple_lambda.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "25\n"

  describe "logic_op" $ do
    it "Doit renvoyer \"#f\"" $ do
      let command = "../glados ../examples/logic_op.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "#f\n"

  describe "logic_op2" $ do
    it "Doit renvoyer \"#t\"" $ do
      let command = "../glados ../examples/logic_op2.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "#t\n"

  describe "logic_op3" $ do
    it "Doit renvoyer \"#f\"" $ do
      let command = "../glados ../examples/logic_op3.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "#f\n"

  describe "list_operation" $ do
    it "Doit renvoyer (1 2 3)" $ do
      let command = "../glados ../examples/list_operation.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "(1 2 3)\n"

  describe "list_operation2" $ do
    it "Doit renvoyer 1" $ do
      let command = "../glados ../examples/list_operation2.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "1\n"

  describe "list_operation3" $ do
    it "Doit renvoyer (2 3)" $ do
      let command = "../glados ../examples/list_operation3.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "(2 3)\n"

  describe "list_operation4" $ do
    it "Doit renvoyer 3" $ do
      let command = "../glados ../examples/list_operation4.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "3\n"

  describe "list_usage" $ do
    it "Doit renvoyer 1" $ do
      let command = "../glados ../examples/list_usage.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "1\n"

  describe "list_usage2" $ do
    it "Doit renvoyer (2 3)" $ do
      let command = "../glados ../examples/list_usage2.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "(2 3)\n"

  describe "foo_in_func" $ do
    it "Doit renvoyer 42" $ do
      let command = "../glados ../examples/foo_in_func.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "42\n"

  describe "foo_in_lambda" $ do
    it "Doit renvoyer 42" $ do
      let command = "../glados ../examples/foo_in_lambda.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "42\n"

  describe "foo_redefine" $ do
    it "Doit renvoyer \"Hello, world!\"" $ do
      let command = "../glados ../examples/foo_redefine.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "\"Hello, world!\"\n"

  describe "lambda_as_function" $ do
    it "Doit renvoyer 16" $ do
      let command = "../glados ../examples/lambda_as_function.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "16\n"

  describe "lambda_conditional" $ do
    it "Doit renvoyer \"small\"" $ do
      let command = "../glados ../examples/lambda_conditional.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "small\n"

  describe "lambda_in_function" $ do
    it "Doit renvoyer 5" $ do
      let command = "../glados ../examples/lambda_in_function.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "5\n"

  describe "lambda_list" $ do
    it "Doit renvoyer 4" $ do
      let command = "../glados ../examples/lambda_list.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "4\n"

  describe "lambda_return_lambda" $ do
    it "Doit renvoyer \"#<procedure>\"" $ do
      let command = "../glados ../examples/lambda_return_lambda.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "#<procedure>\n"

  describe "lambda_multiple_param" $ do
    it "Doit renvoyer 7" $ do
      let command = "../glados ../examples/lambda_multiple_param.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "7\n"

  describe "if_complex_expr" $ do
    it "Doit renvoyer 5" $ do
      let command = "../glados ../examples/if_complex_expr.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "5\n"

  describe "if_variable" $ do
    it "Doit renvoyer \"x-is-seven\"" $ do
      let command = "../glados ../examples/if_variable.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "x-is-seven\n"

  describe "nested_expr_if" $ do
    it "Doit renvoyer 5" $ do
      let command = "../glados ../examples/nested_expr_if.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "5\n"

  describe "nested_if" $ do
    it "Doit renvoyer \"greater-than\"" $ do
      let command = "../glados ../examples/nested_if.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "greater-than\n"

  describe "nested_expr" $ do
    it "Doit renvoyer 11" $ do
      let command = "../glados ../examples/nested_expr.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "11\n"

  describe "nested_expr2" $ do
    it "Doit renvoyer 20" $ do
      let command = "../glados ../examples/nested_expr2.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "20\n"

  describe "nested_expr3" $ do
    it "Doit renvoyer 5" $ do
      let command = "../glados ../examples/nested_expr3.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "5\n"

  describe "string_op" $ do
    it "Doit renvoyer \"Hello, world!\"" $ do
      let command = "../glados ../examples/string_op.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "\"Hello, world!\"\n"

  describe "string_op2" $ do
    it "Doit renvoyer 5" $ do
      let command = "../glados ../examples/string_op2.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "5\n"

  describe "string_op3" $ do
    it "Doit renvoyer 42" $ do
      let command = "../glados ../examples/string_op3.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "42\n"

  describe "define_function" $ do
    it "Doit renvoyer 3628800" $ do
      let command = "../glados ../examples/define_function.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "3628800\n"

  describe "define_list" $ do
    it "Doit renvoyer 10" $ do
      let command = "../glados ../examples/define_list.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "10\n"

  describe "define_var" $ do
    it "Doit renvoyer 8" $ do
      let command = "../glados ../examples/define_var.scm"
      result <- readProcess "bash" ["-c", command] ""
      result `shouldBe` "8\n"
