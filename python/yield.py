#!/usr/bin/env python
# -*- coding: utf-8 -*-


def fib():
    a, b = 0, 1
    while True:
        yield b
        a, b = b, a + b

if __name__ == '__main__':
    for x in fib():
        print(x)
        if x > 100:
            break
