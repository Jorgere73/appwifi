#!/bin/bash

gcc -c appwifi.c
gcc -c menu.c
gcc -c main.c
gcc appwifi.o main.o menu.o -o main
./main
