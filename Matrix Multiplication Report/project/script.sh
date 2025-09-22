#!/bin/bash
for i in {1..6}; do for j in 1000 2000 3000 4000 5000 6000 7000 8000 9000; do { time ./project.exe $i $j; } >> result.txt 2>&1 ; done; done 