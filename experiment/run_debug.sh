#!/bin/bash

rm ../src/qasm_parser

make -C ../src

../src/qasm_parser ../experiment/QASMBench/small/vqe_uccsd_n4/vqe_uccsd_n4.qasm > debug_result.txt