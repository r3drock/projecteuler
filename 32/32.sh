#!/bin/sh
./32.out | sort | uniq | gawk '{$1=$1}; {sum+=$1}END{print sum}'
