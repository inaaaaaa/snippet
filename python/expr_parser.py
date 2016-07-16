#!/usr/bin/env python
# -*- coding: utf-8 -*-

import re
import json

"""
value <- [0-9]+ / '(' expr ')'
product <- value (('*' / '/') value)*
sum <- product (('+' / '-') product)*
expr <- sum
"""

def _expr(tokens):
    return {'expr': [_sum(tokens)]}

def _sum(tokens):
    paren = 0
    _tokens = []
    _next = []
    for t in tokens:
        if t == '(':
            paren += 1
            _tokens.append(t)
        elif t == ')':
            paren -= 1
            _tokens.append(t)
        elif (t == '+' or t == '-') and paren == 0:
            _next.append(_product(_tokens))
            _tokens = []
            _next.append(t)
        else:
            _tokens.append(t)
    _next.append(_product(_tokens))
    return {'sum': _next}

def _product(tokens):
    paren = 0
    _tokens = []
    _next = []
    for t in tokens:
        if t == '(':
            paren += 1
            _tokens.append(t)
        elif t == ')':
            paren -= 1
            _tokens.append(t)
        elif (t == '*' or t == '/') and paren == 0:
            _next.append(_value(_tokens))
            _tokens = []
            _next.append(t)
        else:
            _tokens.append(t)
    _next.append(_value(_tokens))
    return {'product': _next}

def _value(tokens):
    if re.search('[0-9]+', tokens[0]):
        return {'value': [tokens[0]]}
    elif tokens[0] == '(' and tokens[len(tokens) - 1] == ')':
        return {'value': [_expr(tokens[1:len(tokens)-1])]}

if __name__ == '__main__':
    input0 = ['25', '+', '10']
    input1 = ['(', '25', '+', '10', ')', '*', '20']
    input2 = ['(', '(', '25', '+', '10', ')', ')', '*', '20']
    input3 = ['200']
    print(json.dumps(_expr(input0)))
    print(json.dumps(_expr(input1)))
    print(json.dumps(_expr(input2)))
    print(json.dumps(_expr(input3)))
