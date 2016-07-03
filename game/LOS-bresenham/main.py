#!/usr/bin/env python
# -*- coding: utf-8 -*-

from math import ceil

def bresenham(start_x, start_y, end_x, end_y):
    diff_x = end_x - start_x
    diff_y = end_y - start_y
    total_step = max(abs(diff_x), abs(diff_y))
    delta_x = diff_x / total_step
    delta_y = diff_y / total_step
    return [(int(ceil(start_x + delta_x * i)), int(ceil(start_y + delta_y * i)))
            for i in range(total_step + 1)]

def main():
    print(bresenham(0, 0, 8, 12))
    print(bresenham(0, 0, 8, 12))
    print(bresenham(0, 0, -8, -12))
    print(bresenham(0, 0, 10, 10))
    print(bresenham(0, 0, -10, -10))

if __name__ == '__main__':
    main()
