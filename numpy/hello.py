#!/usr/bin/env python3
# encoding:utf-8

# run : python3 hello.py

import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import sklearn as skl

def main():
    a = np.array([[1, 2, 3, 4, 5], [2, 4, 6, 8, 10]])
    b = np.zeros(3)
    c = np.ones((3, 4))
    d = np.empty((2, 3))
    e = np.zeros_like(a)
    f = np.identity(2)
    print(repr(a))
    print(a[1][0])
    print(repr(b))
    print(repr(c))
    print(repr(d))
    print(repr(e))
    print(repr(f))

if __name__ == '__main__':
    main()
