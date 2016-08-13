#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Usage: $ python3.5 -B brainfuck.py

"""
expr ::= {char};
char ::= '>' | '<' | '+' | '-' | '.' | ',' | '[' | ']' | other;
other ::= ? all visible characters ?;
"""

helloworld = '+++++++++[>++++++++>+++++++++++>+++++<<<-]>.>++.+++++++..+++.>-.------------.<++++++++.--------.+++.------.--------.>+.'


class BrainFuck:

    def __init__(self):
        self.inst_ptr = 0
        self.data_ptr = 0
        self.arr = [0] * 30000

    def interpret(self, _in):
        while self.inst_ptr < len(_in):
            c = _in[self.inst_ptr]
            self.inst_ptr += 1
            if c == '>':
                self.data_ptr += 1
            elif c == '<':
                self.data_ptr -= 1
            elif c == '+':
                self.arr[self.data_ptr] += 1
            elif c == '-':
                self.arr[self.data_ptr] -= 1
            elif c == '.':
                print(chr(int(self.arr[self.data_ptr])), end="")
            elif c == ',':
                self.arr[self.data_ptr] = int(input())
            elif c == '[':
                if self.arr[self.data_ptr] == 0:
                    while _in[self.inst_ptr] != ']':
                        self.inst_ptr += 1
                    self.inst_ptr += 1
            elif c == ']':
                if self.arr[self.data_ptr] != 0:
                    while _in[self.inst_ptr] != '[':
                        self.inst_ptr -= 1
                    self.inst_ptr += 1
            else:
                pass


if __name__ == '__main__':
    BrainFuck().interpret(helloworld)
