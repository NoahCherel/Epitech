--
-- EPITECH PROJECT, 2023
-- vm
-- File description:
-- FunctionsHandler
--

module VirtualMachine (
    additionFunction,
    substractionFunction,
    multiplicationFunction,
    divisionFunction,
    equalFunction,
    lesserThanFunction,
    notFunction,
    callFunction,
    applyBuiltInFunction,
    interpretBytecodes,
    getParams
) where

import DataSet

-- | This function takes the top two elements of the stack, adds them together and pushes the result back onto the stack.
additionFunction :: DataPile -> Either String DataPile
additionFunction (IntegerValue x : IntegerValue y : xs) = Right $ IntegerValue (x + y) : xs
additionFunction _ = error "Incorrect Parameters values for additionFunction"

-- | This function performs a substraction operation on the top two elements of the data pile.
-- If the top two elements are integers, it returns the result of the substraction as a new integer value.
-- If the data pile does not contain at least two integer values, it returns an error message.
substractionFunction :: DataPile -> Either String DataPile
substractionFunction (IntegerValue x:IntegerValue y:xs) = Right $ IntegerValue (x - y) : xs
substractionFunction _ = error "Incorrect Parameters values for substractionFunction"

-- | Given a number and a list of data, returns the first `number` elements of the list as a `Parameters` list.
-- If the number is 0 or the list is empty, an empty list is returned.
getParams :: Int -> DataPile -> Parameters
getParams 0 _ = []
getParams _ [] = []
getParams number (x:xs)
    | number > 0 = x : getParams (number - 1) xs
    | otherwise = []

-- | This function takes a DataPile and multiplies the first two IntegerValues in the list.
-- If the list does not contain at least two IntegerValues, it returns an error message.
multiplicationFunction :: DataPile -> Either String DataPile
multiplicationFunction (IntegerValue x:IntegerValue y:xs) = Right $ IntegerValue (x * y) : xs
multiplicationFunction _ = error "Incorrect Parameters values for multiplicationFunction"

-- | This function performs division operation on the top two elements of the stack.
-- If the second element is zero, it returns an error message.
-- If the top two elements are not integers, it returns an error message.
divisionFunction :: DataPile -> Either String DataPile
divisionFunction (IntegerValue 0:_) = error "Division by zero"
divisionFunction (IntegerValue x:IntegerValue y:xs) = Right $ IntegerValue (y `Prelude.div` x) : xs
divisionFunction _ = error "Incorrect Parameters values for div"

-- | Applies a function to the data pile.
-- If the function is a built-in function, it applies it directly.
-- If the function is a custom function, it interprets its bytecodes with the given environment and named values.
-- Returns either an error message or the updated data pile.
--callFunction :: NamedValues -- ^ The named values in the current scope.
--             -> Environment -- ^ The environment in which the function is called.
--             -> NewLangVal -- ^ The function to call.
--             -> DataPile -- ^ The data pile to apply the function to.
--             -> Either String DataPile -- ^ Either an error message or the updated data pile.
callFunction :: NamedValues -> Environment -> NewLangVal -> DataPile -> Either String DataPile
callFunction _ _ (BuiltInFunction op) s = applyBuiltInFunction op s
callFunction namedValues environment (CustomFunction _ a p) (x:xs) =
    case interpretBytecodes (getParams a (x:xs)) environment namedValues p [] of
        Left errorValue -> Left errorValue
        Right result -> Right (result : xs)
callFunction _ _ _ _ = error "Incorrect callFunction"

-- | This function takes two values from the top of the data pile and checks if they are equal.
-- | If they are of different types, an error is thrown.
-- | If they are of the same type, a boolean value is pushed onto the data pile indicating whether they are equal or not.
equalFunction :: DataPile -> Either String DataPile
equalFunction (IntegerValue x:IntegerValue y:xs) = Right $ BoolValue (x == y) : xs
equalFunction (BoolValue x:BoolValue y:xs) = Right $ BoolValue (x == y) : xs
equalFunction (TextValue x:TextValue y:xs) = Right $ BoolValue (x == y) : xs
equalFunction _ = error "Incorrect Parameters values for eq?"

-- | This function takes two values from the top of the DataPile and returns a Boolean value indicating whether the second value is less than the first value. If the values are not of the same type or if there are not enough values in the DataPile, an error is thrown.
lesserThanFunction :: DataPile -> Either String DataPile
lesserThanFunction (IntegerValue x:IntegerValue y:xs) = Right $ BoolValue (y < x) : xs
lesserThanFunction (TextValue x:TextValue y:xs) = Right $ BoolValue (y < x) : xs
lesserThanFunction _ = error "Incorrect Parameters values for lesserThanFunction"

-- | This function takes a boolean value and returns its negation.
--
nnotBis :: Bool -> Bool
nnotBis False = True
nnotBis True = False

-- | Applies the logical NOT operation to the first boolean value in the input DataPile.
-- If the function is called with an invalid NewLangFunc, an error message is returned.
-- notFunction :: NewLangFunc -- ^ The function to be applied.
--           -> DataPile -- ^ The input DataPile.
--            -> Either String DataPile -- ^ The result of the operation or an error message.
notFunction :: NewLangFunc -> DataPile -> Either String DataPile
notFunction b s
    | b == EqqFunction = case equalFunction s of
        Left errorValue -> error errorValue
        Right ((BoolValue bo):xs) -> Right $ BoolValue (nnotBis bo) : xs
        _ -> error "Incorrect Parameters values for not"
    | b == LessFunction = case lesserThanFunction s of
        Left errorValue -> error errorValue
        Right ((BoolValue bo):xs) -> Right $ BoolValue (nnotBis bo) : xs
        _ -> error "Incorrect Parameters values for not"
    | otherwise = error "Incorrect Parameters values for not"

-- | Applies a built-in function to a data pile.
--
-- The function takes a 'NewLangFunc' and a 'DataPile' as input and returns an 'Either' type with a 'String' error message or a new 'DataPile'.
--
-- * 'AddFunction': applies the addition function to the data pile.
-- * 'SubFunction': applies the substraction function to the data pile.
-- * 'MulFunction': applies the multiplication function to the data pile.
-- * 'DivFunction': applies the division function to the data pile.
-- * 'EqqFunction': applies the equal function to the data pile.
-- * 'LessFunction': applies the lesser than function to the data pile.
-- * 'NotFunction': applies the not function to a boolean value in the data pile.
applyBuiltInFunction :: NewLangFunc -> DataPile -> Either String DataPile
applyBuiltInFunction AddFunction s = additionFunction s
applyBuiltInFunction SubFunction s = substractionFunction s
applyBuiltInFunction MulFunction s = multiplicationFunction s
applyBuiltInFunction DivFunction s = divisionFunction s
applyBuiltInFunction EqqFunction s = equalFunction s
applyBuiltInFunction LessFunction s = lesserThanFunction s
applyBuiltInFunction (NotFunction b) s = notFunction b s

-- | This function interprets a list of bytecodes and returns the result of the computation.
-- It takes in parameters, an environment, a list of named values, a list of bytecodes, and a data pile.
-- It returns either an error message or a new language value.
interpretBytecodes :: Parameters -> Environment -> NamedValues -> Bytecodes -> DataPile -> Either String NewLangVal
interpretBytecodes params environment namedValues ((PushOperation val):bytecodes) stack = interpretBytecodes params environment namedValues bytecodes (val : stack)
interpretBytecodes params environment namedValues ((PushArgumentOperation index):bytecodes) stack = interpretBytecodes params environment namedValues bytecodes ((params !! index) : stack)
interpretBytecodes params environment namedValues ((PushEnvironmentOperation index):bytecodes) stack = case lookup index environment of
    Just (arity, program) -> interpretBytecodes params environment namedValues bytecodes (CustomFunction index arity program : stack)
    _ -> error "Incorrect environment"
interpretBytecodes params environment namedValues ((PushVariableOperation index):bytecodes) stack = case lookup index namedValues of
    Just val -> interpretBytecodes params environment namedValues bytecodes (val : stack)
    _ -> error "Incorrect push variable"
interpretBytecodes params environment namedValues ((ModifyVariableOperation index val):bytecodes) stack = interpretBytecodes params environment (changeNamedValues namedValues index val) bytecodes stack
interpretBytecodes params environment namedValues (CallOperation:bytecodes) (val:stack) = case callFunction namedValues environment val stack of
    Left errorValue -> error errorValue
    Right newStack -> interpretBytecodes params environment namedValues bytecodes newStack
interpretBytecodes params environment namedValues ((ConditionalJumpOperation index):bytecodes) (BoolValue False:stack) = interpretBytecodes params environment namedValues (drop index bytecodes) stack
interpretBytecodes params environment namedValues ((ConditionalJumpOperation _):bytecodes) (_:stack) = interpretBytecodes params environment namedValues bytecodes stack
interpretBytecodes _ _ _ (ReturnOperation:_) (val:_) = Right val
interpretBytecodes _ _ _ _ _ = error "Incorrect Bytecodes"


-- | Updates the value of a named variable in a list of named values.
-- If the variable is not found, the list is returned unchanged.
changeNamedValues :: NamedValues -> String -> NewLangVal -> NamedValues
changeNamedValues [] _ _ = []
changeNamedValues ((name, _):xs) name' nvalue
    | name == name' = (name, nvalue) : xs
    | otherwise = (name, nvalue) : changeNamedValues xs name' nvalue
