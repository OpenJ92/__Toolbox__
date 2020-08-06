{-# LANGUAGE InstanceSigs #-}
module BatchedQueue (BatchedQueue) where
  import Prelude hiding (head, tail)
  import Queue

  data BatchedQueue a = BQ [a] [a]
    deriving (Show)

  check :: [a] -> [a] -> BatchedQueue a
  check [] r = BQ (reverse r) []
  check f  r = BQ f r

  instance Queue BatchedQueue where
    empty :: BatchedQueue a
    empty = BQ [] []
    
    isEmpty :: BatchedQueue a -> Bool
    isEmpty (BQ f r) = null f

    snoc :: BatchedQueue a -> a -> BatchedQueue a
    snoc (BQ f r) x = check f (x : r)

    head :: BatchedQueue a -> a
    head (BQ [] _) = error "empty queue"
    head (BQ (x:f) _) = x

    tail :: BatchedQueue a -> BatchedQueue a
    tail (BQ [] _) = error "empty queue" 
    tail (BQ (x:f) r) = check f r

  instance Functor BatchedQueue where
    fmap g (BQ f r) = BQ (fmap g f) (fmap g r)
