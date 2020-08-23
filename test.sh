#!/bin/sh

GEN="./generator"
LEM="./lem-in"
flag=" --flow-one"
declare -i I=0
declare -i AVG=0
while [ $I -lt 500 ]
do
	MAP=$($GEN $flag > file.txt)
	declare -i EXPECTED=$(cat file.txt | tail -n 1 | cut -d ' ' -f 8)
	declare -i LINES=$($LEM file.txt | wc -l)
	declare -i DIFF=$(($LINES - $EXPECTED))
	echo "MINE: $LINES ||| EXPECTED $EXPECTED ||| DIFFIRENCE $DIFF"
	AVG=$[$AVG+$DIFF]
	I=$[$I+1]
	if ((DIFF > 15))
	then
		exit 1
	fi
	if ! ((I % 100))
	then
		echo "				THE AVARAGE OF $flag = $[$AVG/100]"
		AVG=0
		AVG_TIME=0
		case $I in
			100) flag=" --flow-ten";;
			200) flag=" --flow-thousand";;
			300) flag=" --big";;
			400) flag=" --big-superposition";;
		esac
		echo "_________________________"
	fi
done

echo "TIME====================================================="

