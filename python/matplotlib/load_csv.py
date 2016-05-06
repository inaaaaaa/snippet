#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt

def load(fname, delim, dim, pass_header=True):
    ret = [[] for i in range(dim)]
    with open(fname, 'r') as fh:
        for line in fh:
            line = line.rstrip().split(delim)
            [ret[i].append(line[i]) for i in range(dim)]
    return [x[1:] for x in ret] if pass_header else ret

def main():
    dat = load('load_csv.txt', ',', 2)
    x = range(len(dat[0]))
    plt.bar(x, [int(x) for x in dat[1]], align='center')
    plt.xticks(x, dat[0])
    plt.savefig('load_csv.png') # or plt.show()

if __name__ == '__main__':
    main()
