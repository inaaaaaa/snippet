# -*- coding: utf-8 -*-


def bogosort(lst):
    cnt = 0
    for e in permutations(lst):
        cnt += 1
        if sorted_p(e):
            return cnt, e


def permutations(lst):
    if len(lst) == 0:
        return []
    if len(lst) == 1:
        return [lst]
    ret = []
    for i in range(len(lst)):
        lst0 = deepcopy(lst)
        x = lst0.pop(i)
        for xs in permutations(lst0):
            ret.append(cons(x, xs))
    return ret


def cons(x, xs):
    ret = [x]
    ret.extend(xs)
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


if __name__ == "__main__":
    print bogosort([22, 44, 33, 11, 55, 66, 0])
