#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Usage: $ python3.5 -B caesar.py


def shift(x, rot):
    return x + rot

if __name__ == '__main__':
    # plain text
    s = 'Hello, World!'
    xs = [ord(c) for c in s]
    print(s)

    # chiphertext
    en = [shift(x, 13) for x in xs]
    s = ''.join([chr(x) for x in en])
    print(s)

    # plain text
    de = [shift(x, -13) for x in en]
    s = ''.join([chr(x) for x in de])
    print(s)


    # plain text
    s = 'Goodbye, World!'
    xs = [ord(c) for c in s]
    print(s)

    # chiphertext
    en = [shift(x, 13 + i) for i, x in enumerate(xs)]
    s = ''.join([chr(x) for x in en])
    print(s)

    # plain text
    de = [shift(x, - (13 + i)) for i, x in enumerate(en)]
    s = ''.join([chr(x) for x in de])
    print(s)
