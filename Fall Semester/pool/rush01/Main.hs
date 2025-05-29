{-
-- EPITECH PROJECT, 2024
-- Pool - RUSH 01
-- File description:
-- Pushswap Checker
-}

import System.Environment
import Data.Char (isLower)
import Data.List (sort)
import System.Exit (exitWith, ExitCode(..))


mySwap :: [Int] -> [Int]
mySwap [] = []
mySwap (x1:x2:xs) = x2 : x1 : xs

myPush :: [Int] -> [Int] -> ([Int], [Int])
myPush [] list = ([], list)
myPush (x:xs) list = (xs, x : list)

myRotateTB :: [Int] -> [Int]
myRotateTB [] = []
myRotateTB (x:xs) = (xs) ++ [x]

myRotateTE :: [Int] -> [Int]
myRotateTE [] = []
myRotateTE x = last x : init x

myDoubleRotateTE :: [Int] -> [Int] -> [[Int]]
myDoubleRotateTE [] [] = []
myDoubleRotateTE l1 l2 = [myRotateTE l1, myRotateTE l2]

myDoubleRotateTB :: [Int] -> [Int] -> [[Int]]
myDoubleRotateTB [] [] = []
myDoubleRotateTB l1 l2 = [myRotateTB l1, myRotateTB l2]

myDoubleSwap :: [Int] -> [Int] -> [[Int]]
myDoubleSwap [] [] = []
myDoubleSwap (fp:sp:tp) (fp2:sp2:tp2) 
    = [mySwap (fp:sp:tp), mySwap (fp2:sp2:tp2)]

myOperations :: [String] -> [Int] -> [Int] -> IO [[Int]]
myOperations [] l1 l2 = return [l1, l2]
myOperations (x:xs) l_a l_b = case x of
    "sa" -> myOperations xs (mySwap l_a) l_b
    "sb" -> myOperations xs l_a (mySwap l_b)
    "sc" -> case myDoubleSwap l_a l_b of
                [l1', l2'] -> myOperations xs l1' l2'
                _ -> error "X"
    "pa" -> let (result2, result1) = myPush l_b l_a  
            in myOperations xs result1 result2  
    "pb" -> let (result1, result2) = myPush l_a l_b  
            in myOperations xs result1 result2  
    "ra" -> myOperations xs (myRotateTB l_a) l_b
    "rb" -> myOperations xs l_a (myRotateTB l_b)
    "rr" -> case myDoubleRotateTB l_a l_b of
                [l1', l2'] -> myOperations xs l1' l2'
                _ -> error "X"
    "rra" -> myOperations xs (myRotateTE l_a) l_b
    "rrb" -> myOperations xs l_a (myRotateTE l_b)
    "rrr" -> case myDoubleRotateTE l_a l_b of
                [l1', l2'] -> myOperations xs l1' l2'
                _ -> error "X"
    _  -> exitWith (ExitFailure 84)

isSorted :: [Int] -> [Int] -> Bool
isSorted [] [] = True
isSorted xs ys = xs == sort xs && null ys

safeRead :: String -> IO Int
safeRead s = case reads s of
    [(x, "")] -> return x
    _ -> exitWith (ExitFailure 84)

main :: IO ()
main = do
    list <- getArgs
    operations <- getLine
    
    let intList = mapM safeRead list :: IO [Int]
        operationList = map (filter isLower) (words operations)
        
    ints <- intList
    result <- myOperations operationList ints []

    if isSorted (head result) (last result) then
        putStrLn "OK"
    else
        putStrLn "KO"
    return ()