{-
-- EPITECH PROJECT, 2023
-- Glados
-- File description:
-- Main.hs
-}

{-# LANGUAGE ExistentialQuantification #-}
{-# LANGUAGE InstanceSigs #-}
{-# HLINT ignore "Use fmap" #-}
{-# OPTIONS_GHC -Wno-overlapping-patterns #-}
{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
{-# OPTIONS_GHC -Wno-incomplete-uni-patterns #-}
{-# OPTIONS_GHC -Wno-orphans #-}
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

module Main (main) where


-- IMPORTS --
import DataSet()
import Control.Monad
import Control.Monad.Except
import Data.Char()
import Data.Functor
import Data.IORef()
import Data.Maybe (isNothing)
import qualified Data.Maybe()
import System.Environment
import System.IO
import System.IO.Error ()
import Text.ParserCombinators.Parsec ()
import DataSet
import ErrorHandling
import Parser
import Env

-- DATA --
data Unpacker = forall a. Eq a => AnyUnpacker (LispVal -> ThrowsError a)

-- MAIN --
main :: IO ()
main = do
  args <- getArgs
  case args of
    [] -> runRepl  -- No arguments, start the REPL
    [filename] -> runFile filename  -- One argument, treat it as a file to execute
    _ -> putStrLn "Usage: ./glados [filename]"

-- Add a new function to run a file
runFile :: String -> IO ()
runFile filename = do
  env <- primitiveBindings >>= flip bindVars [("args", List $ map String [])]
  result <- runIOThrows (liftM show $ eval env (List [Atom "load", String filename]))
  putStrLn result-- HELPERS --

runRepl :: IO ()
runRepl = primitiveBindings >>= until_ (== "quit") (readPrompt "> ") . evalAndPrint

runIOThrows :: IOThrowsError String -> IO String
runIOThrows action = runExceptT (trapError action) <&> extractValue

flushStr :: String -> IO ()
flushStr str = putStr str >> hFlush stdout

evalAndPrint :: Env -> String -> IO ()
evalAndPrint env expr = do
  result <- evalString env expr
  when (not $ null result) $ putStrLn result

readPrompt :: String -> IO String
readPrompt prompt = do
  flushStr prompt
  end <- isEOF
  if end
    then return "quit"
    else getLine

evalString :: Env -> String -> IO String
evalString env expr = runIOThrows $ liftM show $ liftThrows (readExpr expr) >>= eval env

until_ :: Monad m => (a -> Bool) -> m a -> (a -> m ()) -> m ()
until_ _pred prompt action = do
  result <- prompt
  if _pred result
    then return ()
    else action result >> until_ _pred prompt action

-- EVALUATOR --
eval :: Env -> LispVal -> IOThrowsError LispVal
eval _ val@(String _) = return val -- string
eval _ val@(Number _) = return val -- number
eval _ val@(Bool _) = return val -- boolean
eval env (Atom _id) = getVar env _id -- atomic Value
eval _ (List [Atom "quote", val]) = return val -- quote keyword
eval env (List [Atom "if", _pred, conseq, alt]) =
  -- if statement
  do
    result <- eval env _pred
    case result of
      Bool False -> eval env alt
      _ -> eval env conseq
eval env (List [Atom "set!", Atom var, form]) =
  -- set! keyword
  eval env form >>= setVar env var
eval env (List [Atom "define", Atom var, form]) =
  -- define variable
  eval env form >>= defineVar env var
eval env (List (Atom "define" : List (Atom var : _params) : _body)) =
  -- define function
  makeNormalFunc env _params _body >>= defineVar env var
eval env (List (Atom "define" : DottedList (Atom var : _params) varargs : _body)) =
  -- define function w/ varargs
  makeVarArgs varargs env _params _body >>= defineVar env var
eval env (List (Atom "lambda" : List _params : _body)) =
  -- define function
  makeNormalFunc env _params _body
eval env (List (Atom "lambda" : DottedList _params varargs : _body)) =
  -- define function w/ params + varargs
  makeVarArgs varargs env _params _body
eval env (List (Atom "lambda" : varargs@(Atom _) : _body)) =
  -- define function w/ varargs
  makeVarArgs varargs env [] _body
eval env (List [Atom "load", String filename]) =
  load filename >>= liftM last . mapM (eval env)
eval env (List [Atom "and", _preds]) =
  -- and operator
  evalAnd env _preds
eval env (List [Atom "or", _preds]) =
  -- or operator
  evalOr env _preds
eval env (List [Atom "not", _preds]) =
  -- not operator
  evalNot env _preds
eval env (List [Atom "begin", List expressions]) = do
  evalBegin env expressions  -- Handle 'begin' special form

eval env (List (function : args)) = do
  -- function execution
  func <- eval env function
  argVals <- mapM (eval env) args
  apply func argVals
eval _ badForm = throwError $ BadSpecialForm "Unrecognized special form" badForm

evalBegin :: Env -> [LispVal] -> IOThrowsError LispVal
evalBegin _ [] = throwError $ BadSpecialForm "No expressions in 'begin'" LispVoid
evalBegin env [expr] = eval env expr
evalBegin env (expr : rest) = do
  _ <- eval env expr
  evalBegin env rest

-- Helper function for 'and' operator
evalAnd :: Env -> LispVal -> IOThrowsError LispVal
evalAnd _ (List []) = return $ Bool True  -- (and) evaluates to true
evalAnd env (List (_pred : preds)) = do
  result <- eval env _pred
  case result of
    Bool False -> return $ Bool False  -- Short-circuit on False
    _ -> evalAnd env (List preds)  -- Continue evaluating predicates
evalAnd _ _ = throwError $ BadSpecialForm "Malformed 'and' expression" (List [])

-- Helper function for 'or' operator
evalOr :: Env -> LispVal -> IOThrowsError LispVal
evalOr _ (List []) = return $ Bool False  -- (or) evaluates to false
evalOr env (List (_pred : preds)) = do
  result <- eval env _pred
  case result of
    Bool True -> return $ Bool True  -- Short-circuit on True
    _ -> evalOr env (List preds)  -- Continue evaluating predicates
evalOr _ _ = throwError $ BadSpecialForm "Malformed 'or' expression" (List [])

-- Helper function for 'not' operator
evalNot :: Env -> LispVal -> IOThrowsError LispVal
evalNot env _pred = do
  result <- eval env _pred
  case result of
    Bool b -> return $ Bool (not b)
    _ -> throwError $ TypeMismatch "boolean" _pred

apply :: LispVal -> [LispVal] -> IOThrowsError LispVal
apply (PrimitiveFunc func) args = liftThrows $ func args
apply (Func _params varargs _body _closure) args =
  if num _params /= num args && isNothing varargs
    then throwError $ NumArgs (num _params) args
    else liftIO (bindVars _closure $ zip _params args) >>= bindVarArgs varargs >>= evalBody
  where
    remainingArgs = drop (length _params) args
    num = toInteger . length
    evalBody env = liftM last $ mapM (eval env) _body
    bindVarArgs arg env = case arg of
      Just argName -> liftIO $ bindVars env [(argName, List remainingArgs)]
      Nothing -> return env
apply (IOFunc func) args = func args
apply _ _= return LispVoid

makeFunc :: Monad m => Maybe String -> Env -> [LispVal] -> [LispVal] -> m LispVal
makeFunc varargs env _params _body = return $ Func (map showVal _params) varargs _body env

makeNormalFunc :: Env -> [LispVal] -> [LispVal] -> ExceptT LispError IO LispVal
makeNormalFunc = makeFunc Nothing

makeVarArgs :: LispVal -> Env -> [LispVal] -> [LispVal] -> ExceptT LispError IO LispVal
makeVarArgs = makeFunc . Just . showVal

-- PRIMITIVES --
primitives :: [(String, [LispVal] -> ThrowsError LispVal)]
primitives =
  [ ("+", numericBinop (+)),
    ("-", numericBinop (-)),
    ("*", numericBinop (*)),
    ("/", numericBinop div),
    ("div", numericBinop div),
    ("mod", numericBinop mod),
    ("quotient", numericBinop quot),
    ("remainder", numericBinop rem),
    ("=", numBoolBinop (==)),
    ("<", numBoolBinop (<)),
    (">", numBoolBinop (>)),
    ("/=", numBoolBinop (/=)),
    (">=", numBoolBinop (>=)),
    ("<=", numBoolBinop (<=)),
    ("&&", boolBoolBinop (&&)),
    ("||", boolBoolBinop (||)),
    ("string=?", strBoolBinop (==)),
    ("string<?", strBoolBinop (<)),
    ("string>?", strBoolBinop (>)),
    ("string>=?", strBoolBinop (>=)),
    ("string<=?", strBoolBinop (<=)),
    ("string/=?", strBoolBinop (/=)),
    ("car", car),
    ("cdr", cdr),
    ("cons", cons),
    ("eq?", eqv),
    ("eqv?", eqv),
    ("equal?", equal),
    ("and", boolBoolBinop (&&)),
    ("or", boolBoolBinop (||)),
    ("length", lengthFunc),
    ("string-append", stringAppend),
    ("display", display),
    ("string-length", stringLength),
    ("string->number", stringToNumber),
    ("null?", isNull)
  ]

ioPrimitives :: [(String, [LispVal] -> IOThrowsError LispVal)]
ioPrimitives =
  [ ("apply", applyProc),
    ("open-input-file", makePort ReadMode),
    ("open-output-file", makePort WriteMode),
    ("close-input-port", closePort),
    ("close-output-port", closePort),
    ("read", readProc),
    ("write", writeProc),
    ("read-contents", readContents),
    ("read-all", readAll)
  ]

primitiveBindings :: IO Env
primitiveBindings =
  nullEnv
    >>= flip
      bindVars
      ( map (_makeFunc IOFunc) ioPrimitives
          ++ map (_makeFunc PrimitiveFunc) primitives
      )
  where
    _makeFunc constructor (var, func) = (var, constructor func)

-- PRIMITIVE FUNCTIONS --
car :: [LispVal] -> ThrowsError LispVal
car [List (x : _)] = return x
car [DottedList (x : _) _] = return x
car [badArg] = throwError $ TypeMismatch "pair" badArg
car badArgList = throwError $ NumArgs 1 badArgList

cdr :: [LispVal] -> ThrowsError LispVal
cdr [List (_ : xs)] = return $ List xs
cdr [DottedList [_] xs] = return xs
cdr [DottedList (_ : xs) x] = return $ DottedList xs x
cdr [badArg] = throwError $ TypeMismatch "pair" badArg
cdr badArgList = throwError $ NumArgs 1 badArgList

cons :: [LispVal] -> ThrowsError LispVal
cons [x1, List []] = return $ List [x1]
cons [x, List xs] = return $ List $ x : xs
cons [x, DottedList xs xlast] = return $ DottedList (x : xs) xlast
cons [x1, x2] = return $ DottedList [x1] x2
cons badArgList = throwError $ NumArgs 2 badArgList

eqv :: [LispVal] -> ThrowsError LispVal
eqv [Bool arg1, Bool arg2] = return $ Bool $ arg1 == arg2
eqv [Number arg1, Number arg2] = return $ Bool $ arg1 == arg2
eqv [String arg1, String arg2] = return $ Bool $ arg1 == arg2
eqv [Atom arg1, Atom arg2] = return $ Bool $ arg1 == arg2
eqv [DottedList xs x, DottedList ys y] = eqv [List $ xs ++ [x], List $ ys ++ [y]]
eqv [List arg1, List arg2] =
  return $ Bool $ (length arg1 == length arg2) && all eqvPair (zip arg1 arg2)
  where
    eqvPair (x1, x2) = case eqv [x1, x2] of
      Left _ -> False -- Unreachable code
      Right (Bool val) -> val
eqv [_, _] = return $ Bool False
eqv badArgsList = throwError $ NumArgs 2 badArgsList

equal :: [LispVal] -> ThrowsError LispVal
equal [arg1, arg2] = do
  primitiveEquals <-
    liftM or $
      mapM
        (unpackEquals arg1 arg2)
        [AnyUnpacker unpackNum, AnyUnpacker unpackStr, AnyUnpacker unpackBool]
  eqvEquals <- eqv [arg1, arg2]
  return $ Bool (primitiveEquals || let (Bool x) = eqvEquals in x)
equal badArgList = throwError $ NumArgs 2 badArgList

lengthFunc :: [LispVal] -> ThrowsError LispVal
lengthFunc [List xs] = return $ Number (toInteger (length xs))
lengthFunc [notList] = throwError $ TypeMismatch "list" notList
lengthFunc args = throwError $ NumArgs 1 args

stringAppend :: [LispVal] -> ThrowsError LispVal
stringAppend args = do
  -- Check that all arguments are strings
  strings <- mapM unpackStr args
  return $ String (concat strings)

display :: [LispVal] -> ThrowsError LispVal
display [val] = return $ String (showVal val)
display args = throwError $ NumArgs 1 args  -- Display takes exactly 1 argument

stringLength :: [LispVal] -> ThrowsError LispVal
stringLength [String s] = return $ Number (toInteger (length s))
stringLength [badArg] = throwError $ TypeMismatch "string" badArg
stringLength badArgList = throwError $ NumArgs 1 badArgList

stringToNumber :: [LispVal] -> ThrowsError LispVal
stringToNumber [String s] =
  case reads s of
    [(num, _)] -> return $ Number num
    _ -> throwError $ TypeMismatch "number" (String s)
stringToNumber [badArg] = throwError $ TypeMismatch "string" badArg
stringToNumber badArgList = throwError $ NumArgs 1 badArgList

isNull :: [LispVal] -> ThrowsError LispVal
isNull [List []] = return $ Bool True
isNull [_] = return $ Bool False
isNull badArgs = throwError $ NumArgs 1 badArgs

-- IO FUNCTIONS --
applyProc :: [LispVal] -> IOThrowsError LispVal
applyProc [func, List args] = apply func args
applyProc (func : args) = apply func args
applyProc args = throwError $ NumArgs 2 args

makePort :: IOMode -> [LispVal] -> IOThrowsError LispVal
makePort mode [String filename] = liftM Port $ liftIO $ openFile filename mode
makePort _ args = throwError $ NumArgs 1 args

closePort :: [LispVal] -> IOThrowsError LispVal
closePort [Port port] = liftIO $ hClose port >> return (Bool True)
closePort _ = return (Bool False)

readProc :: [LispVal] -> IOThrowsError LispVal
readProc [] = readProc [Port stdin]
readProc [Port port] = liftIO (hGetLine port) >>= liftThrows . readExpr
readProc args = throwError $ NumArgs 1 args

writeProc :: [LispVal] -> IOThrowsError LispVal
writeProc [obj] = writeProc [obj, Port stdout]
writeProc [obj, Port port] = liftIO $ hPrint port obj >> return (Bool True)
writeProc args = throwError $ NumArgs 1 args

readContents :: [LispVal] -> IOThrowsError LispVal
readContents [String fileName] = liftM String $ liftIO $ readFile fileName
readContents args = throwError $ NumArgs 1 args

load :: String -> IOThrowsError [LispVal]
load filename = liftIO (readFile filename) >>= liftThrows . readExprList

readAll :: [LispVal] -> IOThrowsError LispVal
readAll [String filename] = liftM List $ load filename
readAll args = throwError $ NumArgs 1 args

numericBinop :: (Integer -> Integer -> Integer) -> [LispVal] -> ThrowsError LispVal
numericBinop _ [] = throwError $ NumArgs 2 []
numericBinop _ singleVal@[_] = throwError $ NumArgs 2 singleVal
numericBinop op _params = mapM unpackNum _params Data.Functor.<&> (Number . foldl1 op)

boolBinop :: (LispVal -> ThrowsError a) -> (a -> a -> Bool) -> [LispVal] -> ThrowsError LispVal
boolBinop unpacker op args =
  if length args /= 2
    then throwError $ NumArgs 2 args
    else do
      left <- unpacker $ head args
      right <- unpacker $ args !! 1
      return $ Bool $ left `op` right

numBoolBinop :: (Integer -> Integer -> Bool) -> [LispVal] -> ThrowsError LispVal
numBoolBinop = boolBinop unpackNum

strBoolBinop :: (String -> String -> Bool) -> [LispVal] -> ThrowsError LispVal
strBoolBinop = boolBinop unpackStr

boolBoolBinop :: (Bool -> Bool -> Bool) -> [LispVal] -> ThrowsError LispVal
boolBoolBinop = boolBinop unpackBool

-- UNPACKERS --
unpackEquals :: LispVal -> LispVal -> Unpacker -> ThrowsError Bool
unpackEquals arg1 arg2 (AnyUnpacker unpacker) =
  do
    unpacked1 <- unpacker arg1
    unpacked2 <- unpacker arg2
    return $ unpacked1 == unpacked2
    `catchError` const (return False)

unpackNum :: LispVal -> ThrowsError Integer
unpackNum (Number n) = return n
unpackNum (String s) =
  let parsed = reads s
   in if null parsed
        then throwError $ TypeMismatch "number" $ String s
        else return $ fst $ head parsed
unpackNum (List [n]) = unpackNum n
unpackNum notNum = throwError $ TypeMismatch "number" notNum

unpackStr :: LispVal -> ThrowsError String
unpackStr (String s) = return s
unpackStr (Number n) = return $ show n
unpackStr (Bool b) = return $ show b
unpackStr notString = throwError $ TypeMismatch "string" notString

unpackBool :: LispVal -> ThrowsError Bool
unpackBool (Bool b) = return b
unpackBool notBool = throwError $ TypeMismatch "boolean" notBool

-- SHOW VALUES --
instance Show LispVal where show = showVal

showVal :: LispVal -> String
showVal (String contents) = "\"" ++ contents ++ "\""
showVal LispVoid = ""
showVal (Atom name) = name
showVal (Number num) = show num
showVal (Bool True) = "#t"
showVal (Bool False) = "#f"
showVal (List contents) = "(" ++ unwordsList contents ++ ")"
showVal (DottedList _head _tail) = "(" ++ unwordsList _head ++ " . " ++ showVal _tail ++ ")"
showVal (PrimitiveFunc _) = "<primitive>"
showVal (Func {}) =
  "#<procedure>"
showVal (IOFunc _) = "<IO primitive>"
showVal (Port _) = "<IO port>"

unwordsList :: [LispVal] -> String
unwordsList = unwords . map showVal

-- SHOW ERRORS --
instance Show LispError where
  show :: LispError -> String
  show = showError

showError :: LispError -> String
showError (UnboundVar message varName message2) = message ++ varName ++ message2
showError (BadSpecialForm message form) = message ++ ": " ++ show form
showError (NotFunction message func) = message ++ ": " ++ show func
showError (NumArgs expected found) = "Expected " ++ show expected ++ " args, found values " ++ unwordsList found
showError (TypeMismatch expected found) = "Invalid type, expected " ++ expected ++ ", found " ++ show found
showError (Parser err) = "Parse error at " ++ show err
showError _ = "Unknown error"
