#!/bin/bash

gcc -c appwifi.c
gcc -c main.c
gcc appwifi.o main.o -o main
./main
