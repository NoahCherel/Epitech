{-
-- EPITECH PROJECT, 2023
-- Game.hs
-- File description:
-- Day 3
-}

data Item = Sword | Bow | MagicWand
    deriving (Eq)

instance Show Item where
    show Sword   = "sword"
    show Bow     = "bow"
    show MagicWand = "magic wand"

data Mob = Mummy | Skeleton Item | Witch (Maybe Item)
    deriving (Eq)

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create str =
    case str of
        "mummy"         -> Just Mummy
        "doomed archer" -> Just (Skeleton Bow)
        "dead knight"   -> Just (Skeleton Sword)
        "witch"         -> Just (Witch Nothing)
        "sorceress"     -> Just (Witch (Just MagicWand))
        _               -> Nothing

equip :: Item -> Mob -> Maybe Mob
equip item mob =
    case mob of
        Skeleton _ -> Just (Skeleton item)
        Witch _    -> Just (Witch (Just item))
        _          -> Nothing

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton item) = "skeleton holding a " ++ show item
    show (Witch Nothing) = "witch"
    show (Witch ( Just MagicWand)) = "sorceress"
    show (Witch (Just item)) = "witch holding a " ++ show item

class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool

instance HasItem Mob where
    getItem mob =
        case mob of
            Skeleton item -> Just item
            Witch item    -> item
            _             -> Nothing
    hasItem mob =
        case mob of
            Skeleton _ -> True
            Witch _    -> True
            _          -> False