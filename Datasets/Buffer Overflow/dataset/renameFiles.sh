#!/bin/bash


# filenames that should be excluded from renaming
EXCLUDE_EXTENSIONS=("sh" "txt")

# specific filenames to exclude
EXCLUDE_FILES=("filename_mapping.txt")


# set target directory, default to current directory if not provided
TARGET_DIR="${1:-.}"

# check if target directory exists
if [ ! -d "$TARGET_DIR" ]; then
    echo "Error: Directory '$TARGET_DIR' does not exist."
    exit 1
fi

# Create or clear the mapping file
MAPPING_FILE="$TARGET_DIR/filename_mapping.txt"
echo "Orignal filename -> New filename" > "$MAPPING_FILE"
echo "===========================================" >> "$MAPPING_FILE"

# function for checking if a file should be excluded
should_exclude() {
    local filename="$1"
    
    # check specific filenames
    for exclude_file in "${EXCLUDE_FILES[@]}"; do
        if [ "$filename" == "$exclude_file" ]; then
            return 0  # should exclude
        fi
    done
    
    # check extensions
    if [[ "$filename" == *.* ]]; then
        local ext="${filename##*.}"
        for exclude_ext in "${EXCLUDE_EXTENSIONS[@]}"; do
            if [ "$ext" == "$exclude_ext" ]; then
                return 0  # should exclude
            fi
        done
    fi
    
    return 1  # should not exclude
}

# initialize counter
counter=1

# change to target directory
cd "$TARGET_DIR" || exit 1

# loop through files in the target directory
for file in *; do
    # skip directories
    if [ -d "$file" ]; then
        continue
    fi
    
    # check if file should be excluded
    if should_exclude "$file"; then
        echo "Skip (excluded): $file"
        continue
    fi
    
    # determine new filename
    if [[ "$file" == *.* ]]; then
        # file has an extension
        extension="${file##*.}"
        new_name=$(printf "codesnippet_%04d.%s" $counter "$extension")
    else
        # file has no extension
        new_name=$(printf "codesnippet_%04d" $counter)
    fi
    
    # check if new filename already exists
    if [ -e "$new_name" ]; then
        echo "Warning: File '$new_name' exists, skipping '$file'"
        continue
    fi
    
    # Rename the file
    mv "$file" "$new_name"
    
    # Record the mapping
    echo "$file -> $new_name" >> "$MAPPING_FILE"
    
    echo "Renaming Complete: $file -> $new_name"
    
    # Increment counter
    ((counter++))
done

echo ""
echo "Finish! $((counter-1)) files renamed."
echo "Mapping relationship has been saved to: $MAPPING_FILE"
echo ""
echo "File types has been excluded: ${EXCLUDE_EXTENSIONS[*]}"
echo "Files has been excluded: ${EXCLUDE_FILES[*]}"