-- list monad

bind :: [a] -> (a -> [b]) -> [b]
bind xs f = foldr ((++) . f) [] xs

return' :: a -> [a]
return' x = [x]

main = do
  print $ [1..3] `bind` \x -> "abc" `bind` \y -> return' (x, y) -- [(1,'a'),(1,'b'),(1,'c'),(2,'a'),(2,'b'),(2,'c'),(3,'a'),(3,'b'),(3,'c')]
  print $ [1..3] `bind` \x -> ([] :: [Int]) `bind` \y -> return' (x, y) -- []
