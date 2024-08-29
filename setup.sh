#!/bin/bash

# Define variables
HOME_DIR="$HOME"
CPT_DIR="$HOME_DIR/.cpt"
REPO_URL="https://github.com/Poukk/c-piscine-test"
SCRIPT_FILE="$CPT_DIR/script.sh"
ALIAS_NAME="cpt"

# Create .cpt directory if it doesn't exist
if [ ! -d "$CPT_DIR" ]; then
    echo "Creating directory $CPT_DIR..."
    mkdir "$CPT_DIR"
else
    echo "Directory $CPT_DIR already exists."
fi

# Clone the Git repository into .cpt
if [ ! -d "$CPT_DIR/.git" ]; then
    echo "Cloning repository $REPO_URL into $CPT_DIR..."
    git clone "$REPO_URL" "$CPT_DIR"
else
    echo "Repository already cloned in $CPT_DIR."
fi

# Create a script file if it does not exist
if [ ! -f "$SCRIPT_FILE" ]; then
    echo "Creating script file $SCRIPT_FILE..."
    touch "$SCRIPT_FILE"
    chmod +x "$SCRIPT_FILE"
else
    echo "Script file $SCRIPT_FILE already exists."
fi

# Add alias to .bashrc
BASHRC_FILE="$HOME_DIR/.bashrc"
if ! grep -q "alias $ALIAS_NAME=" "$BASHRC_FILE"; then
    echo "Adding alias to $BASHRC_FILE..."
    echo "alias $ALIAS_NAME='bash $SCRIPT_FILE'" >> "$BASHRC_FILE"
    echo "Alias added. Run 'source $BASHRC_FILE' to apply changes."
else
    echo "Alias $ALIAS_NAME already exists in $BASHRC_FILE."
fi

# Inform user to reload .bashrc
echo "Please run 'source $BASHRC_FILE' to apply the new alias."

