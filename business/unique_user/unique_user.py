#!/usr/bin/env python
# -*- coding: utf-8 -*-

INF = 10000
CNT = 30


class Edge:
    def __init__(self, src, dst):
        self.src = src
        self.dst = dst


def normalize(edges):
    lst = [INF] * CNT

    sorted(edges, key=lambda e: min(e.src, e.dst))

    for e in edges:
        x = min(e.src, e.dst, lst[e.src], lst[e.dst])
        lst[e.src] = x
        lst[e.dst] = x

    return lst


def pprint(res):
    for i, x in enumerate(res):
        if x == INF:
            continue
        print('{}:{}'.format(str(i), str(x)))


if __name__ == '__main__':
    edges = [
        Edge(1, 4),
        Edge(3, 4),
        Edge(4, 5),
        Edge(5, 11),
        Edge(5, 2),
        Edge(7, 6),
        Edge(7, 9)
    ]
    pprint(normalize(edges))
