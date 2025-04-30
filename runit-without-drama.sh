#!/bin/bash

# Clean and compile
make clean
make

# Run the program without Drama genre movies
echo "Running without Drama genre..."
grep -v "^D," data4movies.txt | ./a.out
