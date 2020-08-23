#!/bin/sh

GEN="./generator"
LEM="./lem-in"
flag=" --flow-one"
declare -i I=0
declare -i AVG=0
while [ $I -lt 15 ]
do
	MAP=$($GEN $flag > file.txt)
	declare -i EXPECTED=$(cat file.txt | tail -n 1 | cut -d ' ' -f 8)
	declare -i LINES=$($LEM file.txt | wc -l)
	declare -i DIFF=$(($LINES - $EXPECTED))
	echo "MINE: $LINES ||| EXPECTED $EXPECTED ||| DIFFIRENCE $DIFF"
	AVG=$[$AVG+$DIFF]
	I=$[$I+1]
	if ! ((I % 3))
	then
		echo "				THE AVARAGE OF $flag = $[$AVG/3]"
		AVG=0
		AVG_TIME=0
		case $I in
			3) flag=" --flow-ten";;
			6) flag=" --flow-thousand";;
			9) flag=" --big";;
			12) flag=" --big-superposition";;
		esac
		echo "_________________________"
	fi
done

echo "TIME====================================================="

