#!/usr/bin/env python
# -*- coding: utf-8 -*-

import functools
import re
import sys

g_func = {
    'add': lambda xs: add(xs),
    'sub': lambda xs: sub(xs),
    'mul': lambda xs: mul(xs),
    'div': lambda xs: div(xs)
}

def add(xs):
    xs = [int(x) for x in xs]
    return functools.reduce(lambda a, b: a + b, xs)

def sub(xs):
    xs = [int(x) for x in xs]
    return functools.reduce(lambda a, b: a - b, xs)

def mul(xs):
    xs = [int(x) for x in xs]
    return functools.reduce(lambda a, b: a * b, xs)

def div(xs):
    xs = [int(x) for x in xs]
    return functools.reduce(lambda a, b: a / b, xs)

def _apply(stack):
    args = []
    for i in range(len(stack)):
        token0 = stack[len(stack)-i-2]
        token1 = stack[len(stack)-i-1]
        if token0 == '(':
            return stack[:len(stack)-i-2] + [g_func[token1](args)]
        else:
            args.insert(0, token1)

def read_head(_str):
    token = re.match(r'[(,)]|\w+', _str)
    if token:
        return (_str[:token.end()], _str[token.end():])
    else:
        return read_head(_str[1:])
    
def consume(_str, stack):
    if _str == '':
        return stack
    (head, last) = read_head(_str)
    if head == ')':
        return consume(last, _apply(stack))
    else:
        return consume(last, stack+[head])

def _eval(_str):
    return consume(_str, [])[0]

if __name__ == '__main__':
    print(_eval("(mul (add 1 2 3) 2000)"))
    print(_eval("(div (add 5 5) 2)"))
    print(_eval("(sub 3 7)"))
