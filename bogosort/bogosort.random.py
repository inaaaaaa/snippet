# -*- coding: utf-8 -*-

import random


def bogosort(lst):
    cnt, ret = (0, deepcopy(lst))
    while not sorted_p(ret):
        cnt += 1
        ret = random_sort(ret)
    return cnt, ret


def random_sort(lst):
    ret = deepcopy(lst)
    for i in range(len(ret)):
        swap_se(ret, i, random.randint(0, len(ret) - 1))
    return ret


def sorted_p(lst):
    if len(lst) < 2:
        return True
    x = lst[0]
    for i in range(1, len(lst)):
        if not x <= lst[i]:
            return False
        x = lst[i]
    return True


def deepcopy(lst):
    ret = [0] * len(lst)
    for i in range(len(lst)):
        ret[i] = lst[i]
    return ret


def swap_se(lst, i, j):
    tmp = lst[i]
    lst[i] = lst[j]
    lst[j] = tmp


if __name__ == "__main__":
    random.seed(0)
    print bogosort([0, 44, 22, 33, 11, 66])
