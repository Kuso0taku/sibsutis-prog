#!/bin/bash
path="."
echo "logging.."
echo "code logging.."
echo "" > code_log.txt
for i in {1..8}; do 
  echo "     task no.$i" >> code_log.txt
  cat "$path/task$i.c" >> code_log.txt
  echo "" >> code_log.txt
  echo "" >> code_log.txt
  echo "..task no.$i done."
done
echo "done."
echo "output logging.."
"$path/execute_all".sh > output_log.txt
echo "done."
echo "done."
