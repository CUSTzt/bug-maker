#!/usr/bin/env bash
g++ -o r matrix.cpp -O2 -std=c++11
g++ -o std std.cpp -O2 -std=c++11
while true; do
    # python gen.py > in
    ./std < data.in > stdout
    ./r < data.in > out
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