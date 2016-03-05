#!/usr/bin/env python3
# encoding:utf-8

import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import sklearn as skl

def main():
    x = range(50)
    y = np.random.randint(0, 100, 50)
    plt.plot(x, y)
    plt.savefig('line.png')
    plt.clf()
    plt.plot(x, y, "o")
    plt.savefig('dot.png')

if __name__ == '__main__':
    main()
