#!/bin/bash
task="task$2"
path="$1"
echo "Making & executing $task:"
echo
nvim "$path/$task.c"
gcc "$path/$task.c" -Wall -fexec-charset=UTF-8 -fextended-identifiers -finput-charset=UTF-8 -o "$path/$task" -lm && "$path/$task"
