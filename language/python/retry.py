#!/usr/bin/env python
# -*- coding: utf-8 -*-

import time

def retry(func, times=3, sleep_sec=1):
    try:
        func()
    except:
        if times == 1:
            return
        time.sleep(sleep_sec)
        retry(func, times - 1, sleep_sec)

def do_something(foo):
    print(foo)
    raise

def main():
    retry(lambda: do_something("e.g. call api"), 5, 2)

if __name__ == '__main__':
    main()
