#!/usr/bin/env python

# This file is autogenerated by Autocmake
# Copyright (c) 2015 by Radovan Bast and Jonas Juselius
# See https://github.com/scisoft/autocmake/

import os
import sys

sys.path.append('cmake/lib')
from config import configure
import docopt


options = """
Usage:
  ./setup.py [options] [<builddir>]
  ./setup.py (-h | --help)

Options:
  --cxx=<CXX>                         C++ compiler [default: g++].
  --extra-cxx-flags=<EXTRA_CXXFLAGS>  Extra C++ compiler flags [default: ''].
  --type=<TYPE>                       Set the CMake build type (debug, release, or relwithdeb) [default: release].
  --generator=<STRING>                Set the CMake build system generator [default: Unix Makefiles].
  --show                              Show CMake command and exit.
  --cmake-options=<OPTIONS>           Define options to CMake [default: None].
  <builddir>                          Build directory.
  -h --help                           Show this screen.
"""


def gen_cmake_command(options, arguments):
    """
    Generate CMake command based on options and arguments.
    """
    command = []
    command.append('CXX=%s' % arguments['--cxx'])
    command.append('cmake')
    command.append('-DEXTRA_CXXFLAGS="%s"' % arguments['--extra-cxx-flags'])
    command.append('-DCMAKE_BUILD_TYPE=%s' % arguments['--type'])
    command.append('-G "%s"' % arguments['--generator'])
    if(arguments['--cmake-options']):
        command.append('%s' % arguments['--cmake-options'])

    return ' '.join(command)


try:
    arguments = docopt.docopt(options, argv=None)
except docopt.DocoptExit:
    sys.stderr.write('ERROR: bad input to %s\n' % sys.argv[0])
    sys.stderr.write(options)
    sys.exit(-1)

root_directory = os.path.dirname(os.path.realpath(__file__))
build_path = arguments['<builddir>']
cmake_command = '%s %s' % (gen_cmake_command(options, arguments), root_directory)
configure(root_directory, build_path, cmake_command, arguments['--show'])
