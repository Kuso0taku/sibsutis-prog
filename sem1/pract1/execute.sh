#!/bin/bash
task="task$1"
path="./$task"
echo "Making & executing $task:"
echo
nvim "$task.c"
gcc "$task.c" -o "$task" && "$task"
