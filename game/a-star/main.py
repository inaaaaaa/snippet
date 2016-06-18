#!/usr/bin/env python
# -*- coding: utf-8 -*-

x_offset = [-1, 0, 1, -1, 1, -1, 0, 1]
y_offset = [-1, -1, -1, 0, 0, 1, 1, 1]
g_field_x_size = 10
g_field_y_size = 10
g_field = [
    [0, 0, 1, 1, 1, 1, 1, 1, 1, 1],
    [0, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 0, 0, 0, 0, 0, 1, 1],
    [1, 1, 1, 1, 1, 1, 1, 0, 1, 1],
    [1, 1, 1, 1, 1, 1, 1, 0, 1, 1],
    [1, 1, 1, 1, 1, 1, 1, 0, 1, 1],
    [0, 0, 0, 1, 1, 1, 1, 1, 1, 1],
    [0, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 1, 1, 1, 0, 0, 1, 1]
]

class Coord():
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Node():
    def __init__(self, coord, parent_node, cost, heuristic):
        self.x = coord.x
        self.y = coord.y
        self.parent_node = parent_node
        self.cost = cost
        self.heuristic = heuristic
    def trace_ancestor(self):
        ret = []
        node = self
        while node is not None:
            ret.append(node)
            node = node.parent_node
        ret.reverse()
        return ret

def calc_cost(parent_node, cost):
    return parent_node.cost + cost

def calc_heuristic(now, goal):
    return max(abs(now.x - goal.x), abs(now.y - goal.y))

def a_star(start, goal):
    open_list = [Node(start, None, 0, 0)]
    while len(open_list) != 0:
        open_list.sort(key = lambda node: node.cost + node.heuristic)
        now_node = open_list.pop(0)
        if now_node.x == goal.x and now_node.y == goal.y:
            return now_node.trace_ancestor()
        for i in range(8):
            next_coord = Coord(now_node.x + x_offset[i], now_node.y + y_offset[i])
            next_cost = g_field[next_coord.y][next_coord.x]
            if 0 <= next_coord.x and next_coord.x < g_field_x_size and 0 <= next_coord.y and next_coord.y < g_field_y_size and next_cost > 0:
                open_list.append(Node(next_coord, now_node, calc_cost(now_node, next_cost), calc_heuristic(next_coord, goal)))
                g_field[next_coord.y][next_coord.x] = 0

def main():
    route = [(node.x, node.y) for node in a_star(Coord(4, 5), Coord(6, 1))]
    print(route)

if __name__ == '__main__':
    main()
