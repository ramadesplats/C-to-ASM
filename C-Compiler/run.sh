#!/bin/sh

# compile asm interpreteur
# la taille max de registre, memoire peut changer dans asmfonctions.h
cd asmly
make
cd ..
# compile c compilateur
cd cly
make
cd ..
# compile asm2op opcode generateur
cd asm2oply
make
cd ..

# genere code asm
./cly/parser test.c
# clean les \0 du code asm
tr '\0' " " < result_clair.txt > result_clair_clean.txt
# generate opcode
./asm2oply/asm2op result_clair_clean.txt > result_op.txt
# run asm
./asmly/interpreteur result_clair_clean.txt
