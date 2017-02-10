import Control.Monad
import System.IO

{-
  $ echo foo | stack runhaskell stdin.hs
  foo
-}

main = cat'

cat :: IO()
cat = do
  done <- isEOF
  when (not done) $ do
        line <- getLine
        putStrLn line
        cat

cat' :: IO()
cat' = do
  c <- lines <$> getContents
  mapM_ putStrLn c
