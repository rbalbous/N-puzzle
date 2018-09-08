#!/usr/bin/ bash

for value in {1..25}
	do
		./generator.py 5 > test4.txt
		cat test4.txt | grep \#
		./npuzzle test4.txt
		sleep 1
	done
