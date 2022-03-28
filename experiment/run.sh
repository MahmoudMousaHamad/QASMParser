#!/bin/bash

QASM_FILES="$(find ./ -type f -name *.qasm)"
PARSER="../src/qasm_parser"
CX_OPS="patterns.txt"

# Make Parser
make -C ../src

# Rm CX operations file
rm $CX_OPS

for file in $QASM_FILES; do
    echo $file
    $PARSER $file
done