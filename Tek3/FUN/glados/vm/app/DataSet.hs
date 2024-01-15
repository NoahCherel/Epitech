--
-- EPITECH PROJECT, 2023
-- Untitled (Workspace)
-- File description:
-- DataSet
--

module DataSet (
    DataPile,
    Bytecodes,
    Parameters,
    Environment,
    NamedValues,
    Operation(..),
    NewLangVal(..),
    NewLangFunc(..)
) where

type DataPile = [NewLangVal]
type Bytecodes = [Operation]
type Parameters = [NewLangVal]
type Environment = [(String, (Int, Bytecodes))]
type NamedValues = [(String, NewLangVal)]

data Operation
    = PushOperation NewLangVal
    | CallOperation
    | ConditionalJumpOperation Int
    | PushArgumentOperation Int
    | PushEnvironmentOperation String
    | PushVariableOperation String
    | ModifyVariableOperation String NewLangVal
    | ReturnOperation
    deriving (Show, Eq)

data NewLangVal
    = IntegerValue Int
    | TextValue String
    | BoolValue Bool
    | BuiltInFunction NewLangFunc
    | CustomFunction String Int Bytecodes

data NewLangFunc
    = AddFunction
    | SubFunction
    | MulFunction
    | DivFunction
    | EqqFunction
    | LessFunction
    | NotFunction NewLangFunc
    deriving (Show, Eq)

instance Show NewLangVal where
    show (IntegerValue number) = show number
    show (TextValue s) = s
    show (BoolValue b) = show b
    show (BuiltInFunction number) = "<BI func> " ++ show number
    show (CustomFunction number a p) = "<func> " ++ number ++ " <params> " ++ show a ++ " <bytecodes> " ++ show p

instance Eq NewLangVal where
    (IntegerValue number) == (IntegerValue numberBis) = number == numberBis
    (TextValue s) == (TextValue s') = s == s'
    (BoolValue b) == (BoolValue b') = b == b'
    (BuiltInFunction _) == (BuiltInFunction _) = True
    (CustomFunction number _ _) == (CustomFunction numberBis _ _) = number == numberBis
    _ == _ = False
