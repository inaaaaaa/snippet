fib :: [Int]
fib = 1:1:zipWith (+) fib (tail fib)

main :: IO()
main = putStrLn $ show $ take 10 fib
