module BinaryTree (BinaryTree) where
  
  data BinaryTree a = BT (BinaryTree a) a (BinaryTree a) | E
    deriving (Show)

  instance Functor BinaryTree where
    fmap f (BT l x r) = BT (fmap f l) (f x) (fmap f r)
    fmap f (E)        = E

  insert :: (Ord a) => BinaryTree a -> a -> BinaryTree a
  insert bt@(BT E x E) x'
    | x >  x' = BT (BT E x' E) x E
    | x <  x' = BT E x (BT E x' E)
    | x == x' = bt
  insert bt@(BT E x r) x'
    | x >  x' = BT (BT E x' E) x' r
    | x <  x' = BT E x (insert r x')
    | x == x' = bt
  insert bt@(BT l x E) x'
    | x >  x' = BT (insert l x') x E
    | x <  x' = BT l x (BT E x' E)
    | x == x' = bt
  insert bt@(BT l x r) x'
    | x >  x' = BT (insert l x') x r
    | x <  x' = BT l x (insert r x')
    | x == x' = bt

  rotate :: BinaryTree a -> BinaryTree a
  rotate (BT (BT (BT _ x'' _) x' _) x _) = undefined -- Note x < x'  < x''
  --     x
  --    /
  --   x'
  --  /
  -- x''
  rotate (BT (BT _ x' (BT _ x'' _)) x _) = undefined -- Note x < x'' < x'
  --   x
  --  /
  -- x'
  --  \
  --   x''
  rotate (BT _ x (BT (BT _ x'' _) x' _)) = undefined -- Note x > x'  > x''
  --   x
  --    \
  --     x'
  --    /
  --   x''
  rotate (BT _ x (BT _ x' (BT _ x'' _))) = undefined -- Note x > x'' > x'
  -- x
  --  \
  --   x'
  --    \ 
  --     x''
