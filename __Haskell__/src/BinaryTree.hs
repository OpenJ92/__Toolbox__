module BinaryTree (BinaryTree) where
  
  type Height = Int
  type BalenceFactor = Int 
  data AVLTree a = AVLNode BalenceFactor Height (AVLTree a) a (AVLTree a) | E
    deriving (Show)

  data BinaryTree a = BT (BinaryTree a) a (BinaryTree a) | E
    deriving (Show)

  instance Functor BinaryTree where
    fmap f (BT l x r) = BT (fmap f l) (f x) (fmap f r)
    fmap f (E)        = E


  seed :: (Ord a) => a -> BinaryTree a
  seed x = BT E x E

  insert :: (Ord a) => BinaryTree a -> a -> BinaryTree a
  insert bt@(BT E x E) x'
    | x >  x' = BT (seed x') x E
    | x <  x' = BT E x (seed x')
    | x == x' = bt
  insert bt@(BT E x r) x'
    | x >  x' = BT (seed x') x r

    | x <  x' = BT E x (insert r x')
    | x == x' = bt
  insert bt@(BT l x E) x'
    | x >  x' = BT (insert l x') x E
    | x <  x' = BT l x (seed x')

    | x == x' = bt
  insert bt@(BT l x r) x'
    | x >  x' = BT (insert l x') x r
    | x <  x' = BT l x (insert r x')
    | x == x' = bt
  insert E x' = seed x'

  rotate :: BinaryTree a -> BinaryTree a
  rotate (BT (BT (BT l'' x'' r'') x' r') x r) =  -- Note x < x'  < x''
    BT (BT l'' x'' r'') x' (BT r' x r)

  --     x              x'  
  --    / \            / \  
  --   x'  E    ->    x'' x   
  --  / \            / \ / \
  -- x'' E          E  E E  E
  
  rotate (BT (BT l' x' (BT l'' x'' r'')) x r) = -- Note x < x'' < x'
    rotate (BT (BT (BT l' x' l'') x'' r'') x r)
  --     x              x             x''
  --    / \            / \           / \
  --   x'  E    ->    x'' E   ->    x'  x
  --  / \            / \           / \ / \
  -- E   x''        x'  E         E  E E  E

  rotate (BT l x (BT (BT l'' x'' r'') x' r')) = -- Note x > x'  > x''
    rotate (BT l x (BT l'' x'' (BT r'' x' r')))
  --     x            x               x''
  --    / \          / \             / \
  --   E   x'   ->  E   x''   ->    x   x'
  --      / \          / \         / \ / \
  --     x'' E        E   x'      E  E E  E

  rotate (BT l x (BT l' x' (BT l'' x'' r''))) = -- Note x > x'' > x'
    BT (BT l x l') x' (BT l'' x'' r'')
  --     x            x'
  --    / \          / \
  --   E   x'   ->  x   x''
  --      / \      / \ / \ 
  --     E   x''  E  E E  E 

  rotate (BT l x r) = BT (rotate l) x (rotate r)
  rotate E          = error "empty case"
  -- balance :: BinaryTree a -> BinaryTree a
  -- balance bt@(BT E _ E) = bt
  -- balance bt = rotate . balance $ bt
