#! /usr/bin/env python
# encoding: utf-8

from build.wafconan import conan_configure_libs

VERSION='0.0.1'
APPNAME='cxx_test'

top = '.'
out = 'build'

def options(opt):
	opt.load('compiler_cxx')

def configure(conf):
	conf.load('compiler_cxx')
	conan_configure_libs(conf)

def build(bld):
	bld.program(source='example.cpp', target='app', use=bld.env.CONAN_LIBS)
