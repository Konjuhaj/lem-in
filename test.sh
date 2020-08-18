#!/bin/sh
echo "big.txt should be 53"
time ./lem-in big.txt | wc -l
echo "mymap.txt should be 23"
time ./lem-in mymap.txt | wc -l
echo "Superposition 1 should be 68"
time ./lem-in test/flow-big-superposition_1 | wc -l
echo "Superposition 2 should be 74"
time ./lem-in test/flow-big-superposition_2 | wc -l
echo "Superposition 3 should be 65"
time ./lem-in test/flow-big-superposition_3 | wc -l
echo "Superposition 4 should be 86"
time ./lem-in test/flow-big-superposition_4 | wc -l
echo "Superposition 5 should be 81"
time ./lem-in test/flow-big-superposition_5 | wc -l
echo "Superposition 6 should be 83"
time ./lem-in test/flow-big-superposition_6 | wc -l
echo "Superposition 7 should be 77"
time ./lem-in test/flow-big-superposition_7 | wc -l
echo "Superposition 8 should be 94"
time ./lem-in test/flow-big-superposition_8 | wc -l
echo "file_vaikea should be 8"
time ./lem-in test/test_file_vaikea | wc -l
echo "flow-big should be 73"
time ./lem-in test/flow-big| wc -l
