#!/bin/bash

# Define color and icon variables
RED='\033[31m'
GREEN='\033[32m'
YELLOW='\033[33m'
BLUE='\033[34m'
RESET='\033[0m'
CHECK_MARK="\u2714"
CROSS_MARK="\u274C"
INFO="\u2139"
ALERT="\u26A0"

# Define variables
HOME_DIR="$HOME"
CPT_DIR="$HOME_DIR/.cpt"
HELPERS_DIR="$CPT_DIR/helpers"
COMPILE_FLAGS="-Wall -Werror -Wextra"

# Prompt for user input
read -p "List number: C" list_number
read -p "Test until: ex" exercise_number

# Analyze the norm
echo -e "${BLUE}${INFO} Analyzing the norm...${RESET}"
norminette -R CheckForbiddenHeader ex*/*
if [ $? -eq 0 ]; then
    echo -e "${GREEN}${CHECK_MARK} Norminette check passed.${RESET}"
else
    echo -e "${RED}${CROSS_MARK} Norminette check failed.${RESET}"
fi

# Compile the code
echo -e "${BLUE}${INFO} Compiling and testing exercises...${RESET}"
for i in $(seq -w 0 $exercise_number); do
    cc -o ex$i/ex$i $COMPILE_FLAGS ex$i/*.c ~/.cpt/C$list_number/test_ex$i.c $HELPERS_DIR/test_helpers.c -I $HELPERS_DIR
    ./ex$i/ex$i
    rm ./ex$i/ex$i
done
