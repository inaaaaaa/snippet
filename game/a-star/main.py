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

class Node():
    def __init__(self, x, y, parent_node, cost, heuristic):
        self.x = x
        self.y = y
        self.parent_node = parent_node
        self.cost = cost
        self.heuristic = heuristic
    def trace_ancestor(self):
        ret = []
        n = self
        while n is not None:
            ret.append(n)
            n = n.parent_node
        return ret

def calc_cost(parent_node, g_field_cost):
    return parent_node.cost + g_field_cost

def calc_heuristic(now_x, now_y, goal_x, goal_y):
    return max(abs(goal_x - now_x), abs(goal_y - now_y))

def a_star(start_x, start_y, goal_x, goal_y):
    open_list = [Node(start_x, start_y, None, 0, 0)]
    while len(open_list) != 0:
        open_list.sort(key = lambda x: x.cost + x.heuristic)
        now_node = open_list.pop(0)
        if now_node.x == goal_x and now_node.y == goal_y:
            return now_node.trace_ancestor()
        for i in range(8):
            next_x = now_node.x + x_offset[i]
            next_y = now_node.y + y_offset[i]
            next_cost = g_field[next_y][next_x]
            if 0 <= next_x and next_x < g_field_x_size and 0 <= next_y and next_y < g_field_y_size and next_cost > 0:
                g_field[next_y][next_x] = 0
                open_list.append(Node(next_x, next_y, now_node, calc_cost(now_node, next_cost), calc_heuristic(next_x, next_y, goal_x, goal_y)))

def main():
    route = [(node.x, node.y) for node in a_star(4, 5, 6, 1)]
    print(route)
    for xs in g_field:
        print(xs)

if __name__ == '__main__':
    main()
