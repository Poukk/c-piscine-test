#!/bin/bash

# Define color variables
RED='\033[31m'
GREEN='\033[32m'
YELLOW='\033[33m'
BLUE='\033[34m'
RESET='\033[0m'

# Prompt for user input
read -p "List number: C" list_number 
read -p "Test until: ex: " exercise_number

# Generate compilation flags
compile_flags=""
for i in $(seq -w 0 $exercise_number); do
    compile_flags="$compile_flags -D EX$i"
done

# Compile the code
echo -e "${BLUE}Compiling...${RESET}"
cc -Wall -Werror -Wextra $compile_flags ~/.cpt/C$list_number/main.c ex*/* || { echo -e "${RED}Compilation failed.${RESET}"; exit 1; }

# Analyze the norm
echo -e "${BLUE}Analyzing the norm.${RESET}"
norminette -R CheckForbiddenHeader ex*/* || { echo -e "${RED}Norminette check failed.${RESET}"; }

# Test exercises
echo -e "${BLUE}Testing exercises...${RESET}"
./a.out $exercise_number || { echo -e "${RED}Execution failed.${RESET}"; exit 1; }

# Remove output from compiler
rm a.out
