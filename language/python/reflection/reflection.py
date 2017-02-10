#!/usr/bin/env python
# -*- coding: utf-8 -*-

import inspect
from functools import wraps


def visit_log(func):
    @wraps(func)
    def inner(*args, **kwargs):
        class_name = args[0].__class__.__name__
        func_name = func.__name__
        print("visit %s/%s" % (class_name, func_name))
        return func(*args, **kwargs)
    return inner

@visit_log
def bye(msg):
    return "bye, %s" % (msg)

class Foo:

    def __init__(self):
        pass

    def show(self):
        print(inspect.currentframe().f_code.co_name)
        print(self.__class__.__name__)

    @visit_log
    def hello(self, msg):
        return "hello, %s" % (msg)

if __name__ == '__main__':
    foo = Foo()

    print('---')
    foo.show()

    print('---')
    print(foo.hello('world'))

    print('---')
    print(bye('world'))
