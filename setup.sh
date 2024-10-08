#!/bin/bash

# Define colors
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
RED="\033[1;31m"
RESET="\033[0m"

# Define icons
CHECK_MARK="\u2714"
CROSS_MARK="\u274C"
INFO="\u2139"
ALERT="\u26A0"

# Define variables
HOME_DIR="$HOME"
CPT_DIR="$HOME_DIR/.cpt"
REPO_URL="https://github.com/Poukk/c-piscine-test"
SCRIPT_FILE="$CPT_DIR/script.sh"

# Create .cpt directory
if [ -d "$CPT_DIR" ]; then
    echo -e "${YELLOW}${INFO} Deleting existing directory $CPT_DIR...${RESET}"
    rm -rf "$CPT_DIR"
    echo -e "${GREEN}${CHECK_MARK} Directory $CPT_DIR deleted.${RESET}"
fi

echo -e "${YELLOW}${INFO} Creating directory $CPT_DIR...${RESET}"
mkdir "$CPT_DIR"
echo -e "${GREEN}${CHECK_MARK} Directory $CPT_DIR created.${RESET}"

# Clone the Git repository into .cpt
if [ ! -d "$CPT_DIR/.git" ]; then
    echo -e "${YELLOW}${INFO} Cloning repository $REPO_URL into $CPT_DIR...${RESET}"
    git clone "$REPO_URL" "$CPT_DIR"
    echo -e "${GREEN}${CHECK_MARK} Repository cloned successfully.${RESET}"
else
    echo -e "${BLUE}${INFO} Repository already cloned in $CPT_DIR.${RESET}"
fi

# Function to add the function to the shell config file
add_function() {
    SHELL_CONFIG_FILE="$1"
    SHELL_TYPE="$2"

    # Remove existing function or alias if it exists
    sed -i '/cpt()/,/}/d' "$SHELL_CONFIG_FILE"
    sed -i '/alias cpt=/d' "$SHELL_CONFIG_FILE"

    echo -e "${YELLOW}${INFO} Adding function to $SHELL_CONFIG_FILE...${RESET}"
    
    if [ "$SHELL_TYPE" = "fish" ]; then
        echo '' >> "$SHELL_CONFIG_FILE"
        echo 'function cpt' >> "$SHELL_CONFIG_FILE"
        echo '    if test "$argv[1]" = "--upgrade"' >> "$SHELL_CONFIG_FILE"
        echo "        git -C \"$CPT_DIR\" pull \"$REPO_URL\"" >> "$SHELL_CONFIG_FILE"
        echo '    else' >> "$SHELL_CONFIG_FILE"
        echo "        bash \"$SCRIPT_FILE\" \$argv" >> "$SHELL_CONFIG_FILE"
        echo '    end' >> "$SHELL_CONFIG_FILE"
        echo 'end' >> "$SHELL_CONFIG_FILE"
    else
        echo '' >> "$SHELL_CONFIG_FILE"
        echo 'cpt() {' >> "$SHELL_CONFIG_FILE"
        echo '    if [[ "$1" = "--upgrade" ]]; then' >> "$SHELL_CONFIG_FILE"
        echo "        git -C \"$CPT_DIR\" pull \"$REPO_URL\"" >> "$SHELL_CONFIG_FILE"
        echo '    else' >> "$SHELL_CONFIG_FILE"
        echo "        bash \"$SCRIPT_FILE\" \"\$@\"" >> "$SHELL_CONFIG_FILE"
        echo '    fi' >> "$SHELL_CONFIG_FILE"
        echo '}' >> "$SHELL_CONFIG_FILE"
    fi

    echo -e "${GREEN}${CHECK_MARK} Function added to $SHELL_CONFIG_FILE.${RESET}"
}

# Add function to bash, zsh, and fish if they exist
if [ -f "$HOME_DIR/.bashrc" ]; then
    add_function "$HOME_DIR/.bashrc" "bash"
fi

if [ -f "$HOME_DIR/.zshrc" ]; then
    add_function "$HOME_DIR/.zshrc" "zsh"
fi

if [ -d "$HOME_DIR/.config/fish" ]; then
    FISH_CONFIG_FILE="$HOME_DIR/.config/fish/config.fish"
    add_function "$FISH_CONFIG_FILE" "fish"
fi

# Inform user to reload shell configurations
echo -e "${YELLOW}${ALERT} Please restart your shell or source your configuration file to apply the new function.${RESET}"
