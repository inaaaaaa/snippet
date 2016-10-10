import Control.Applicative
import Control.Monad

{-
  $ cat input.txt
  1 2 3
  4 5 6
  7 8 9
  $ cat input.txt | stack runhaskell stdin.hs
  [1,2,3]
  [4,5,6]
  [7,8,9]
-}

main = do
  -- 0
  a <- getLine
  let a' = map (read :: String -> Int) . words $ a
  print a'

  -- 1
  b <- map (read :: String -> Int) . words <$> getLine
  print b

  -- 2
  map (read :: String -> Int) . words <$> getLine >>= print
