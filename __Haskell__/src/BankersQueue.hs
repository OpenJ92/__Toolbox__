{-# LANGUAGE InstanceSigs #-}
module BankersQueue (BankersQueue) where
  import Prelude hiding (head, tail)
  import Queue

  data BankersQueue a = BQ Int [a] Int [a]
    deriving (Show)

  check :: Int -> [a] -> Int -> [a] -> BankersQueue a
  check lenf f lenr r | lenf >= lenr = BQ lenf f lenr r
                      | otherwise = BQ (lenf + lenr) (f ++ reverse r) 0 [] 

  instance Queue BankersQueue where
    empty :: BankersQueue a
    empty = BQ 0 [] 0 []

    isEmpty :: BankersQueue a -> Bool
    isEmpty (BQ lenf f lenr r) = (lenf == 0)

    snoc :: BankersQueue a -> a -> BankersQueue a
    snoc (BQ lenf f lenr r) x = BQ lenf f (lenr + 1) (x : r)

    head :: BankersQueue a -> a
    head (BQ lenf [] lenr r) = error "empty queue"
    head (BQ lenf (x:f) lenr r) = x

    tail :: BankersQueue a -> BankersQueue a
    tail (BQ lenf [] lenr r) = error "empty queue"
    tail (BQ lenf (x:f) lenr r) = BQ (lenf - 1) f lenr r

  instance Functor BankersQueue where
    fmap g (BQ lenf f lenr r) = BQ lenf (fmap g f) lenf (fmap g r)
