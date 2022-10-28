#!/bin/bash

gcc -c *.c
gcc *.o -o main -Wall
./main
