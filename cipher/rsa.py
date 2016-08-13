#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Usage: $ python3.5 -B rsa.py

import math
import random


class RSA:

    def __init__(self, p, q):
        """p and q are prime number."""
        self.m = p * q  # public key
        self.z = (p - 1) * (q - 1)
        self.e = self._gen_e(self.z)  # public key
        self.d = self._gen_d(self.e, self.z)  # private key

    def _gen_e(self, z):
        """e and z are relatively prime."""
        ret = []
        for e in range(2, z):
            if math.gcd(e, z) == 1:
                ret.append(e)
        return ret[random.randrange(len(ret))]

    def _gen_d(self, e, z):
        """d is the modular multiplicative inverse of z."""
        ret = []
        for d in range(2, z):
            if (d * e) % z == 1:
                ret.append(d)
        return ret[random.randrange(len(ret))]

    def encrypt(self, x):
        return (x ** self.e) % self.m

    def decrypt(self, x):
        return (x ** self.d) % self.m


if __name__ == '__main__':
    rsa = RSA(71, 41)

    # plaintext
    s = 'Hello, World!'
    xs = [ord(c) for c in s]
    print(s)

    # chiphertext
    xs = [rsa.encrypt(x) for x in xs]
    s = ''.join([chr(x) for x in xs])
    print(s)

    # plaintext
    xs = [rsa.decrypt(x) for x in xs]
    s = ''.join([chr(x) for x in xs])
    print(s)
