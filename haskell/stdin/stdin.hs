import Control.Applicative
import Control.Monad

{-
  $ cat input.txt
  0 1 2
  3 4 5
  6 7 8
  9 0 1
  $ cat input.txt | stack runhaskell stdin.hs
  [0,1,2]
  [3,4,5]
  [6,7,8]
  [9,0,1]
-}

main = do
  -- 0
  a <- getLine
  let a' = map (read :: String -> Int) . words $ a
  print a'

  -- 1
  b <- fmap ((fmap (read :: String -> Int)) . words) getLine
  print b

  -- 2
  c <- map (read :: String -> Int) . words <$> getLine
  print c

  -- 3
  map (read :: String -> Int) . words <$> getLine >>= print
