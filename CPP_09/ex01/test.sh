#!/bin/bash

echo "===== VALID TESTS ====="

echo 'Test: ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"'
echo "Expected: 42"
echo "Output: " 
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo "----------------------"

echo 'Test: ./RPN "7 7 * 7 -"'
echo "Expected: 42"
echo "Output: " 
./RPN "7 7 * 7 -"
echo "----------------------"

echo 'Test: ./RPN "1 2 * 2 / 2 * 2 4 - +"'
echo "Expected: 0"
echo "Output: " 
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo "----------------------"

echo 'Test: ./RPN "3 4 +"'
echo "Expected: 7"
echo "Output: " 
./RPN "3 4 +"
echo "----------------------"

echo 'Test: ./RPN "5 1 2 + 4 * + 3 -"'
echo "Expected: 14"
echo "Output: " 
./RPN "5 1 2 + 4 * + 3 -"
echo "----------------------"

echo 'Test: ./RPN "9 3 /"'
echo "Expected: 3"
echo "Output: " 
./RPN "9 3 /"
echo "----------------------"

echo 'Test: ./RPN "0 0 +"'
echo "Expected: 0"
echo "Output: " 
./RPN "0 0 +"
echo "----------------------"

echo 'Test: ./RPN "9 9 9 9 + + +"'
echo "Expected: 36"
echo "Output: " 
./RPN "9 9 9 9 + + +"
echo "----------------------"

echo 'Test: ./RPN "1 2 * 3 4 * +"'
echo "Expected: 14"
echo "Output: " 
./RPN "1 2 * 3 4 * +"
echo "----------------------"

echo ""
echo "===== INVALID TESTS ====="

echo 'Test: ./RPN "(1 + 1)'
echo "Expected: Error"
echo "Output: " 
./RPN "(1 + 1)"
echo "----------------------"

echo 'Test: ./RPN "+"'
echo "Expected: Error"
echo "Output: " 
./RPN "+"
echo "----------------------"

echo 'Test: ./RPN "1 +"'
echo "Expected: Error"
echo "Output: " 
./RPN "1 +"
echo "----------------------"

echo 'Test: ./RPN "1 2"'
echo "Expected: Error"
echo "Output: " 
./RPN "1 2"
echo "----------------------"

echo 'Test: ./RPN "1 2 + +"'
echo "Expected: Error"
echo "Output: " 
./RPN "1 2 + +"
echo "----------------------"

echo 'Test: ./RPN "4 0 /"'
echo "Expected: Error"
echo "Output: " 
./RPN "4 0 /"
echo "----------------------"

echo 'Test: ./RPN "a b +"'
echo "Expected: Error"
echo "Output: " 
./RPN "a b +"
echo "----------------------"

echo 'Test: ./RPN "1 2 + 3"'
echo "Expected: Error"
echo "Output: " 
./RPN "1 2 + 3"
echo "----------------------"
