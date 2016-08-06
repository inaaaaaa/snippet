#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
<expr>   ::= <term> [ ('+' | '-') <term> ]*
<term>   ::= <factor> [ ('*' | '/') <factor> ]*
<factor> ::= <number> | '(' <expr> ')'
<number> ::= [0-9]+
"""

import re


def expr(s):
    ret, rest = term(s)
    while len(rest) > 0 and (rest[0] == '+' or rest[0] == '-'):
        op = rest[0]
        val, rest = term(rest[1:])
        if op == '+':
            ret += val
        else:
            ret -= val
    return ret, rest


def term(s):
    ret, rest = factor(s)
    while len(rest) > 0 and (rest[0] == '*' or rest[0] == '/'):
        op = rest[0]
        val, rest = factor(rest[1:])
        if op == '*':
            ret *= val
        else:
            ret /= val
    return ret, rest


def factor(s):
    if re.match('\d+', s) is not None:
        return number(s)
    else:
        return expr(s[1:len(s)-1])


def number(s):
    m = re.match('\d+', s)
    ret = int(s[:m.end()])
    rest = s[m.end():]
    return ret, rest


def calc(s):
    return expr(s.replace(' ', ''))[0]


if __name__ == '__main__':
    print(calc('1'))
    print(calc('1 + 2'))
    print(calc('1 + 2 * 3'))
    print(calc('1 / 2 - 3 * 4'))
    print(calc('10 + 8 / (2 * 3)'))
