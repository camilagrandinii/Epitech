{-
-- EPITECH PROJECT, 2024
-- Pool - DAY 02
-- File description:
-- Operations
-}

import Data.Char (ord)
import Control.Monad (replicateM)
import Data.Char (isDigit)
import System.Environment (getArgs)
import System.Exit (ExitCode (ExitFailure), exitWith)

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem element (listHead:rest)
    | element == listHead = True
    | otherwise = myElem element rest

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv num divisor = Just (num `div` divisor)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing          
safeNth (x:xs) i = if i == 0 then Just x else safeNth xs (i - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc = fmap (+1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing 
myLookup wantedElement ((key, value):rest)
  | wantedElement == key = Just value
  | otherwise = myLookup wantedElement rest

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing _ = Nothing  
maybeDo _ _ Nothing = Nothing 
maybeDo f (Just x) (Just y) = Just (f x y)  

readInt :: [Char] -> Maybe Int
readInt str
  | all isDigit str = Just (read str)  
  | otherwise = Nothing      

getLineLength :: IO Int
getLineLength = do
  line <- getLine
  return (length line)

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >> return (length str) :: IO Int

printBox :: Int -> IO ()
printBox n
  | n <= 0    = return ()  
  | otherwise =
      putStrLn ("+" ++ replicate (n*2) '-' ++ "+") >>
      mapM_ (\_ -> putStrLn $ '|' : replicate (n*2) ' ' ++ "|") [1..(n)] >>
      putStrLn ("+" ++ replicate (n*2) '-' ++ "+")

concatLines :: Int -> IO String
concatLines n
  | n <= 0    = return ""  
  | otherwise = do
      lines <- mapM (\_ -> getLine) [1..n]  
      return $ concat lines

getInt :: IO (Maybe Int)
getInt = do
  input <- getLine
  case reads input of
    [(num, "")] -> return (Just num)
    _           -> return Nothing

calculateResult :: String -> Maybe Int -> Maybe Int -> Maybe Int
calculateResult "+" (Just x) (Just y) = Just (x + y)
calculateResult "-" (Just x) (Just y) = Just (x - y)
calculateResult "*" (Just x) (Just y) = Just (x * y)
calculateResult "/" (Just x) (Just y) = 
  if y /= 0 then Just (x `div` y) else Nothing
calculateResult "%" (Just x) (Just y) = 
  if y /= 0 then Just (x `mod` y) else Nothing
calculateResult _ _ _ = error "Invalid operator or operands"

printingOutputSafe :: Maybe Int -> IO()
printingOutputSafe Nothing = exitWith (ExitFailure 84)
printingOutputSafe (Just x) = print x

main :: IO ()
main = do
    args <- getArgs
    if length args == 3
      then
      printingOutputSafe (calculateResult (head (tail args))
        (readInt (head args)) (readInt (last args)))
    else putStrLn "Usage: doop <num1> <op> <num2>"