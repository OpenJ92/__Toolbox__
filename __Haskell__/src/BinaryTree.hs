module BinaryTree (BinaryTree) where
  
  data BinaryTree a = BT (BinaryTree a) a (BinaryTree a) | E
    deriving (Show)

  instance Functor BinaryTree where
    fmap f (BT l x r) = BT (fmap f l) (f x) (fmap f r)
    fmap f (E)        = E
