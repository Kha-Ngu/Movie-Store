#!/bin/bash

# Clean and compile
make clean
make

# Run the program without Return commands
echo "Running without Return (R) commands..."
grep -v "^R" data4commands.txt | ./a.out
