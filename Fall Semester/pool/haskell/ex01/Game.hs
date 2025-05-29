{-
-- EPITECH PROJECT, 2024
** Pool - DAY 03
** File description:
** RPG Simulation
-}
import Data.Maybe (isJust)

data Item = Sword | Bow | MagicWand deriving (Eq)

instance Show Item where
         show Sword = "sword"
         show Bow = "bow"
         show MagicWand = "magic wand"

class ShowMob a where
    showMob :: a -> String
    
instance ShowMob Mob where
    showMob Mummy = "mummy"
    showMob (Skeleton Bow) = "doomed archer"
    showMob (Skeleton Sword) = "dead knight"
    showMob (Skeleton item) = "skeleton holding a " ++ show item
    showMob (Witch Nothing) = "witch"
    showMob (Witch (Just MagicWand)) = "sorceress"
    showMob (Witch (Just item)) = "witch holding a " ++ show item

data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving (Eq, Show)

class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool
    hasItem obj = isJust (getItem obj)

instance HasItem Mob where
    getItem (Skeleton item) = Just item
    getItem (Witch maybeItem) = maybeItem
    getItem Mummy = Nothing

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
create "mummy" = Just createMummy
create "doomed archer" = Just createArcher
create "doomed knight" = Just createKnight
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create _ = error "This string is NOT a MOB"

equip :: Item -> Mob -> Maybe Mob
equip newItem mobToEquip = case mobToEquip of
  Skeleton _ -> Just (Skeleton newItem)
  Witch _    -> Just (Witch (Just newItem))
  Mummy      -> Nothing

data NPC = NPC Item deriving Show

instance HasItem NPC where
    getItem (NPC item) = Just item

data Player = Player Item deriving Show

instance HasItem Player where
    getItem (Player item) = Just item