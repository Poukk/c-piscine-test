# 42 Piscine Test Automation

This repository provides a script to automate the testing of exercises for the 42 piscine. The script compiles your exercises, checks them against the norminette, and runs the tests for you. It also includes colored and icon-enhanced output to make the process more user-friendly.

## Installation

To install and run the testing script, open your terminal and follow these steps:

```bash
curl -O https://raw.githubusercontent.com/Poukk/c-piscine-test/main/setup.sh
chmod +x /setup.sh
./setup.sh
rm /setup.sh
```

## Usage

Once installed, you can test your exercises by running the `cpt` (C Piscine Test) command:

```bash
cpt
```

This command will prompt you to input the list number (C00, C01, etc.) and the exercise number (ex00, ex01, etc.) you want to test.
###### Key points:
- If the exercises asks for a function, don't leave any other thing in the file other than the function and complementary functions. That is, **don't leave a main function in a function exercise.**
- Run the command inside the directory with the exercises folders(ex00, ex01, etc.). **Don't use inside exercises folders**.
- When prompted to input the list and exercise number, make sure to type two digits. If you want to test List C01, type `01`.

## Updating

To update the script with the latest changes from the repository, use the following command:

```bash
cpt --upgrade
```

This will pull the latest version of the script from the GitHub repository.

## Contributing

If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.
