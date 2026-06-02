#!/bin/zsh

for f in *.rst; do
  # Skip if no .rst files exist
  [[ -e "$f" ]] || continue

  # Create a temp file
  tmp="${f}.tmp"

  # Remove the first 14 lines and write the rest to the temp file
  tail -n +15 "$f" > "$tmp"

  # Replace the original file
  mv "$tmp" "$f"
done
