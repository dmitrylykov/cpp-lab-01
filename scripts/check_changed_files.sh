#!/usr/bin/env bash
# На pull request разрешены правки только файлов с TODO.
set -euo pipefail

base="${BASE_SHA:?BASE_SHA is required}"
head="${HEAD_SHA:-HEAD}"

allowed=(
    "tasks/01_types/types.cpp"
    "tasks/02_branches/labels.cpp"
    "tasks/03_loops/main.cpp"
    "tasks/04_journal/journal.cpp"
    "tasks/04_journal/main.cpp"
)

mapfile -t changed < <(git diff --name-only "$base" "$head")

if [[ "${#changed[@]}" -eq 0 ]]; then
    echo "No changed files."
    exit 0
fi

bad=0
for file in "${changed[@]}"; do
    ok=0
    for allow in "${allowed[@]}"; do
        if [[ "$file" == "$allow" ]]; then
            ok=1
            break
        fi
    done
    if [[ "$ok" -eq 0 ]]; then
        echo "Unexpected change: $file"
        bad=1
    fi
done

if [[ "$bad" -ne 0 ]]; then
    echo "Edit only the TODO files listed in README."
    exit 1
fi

echo "Changed files are solution files."
