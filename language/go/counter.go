package main

import (
	"fmt"
)

func genCounter(conn chan int) {
	for i := 0; ; i++ {
		conn <- i
	}
}

func genFib(conn chan int) {
	x, y := 0, 1
	for {
		conn <- x
		x, y = y, x+y
	}
}

func main() {

	counter := make(chan int)
	go genCounter(counter)
	for i := 0; i < 10; i++ {
		fmt.Println(<-counter)
	}

	fib := make(chan int)
	go genFib(fib)
	for i := 0; i < 10; i++ {
		fmt.Println(<-fib)
	}
}
