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

# Prompt for user input
read -p "List number: C" list_number
read -p "Test until: ex" exercise_number

# Generate compilation flags
compile_flags=""
for i in $(seq -w 0 $exercise_number); do
    compile_flags="$compile_flags -D EX$i ex$i/*.c"
done

# Compile the code
echo -e "${BLUE}${INFO} Compiling...${RESET}"
cc -Wall -Werror -Wextra $compile_flags ~/.cpt/C$list_number/main.c
if [ $? -eq 0 ]; then
    echo -e "${GREEN}${CHECK_MARK} Compilation successful.${RESET}"
else
    echo -e "${RED}${CROSS_MARK} Compilation failed.${RESET}"
    exit 1
fi

# Analyze the norm
echo -e "${BLUE}${INFO} Analyzing the norm...${RESET}"
norminette -R CheckForbiddenHeader ex*/*
if [ $? -eq 0 ]; then
    echo -e "${GREEN}${CHECK_MARK} Norminette check passed.${RESET}"
else
    echo -e "${RED}${CROSS_MARK} Norminette check failed.${RESET}"
fi

# Test exercises
echo -e "${BLUE}${INFO} Testing exercises...${RESET}"
./a.out $exercise_number
if [ $? -eq 0 ]; then
    echo -e "${GREEN}${CHECK_MARK} All tests passed successfully.${RESET}"
else
    echo -e "${RED}${CROSS_MARK} Execution failed.${RESET}"
    exit 1
fi

# Clean up
echo -e "${BLUE}${INFO} Cleaning up...${RESET}"
rm a.out
echo -e "${GREEN}${CHECK_MARK} Cleanup completed.${RESET}"
