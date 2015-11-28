# -*- coding: utf-8 -*-


def mergesort(lst):
    if len(lst) < 2:
        return lst
    return merge(mergesort(lst[0:len(lst)/2]),
                 mergesort(lst[len(lst)/2:len(lst)]))


def merge(lst0, lst1):
    ret = []
    while True:
        if len(lst0) == 0:
            ret.extend(lst1)
            return ret
        if len(lst1) == 0:
            ret.extend(lst0)
            return ret
        if lst0[0] < lst1[0]:
            ret.append(lst0.pop(0))
        else:
            ret.append(lst1.pop(0))


if __name__ == '__main__':
    print mergesort([99, 33, 22, 55, 11, 00])
