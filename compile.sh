#! /bin/bash

gcc -std=c11 -Wall -Wextra -pedantic -o ToyShell src/utils.c src/ToyShell.c main.c
