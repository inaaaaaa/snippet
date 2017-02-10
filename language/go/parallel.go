package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func f(i int, sleepSec int) {
	time.Sleep(time.Duration(sleepSec) * time.Second)
	fmt.Println(sleepSec, i)
}

func main() {
	rand.Seed(0)
	var wg sync.WaitGroup
	for i := 0; i < 100; i++ {
		wg.Add(1)
		go func(i int) {
			defer wg.Done()
			f(i, rand.Intn(10))
		}(i)
	}
	wg.Wait()
}
