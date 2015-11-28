# -*- coding: utf-8 -*-

def quicksort(lst):
    if len(lst) < 2:
        return lst
    pivot = lst.pop(0)
    left = [x for x in lst if x < pivot]
    right = [x for x in lst if x >= pivot]
    return quicksort(left) + [pivot] + quicksort(right)

if __name__ == '__main__':
    print quicksort([33, 22, 11, 55, 44, 77, 00])
