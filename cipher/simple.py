#!/usr/bin/env python
# -*- coding: utf-8 -*-


def charcode_add(_str, seed):
    ret = []
    for e in list(_str):
        ret.append(chr(ord(e) + seed))
    return ret


def do_swap(_str, seed):
    _lst = list(_str)
    for i in range(0, len(_lst), seed):
        for j in range(i, len(_lst), seed):
            swap_se(_lst, i, j)
    return "".join(_lst)


def swap_se(lst, i, j):
    tmp = lst[i]
    lst[i] = lst[j]
    lst[j] = tmp


if __name__ == '__main__':
    _in = raw_input()
    print '***encrypt'
    print do_swap(do_swap(charcode_add(_in, 2), 5), 3)
    print '***decrypt'
    print do_swap(do_swap(charcode_add(_in, -2), 3), 5)
