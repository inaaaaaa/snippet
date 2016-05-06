#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

def main():
    x = np.arange(-3, 3, 0.1)
    y = np.sin(x)
    plt.plot(x, y)
    plt.savefig('sin.png') # or plt.show()
    
if __name__ == '__main__':
    main()
