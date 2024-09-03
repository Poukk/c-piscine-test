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
ALIAS_NAME="cpt"
UPGRADE_ALIAS="cpt --upgrade"

# Create .cpt directory if it doesn't exist
if [ ! -d "$CPT_DIR" ]; then
    echo -e "${YELLOW}${INFO} Creating directory $CPT_DIR...${RESET}"
    mkdir "$CPT_DIR"
    echo -e "${GREEN}${CHECK_MARK} Directory $CPT_DIR created.${RESET}"
else
    echo -e "${BLUE}${INFO} Directory $CPT_DIR already exists.${RESET}"
fi

# Clone the Git repository into .cpt
if [ ! -d "$CPT_DIR/.git" ]; then
    echo -e "${YELLOW}${INFO} Cloning repository $REPO_URL into $CPT_DIR...${RESET}"
    git clone "$REPO_URL" "$CPT_DIR"
    echo -e "${GREEN}${CHECK_MARK} Repository cloned successfully.${RESET}"
else
    echo -e "${BLUE}${INFO} Repository already cloned in $CPT_DIR.${RESET}"
fi

# Function to add alias to shell config file
add_alias() {
    SHELL_CONFIG_FILE="$1"
    if ! grep -q "alias $ALIAS_NAME=" "$SHELL_CONFIG_FILE"; then
        echo -e "${YELLOW}${INFO} Adding alias to $SHELL_CONFIG_FILE...${RESET}"
        echo "alias $ALIAS_NAME='bash $SCRIPT_FILE'" >> "$SHELL_CONFIG_FILE"
        echo "alias '$UPGRADE_ALIAS'='git pull $REPO_URL'" >> "$SHELL_CONFIG_FILE"
        echo -e "${GREEN}${CHECK_MARK} Aliases added to $SHELL_CONFIG_FILE.${RESET}"
        echo -e "${BLUE}${INFO} Please run 'source $SHELL_CONFIG_FILE' to apply changes.${RESET}"
    else
        echo -e "${RED}${CROSS_MARK} Alias $ALIAS_NAME already exists in $SHELL_CONFIG_FILE.${RESET}"
    fi
}

# Add alias to bash, zsh, and fish if they exist
if [ -f "$HOME_DIR/.bashrc" ]; then
    add_alias "$HOME_DIR/.bashrc"
fi

if [ -f "$HOME_DIR/.zshrc" ]; then
    add_alias "$HOME_DIR/.zshrc"
fi

if [ -d "$HOME_DIR/.config/fish" ]; then
    FISH_CONFIG_FILE="$HOME_DIR/.config/fish/config.fish"
    add_alias "$FISH_CONFIG_FILE"
fi

# Inform user to reload shell configurations
echo -e "${YELLOW}${ALERT} Please restart your shell to apply the new aliases.${RESET}"

