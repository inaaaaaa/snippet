#!/usr/bin/env python
# -*- coding: utf-8 -*-

import functools
import re
import sys

g_func = {
    'add': lambda xs: functools.reduce(lambda a, b: a + b, [int(x) for x in xs]),
    'sub': lambda xs: functools.reduce(lambda a, b: a - b, [int(x) for x in xs]),
    'mul': lambda xs: functools.reduce(lambda a, b: a * b, [int(x) for x in xs]),
    'div': lambda xs: functools.reduce(lambda a, b: a / b, [int(x) for x in xs])
}

def _eval(stack):
    args = []
    for i in range(len(stack)):
        token0 = stack[len(stack) - i - 2]
        token1 = stack[len(stack) - i - 1]
        if token0 == '(':
            return stack[:len(stack) - i - 2] + [g_func[token1](args)]
        else:
            args.insert(0, token1)

def parse(tokens, stack):
    if len(tokens) == 0:
        return (tokens, stack)
    if tokens[0] == ')':
        return parse(tokens[1:], _eval(stack))
    else:
        return parse(tokens[1:], stack + [tokens[0]])

def read_token(_str):
    token = re.match(r'[(,)]|\w+', _str)
    if token:
        return (_str[:token.end()], _str[token.end():])
    else:
        return read_token(_str[1:])

def tokenize(_str):
    if _str == '':
        return []
    (token, rest) = read_token(_str)
    return [token] + tokenize(rest)

def _exec(_str):
    return parse(tokenize(_str), [])[1][0]

if __name__ == '__main__':
    print(_exec("(mul (add 1 2 3) 2000)"))
    print(_exec("(div (add 5 5) 2)"))
    print(_exec("(sub 3 7)"))
