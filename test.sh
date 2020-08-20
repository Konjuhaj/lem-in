#!/bin/sh
lemin="time ./lem-in"
echo "big.txt should be 53"
$lemin big.txt | wc -l
echo "mymap.txt should be 23"
$lemin mymap.txt | wc -l
echo "Superposition 1 should be 68"
$lemin test/flow-big-superposition_1 | wc -l
echo "Superposition 2 should be 74"
$lemin test/flow-big-superposition_2 | wc -l
echo "Superposition 3 should be 65"
$lemin test/flow-big-superposition_3 | wc -l
echo "Superposition 4 should be 86"
$lemin test/flow-big-superposition_4 | wc -l
echo "Superposition 5 should be 81"
$lemin test/flow-big-superposition_5 | wc -l
echo "Superposition 6 should be 83"
$lemin test/flow-big-superposition_6 | wc -l
echo "Superposition 7 should be 77"
$lemin test/flow-big-superposition_7 | wc -l
echo "Superposition 8 should be 94"
$lemin test/flow-big-superposition_8 | wc -l
echo "file_vaikea should be 8"
$lemin test/test_file_vaikea | wc -l
echo "flow-big should be 73"
$lemin test/flow-big| wc -l
