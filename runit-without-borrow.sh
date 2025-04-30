#!/bin/bash

# Clean and compile
make clean
make

# Run the program without Borrow commands
echo "Running without Borrow (B) commands..."
grep -v "^B" data4commands.txt | ./a.out

