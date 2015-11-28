-- state monad

import Control.Monad.State

bind' :: MonadState t1 m => State t1 t -> (t -> State t1 a) -> m a
bind' a b = state $ \s ->
            let (r1, s1) = runState a      s
                (r2, s2) = runState (b r1) s1
            in  (r2, s2)

return' :: MonadState s m => a -> m a
return' x = state $ \s -> (x, s)

get'      = state $ \s -> (s, s)

put'    x = state $ \_ -> ((), x)

modify' f = state $ \s -> ((), f s)

main = do
  print $ runState (return' 100) 10 -- (100,10)
  print $ (`runState` 0) $ return' 10 `bind'` (\x -> state $ \s -> (x, 2000)) -- (10,2000)
  print $ (`runState` 0) $ (state $ \s -> (10, 10)) `bind'` (\x -> state $ \s -> (x + 20, s)) -- (30,10)
  print $ (`runState` 5) $ return' 10 `bind'` (\_ -> get') `bind'` (\x -> return' x) -- (5,5)
