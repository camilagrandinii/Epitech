{-
-- EPITECH PROJECT, 2024
** Pool - DAY 03
** File description:
** Tree Manipulation
-}
data Tree a = Node (Tree a) a (Tree a) | Empty deriving (Show)

instance Functor Tree where
    fmap _ Empty = Empty
    fmap f (Node leftTree value rightTree) =
        Node (fmap f leftTree) (f value) (fmap f rightTree)

instance Foldable Tree where
    foldMap _ Empty = mempty
    foldMap f (Node leftTree value rightTree) =
        foldMap f leftTree <> f value <> foldMap f rightTree

createTree :: Tree a
createTree = Empty

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree value Empty = Node Empty value Empty
addInTree newValue (Node leftTree currentValue rightTree)
    | newValue < currentValue =
        Node (addInTree newValue leftTree) currentValue rightTree
    | otherwise =
        Node leftTree currentValue (addInTree newValue rightTree)

listToTree :: Ord a => [a] -> Tree a
listToTree = foldr addInTree Empty

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node leftTree value rightTree) =
    treeToList leftTree ++ [value] ++ treeToList rightTree

treeSort :: Ord a => [a] -> [a]
treeSort xs = treeToList (foldr addInTree createTree xs)