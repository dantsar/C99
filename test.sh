#!/bin/sh
make >> /dev/null
gcc -E test.c | ./parser
