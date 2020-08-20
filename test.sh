#!/bin/sh

GEN="./generator"
LEM="./lem-in"
flag=" --flow-one"
declare -i I=0
declare -i AVG=0
while [ $I -lt 25 ]
do
	MAP=$($GEN $flag > file.txt)
	declare -i EXPECTED=$(cat file.txt | tail -n 1 | cut -d ' ' -f 8)
	declare -i LINES=$($LEM file.txt | wc -l)
	declare -i DIFF=$(($LINES - $EXPECTED))
	echo "MINE: $LINES ||| EXPECTED $EXPECTED ||| DIFFIRENCE $DIFF"
	AVG=$[$AVG+$DIFF]
	I=$[$I+1]
	if ((DIFF > 20))
	then
		exit 1
	fi
	if ! ((I % 5))
	then
		echo "				THE AVARAGE OF $flag = $[$AVG/5]"
		AVG=0
		AVG_TIME=0
		case $I in
			5) flag=" --flow-ten";;
			10) flag=" --flow-thousand";;
			15) flag=" --big";;
			20) flag=" --big-superposition";;
		esac
		echo "_________________________"
	fi
done

