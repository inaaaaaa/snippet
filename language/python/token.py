#!/usr/bin/env python
# -*- coding: utf-8 -*-

import re

def _skip_whitespace(_str):
    m = re.match(' +', _str)
    if m:
        _str = _str[m.end():]
    return _str

def tokenize(_str):
    _str = _skip_whitespace(_str)
    if _str == '':
        return []
    first = None
    rest = None
    ptn = '[0-9]+|\+|\-|\*|\/|\(|\)|plus|minus|mul|div'
    m = re.match(ptn, _str)
    if m:
        first = _str[:m.end()]
        rest = _str[m.end():]
    else:
        raise Exception('miss match')
    ret = tokenize(rest)
    ret.insert(0, first)
    return ret

if __name__ == '__main__':
    print(tokenize('11 + 22'))
    print(tokenize('11 + 22      '))
    print(tokenize('11 plus 22 mul 2 minus 3 div 5'))
    print(tokenize('(11 + 22) * 200 + 1'))
