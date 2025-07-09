#!/bin/bash
# Check: www.inchcalculator.com/scientific-notation-calculator/

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

EXEC=./convert

# Function to run a single test case.
# Arguments:
#   $1 = input to test (string)
#	shift removes the first argument from the list, then becomes the next
#   expected... = expected output substrings to match (one or more)
run_test() {
    local input="$1"
    shift
    local expected=("$@")

    echo -e "${BLUE}Testing input: '${input}'${NC}"

    # Run the executable and capture output
    output=$($EXEC "$input" 2>&1)
    echo -e "Output:\n$output"

    # Check if all expected patterns are found in the output
    local fail=0
    for pattern in "${expected[@]}"; do
        if [[ "$output" != *"$pattern"* ]]; then
            echo -e "${RED}FAIL:${NC} Expected pattern not found: '${pattern}'"
            fail=1
        fi
    done

    if [[ $fail -eq 0 ]]; then
        echo -e "${GREEN}PASS${NC}: All expected patterns matched."
    else
        echo -e "${RED}Test failed for input '${input}'${NC}"
    fi

    echo "-------------------------------------"
    echo
}

# Compile your program
make all

echo -e "${YELLOW}Starting ScalarConverter tests...${NC}"
echo

# Examples of test cases
run_test "a" "char: 'a'" "int: 97" "float: 97.0f" "double: 97.0"
run_test "42" "char: '*'" "int: 42" "float: 42.0f" "double: 42.0"
run_test "-42" "char: Non Displayable" "int: -42" "float: -42.0f" "double: -42.0"
run_test "3.14f" "char: Non Displayable" "int: 3" "float: 3.14f" "double: 3.14"
run_test "100000000" "char: impossible" "int: 100000000" "float: 1e+08.0f" "double: 1e+08.0" 
run_test "nan" "char: impossible" "int: impossible" "float: nanf" "double: nan"
run_test "2147483648" "int: impossible" # test overflow case

echo -e "${YELLOW}All tests done.${NC}"
