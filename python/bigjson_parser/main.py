#!/usr/bin/env python
# -*- coding: utf-8 -*-

import json

def load_json_stream(fname):
    in_buf = []
    out_buf = []
    open_paren = 0
    close_paren = 0
    with open(fname, 'r') as file:
        while True:
            token = file.read(1)

            if token == '':
                break

            if (token == '\n') or (len(in_buf) == 0 and token != '{'):
                continue
            else:
                in_buf.append(token)

            if token == '{':
                open_paren += 1
            elif token == '}':
                close_paren += 1
                if open_paren == close_paren:
                    out_buf.append(json.loads(''.join(in_buf)))
                    in_buf = []
                    open_paren = 0
                    close_paren = 0
    return out_buf

if __name__ == '__main__':
    print(load_json_stream('bigdata.txt'))
    print(load_json_stream('bigdata2.txt'))
