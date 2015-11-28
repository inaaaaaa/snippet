-- maybe monad

bind :: Maybe a -> (a -> Maybe b) -> Maybe b
bind (Just x) f = f x
bind Nothing  _ = Nothing

return' :: a -> Maybe a
return' x = Just x

main :: IO()
main = do
  print $ Just 1 `bind` \a -> Just $ a * 2 -- Just 2
  print $ Just 1 `bind` \a -> Nothing `bind` \b -> Just $ a * b -- Nothing
