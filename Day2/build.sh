#!/bin/bash

SRC_FILE="solution.c"
OUTPUT="solution.o"

gcc $SRC_FILE -o $OUTPUT
./$OUTPUT