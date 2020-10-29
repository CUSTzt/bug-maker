#!/usr/bin/env bash
g++ -o A A.cpp -O2 -std=c++11
g++ -o OK OK.cpp -O2 -std=c++11
while true; do
    ./gen > in.txt
    ./OK < in.txt > stdout
    ./A < in.txt > out
    if test $? -ne 0; then
        exit 0
    fi
    if diff stdout out; then
        printf "AC\n"
    else
        printf "GG\n"
        exit 0
    fi
done