#!/usr/bin/env python
# -*- coding: utf-8 -*-

import re

from jinja2 import Template


def load(fpath):
    with open(fpath) as f:
        return Template(f.read())

if __name__ == '__main__':
    query = load('./template.jinja2').render(yyyymmdd='20160808')
    query = re.sub(r'\ +|\n', ' ', query)
    print(query)
