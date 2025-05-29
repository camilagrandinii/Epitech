{-
-- EPITECH PROJECT, 2024
** Pool - DAY 01
** File description:
** Implementations of Basic Functions
-}
mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg y = y < 0

myAbs :: Int -> Int
myAbs x
    | x < 0 = - x
    | otherwise = x

myMin :: Int -> Int -> Int
myMin x y
    | x < y = x
    | otherwise = y

myMax :: Int -> Int -> Int
myMax x y
    | x > y = x
    | otherwise = y

myTuple :: a -> b -> (a, b)
myTuple x y = (x, y)

myTruple :: a -> b -> c -> (a, b, c)
myTruple x y z = (x, y, z)

myFst :: (a, b) -> a
myFst (x, _) = x

mySnd :: (a, b) -> b
mySnd (_, y) = y

mySwap :: (a, b) -> (b, a)
mySwap (x, y) = (y, x)

myHead :: [a] -> a
myHead [] = error "Empty list, NOT POSSIBLE to retrieve the first element"
myHead (x:_) = x

myTail :: [a] -> [a]
myTail [] = error "Empty list!!!"
myTail (_:x) = x

myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth [] _ = error "Empty list!!!"
myNth (x:xs) 0 = x
myNth (x:xs) n
    | n < 0             = error "Indexes CANNOT be negative!"
    | n >= myLength (x:xs) = error "Index OUT OF BOUNDS!!"
    | otherwise         = myNth xs (n - 1)

myTake :: Int -> [a] -> [a]
myTake _ [] = error "Empty List!!!"
myTake 0 _ = []  
myTake n (x:xs) 
    | n > myLength (x:xs) = (x:xs)
    | otherwise = x : myTake (n-1) xs

myDrop :: Int -> [a] -> [a]
myDrop _ [] = error "Empty List!!!"
myDrop 1 (x:xs) = xs
myDrop n (x:xs)
    | n > myLength (x:xs) = []
    | otherwise = myDrop (n-1) xs

myAppend :: [a] -> [a] -> [a]
myAppend [] [] = []
myAppend [] y = y
myAppend (x:xs) y = x : myAppend xs y

myReverse :: [a] -> [a]
myReverse list = reverseHelper list []

reverseHelper :: [a] -> [a] -> [a]
reverseHelper [] reversed = reversed
reverseHelper (x:xs) reversed = reverseHelper xs (x: reversed)

myInit :: [a] -> [a]
myInit (x:xs)
    | myLength (x:xs) == 0 = error "Empty list!!!"
    | myLength (x:xs) == 1 = []
    | otherwise = x: myInit xs

myLast :: [a] -> a
myLast (x:xs)
    | myLength (x:xs) == 0 = error "Empty list!!!"
    | myLength (x:xs) == 1 = x
    | otherwise = myLast xs

myZip :: [a] -> [b] -> [(a,b)]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys) = (x,y) : myZip xs ys

myUnzip :: [(a,b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x,y):rest) =
 let (xs, ys) = myUnzip rest
 in (x:xs, y:ys)

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []  
myMap f (x:xs) = f x : myMap f xs  

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter bf (x:xs)
    | bf x       = x : myFilter bf xs  
    | otherwise = myFilter bf xs     

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ acc []     = acc  
myFoldl f acc (x:xs) = myFoldl f (f acc x) xs  

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ acc []     = acc  
myFoldr f acc (x:xs) = f x (myFoldr f acc xs)  

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])  
myPartition p (x:xs)
    | p x       = (x : trues, falses)
    | otherwise = (trues, x : falses)
  where
    (trues, falses) = myPartition p xs

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = [] 
myQuickSort p (pivot:xs) =
  myQuickSort p smaller ++ [pivot] ++ myQuickSort p larger
  where
    (smaller, larger) = myPartition (\x -> p x pivot) xs