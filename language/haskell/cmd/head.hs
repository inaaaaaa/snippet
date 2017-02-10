import System.Environment (getArgs)

{-
  $ seq 100 | stack runhaskell head.hs 5
  1
  2
  3
  4
  5
-}

main :: IO()
main = do
  n <- (read :: String -> Int) . head <$> getArgs
  head' n

head' :: Int -> IO()
head' n = do
  c <- lines <$> getContents
  mapM_ putStrLn . take n $ c
