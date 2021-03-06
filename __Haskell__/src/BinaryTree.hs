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
  rotate (BT (BT (BT E x'' E) x' E) x E) =  -- Note x < x'  < x''
    BT (BT E x'' E) x' (BT E x E)
  --     x              x'  
  --    / \            / \  
  --   x'  E    ->    x'' x   
  --  / \            / \ / \
  -- x'' E          E  E E  E
  rotate (BT (BT E x' (BT E x'' E)) x E) = -- Note x < x'' < x'
    rotate (BT (BT (BT E x' E) x'' E) x E)
  --     x              x             x''
  --    / \            / \           / \
  --   x'  E    ->    x'' E   ->    x'  x
  --  / \            / \           / \ / \
  -- E   x''        x'  E         E  E E  E
  rotate (BT E x (BT (BT E x'' E) x' E)) = -- Note x > x'  > x''
    rotate (BT E x (BT E x'' (BT E x' E)))
  --     x            x               x''
  --    / \          / \             / \
  --   E   x'   ->  E   x''   ->    x   x'
  --      / \          / \         / \ / \
  --     x'' E        E   x'      E  E E  E
  rotate (BT E x (BT E x' (BT _ x'' _))) = -- Note x > x'' > x'
    (BT (BT E x E) x' (BT E x'' E))
  --     x            x'
  --    / \          / \
  --   E   x'   ->  x   x''
  --      / \      / \ / \ 
  --     E   x''  E  E E  E 
  rotate bintree                         = bintree

  -- balance :: BinaryTree a -> BinaryTree a
  -- balance bt@(BT E _ E) = bt
  -- balance bt = rotate . balance $ bt
