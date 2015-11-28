# -*- coding: utf-8 -*-


def differential(expr):
    if len(expr) < 2:
        return []
    ret = []
    for i in range(1, len(expr)):
        ret.append(i * expr[i])
    return ret


def to_string(expr):
    ret = ''
    for i in range(len(expr)):
        if i > 0:
            ret += ' + '
        ret += (str(expr[i]) + 'x^' + str(i))
    return ret


if __name__ == '__main__':
    expr = [1, 3, 2, 1]
    print to_string(expr)
    print to_string(differential(expr))
