#!/bin/bash
for file in "${@:-*}"; do
  if [ -f "$file" ]; then
    awk '{gsub(/  /, "    "); print}' "$file" > tmp && mv tmp "$file"
    echo "Processed: $file"
  fi
done
