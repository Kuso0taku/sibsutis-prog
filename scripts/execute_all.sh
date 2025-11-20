#!/bin/bash
path="$1/task"
for i in {1..8}; do 
  echo "      task no.$i:"
  "$path$i"
  echo
done
