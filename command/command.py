#!/usr/bin/env python
# -*- coding: utf-8 -*-

import datetime
import re
import sys

HELP = {
    'all': """
usage: command [-v|--version] [-h|--help]
           <command> [<args>]

The most commonly used command commands are:
   clean      Remove files at defined path.
""",
    'clean': """
usage: command clean <path> [-n|--dry-run]
"""
}


class ParseArgsError(Exception):
    def __init__(self, msg):
        self.msg = msg

    def __str__(self):
        return repr(self.msg)


class Logger:
    def __init__(self):
        pass

    def log(self, msg):
        time = datetime.datetime.now().strftime('%Y/%m/%d %T')
        print "%s::%s" % (time, msg)


class CleanCommand:
    def __init__(self, args):
        try:
            self.args = self._check_args(self._parse_args(args))
        except ParseArgsError as e:
            print HELP['clean']
            print '***ParseArgsError Occured : %s' % (e.msg)
            exit(1)
        self.logger = Logger()

    def run(self):
        if self.args['dry_run']:
            self.logger.log('This is dry run.')
        self.logger.log('run...')

    def _parse_args(self, args):
        _args = {'path': None, 'dry_run': False}
        i = 0
        while i < len(args):
            if args[i] == '-n' or args[i] == '--dry-run':
                _args['dry_run'] = True
            elif re.match(r'^-+', args[i]):
                raise ParseArgsError('Undefined Option')
            else:
                if _args['path'] is None:
                    _args['path'] = args[i]
                else:
                    raise ParseArgsError('Multiple Paths are Defined')
            i += 1
        if _args['path'] is None:
            raise ParseArgsError("The Path isn't Defined")
        return _args

    def _check_args(self, args):
        if not re.match(r'^/', args['path']):
            raise ParseArgsError("The Path is Invalid. "
                                 "Please Input Full Path.")
        return args


def dispatch(subcommand, args):
    if subcommand == '-v' or subcommand == '--version':
        print 'command version 0.0.1'
    elif subcommand == '-h' or subcommand == '--help':
        print HELP['all']
    elif subcommand == 'clean':
        CleanCommand(args).run()
    else:
        print "command: '%s' is not a command command. " \
            + "See 'command --help'." % (subcommand)


if __name__ == '__main__':
    argv = sys.argv
    if len(argv) < 2:
        print HELP['all']
        exit(1)
    dispatch(argv[1], argv[2:])
