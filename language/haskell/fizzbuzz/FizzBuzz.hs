-- type level fizzbuzz

module FizzBuzz where

data Nat = Zero | Succ Nat | Fizz | Buzz | FizzBuzz deriving (Eq, Show, Ord)

instance Num Nat where
    (+)         n    m = foldn Succ n m
    (*)         n    m = foldn (+ n) Zero m
    (-)         Zero m = Zero
    (-)         n    m = foldn (\(Succ s) -> s) n m
    negate      n      = Zero
    abs         n      = n
    signum      Zero   = Zero
    signum      n      = Succ Zero
    fromInteger n      = iterate Succ Zero !! (fromInteger n)

to30 :: [Nat]
to30 = take 30 $ map fizzbuzz natList

fizzbuzz :: Nat -> Nat
fizzbuzz n
    | n % fifteen == Zero = FizzBuzz
    | n % three   == Zero = Fizz
    | n % five    == Zero = Buzz
    | otherwise           = n

natList :: [Nat]
natList = iterate Succ one

one, three, five, fifteen :: Nat
one     = Succ Zero
three   = Succ (Succ (Succ Zero))
five    = Succ (Succ (Succ (Succ (Succ Zero))))
fifteen = three * five

foldn :: (a -> a) -> a -> Nat -> a
foldn h c Zero     = c
foldn h c (Succ n) = h (foldn h c n)

(%) :: Nat -> Nat -> Nat
(%) n Zero = error "div by zero"
(%) n m
    | n < m     = n
    | otherwise = (n - m) % m

main :: IO()
main = do
  putStrLn "***print fizzbuzz 1 to 30"
  mapM_ print to30
