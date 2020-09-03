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
	declare -i FILE=$(cat file.txt | wc -l)
	declare -i LINES=$($LEM < file.txt | wc -l)
	declare -i DIFF=$(($LINES - $EXPECTED))
	echo "MINE: $LINES ||| EXPECTED $EXPECTED ||| DIFFIRENCE $DIFF"
	AVG=$[$AVG+$DIFF]
	if [ $DIFF -gt 15 ]
	then
		exit
	fi
	I=$[$I+1]
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

$GEN $flag > file.txt
time $LEM < file.txt > /dev/null
$GEN $flag > file.txt
time $LEM < file.txt > /dev/null
$GEN $flag > file.txt
time $LEM < file.txt > /dev/null
$GEN $flag > file.txt
time $LEM < file.txt > /dev/null
$GEN $flag > file.txt
time $LEM < file.txt > /dev/null

echo "ERROR====================================================="

for t in test/Errors/*; do
	temp=$t
	timeout() {
		time=$2
		expect -c "set echo \"-noecho\"; set timeout $time; spawn $LEM < $temp ; expect timeout { exit 1 } eof { exit 0 }" > /dev/null
		if [ $? = 1 ] ; then
			printf "⌛"
			continue
		elif [ $? = 139 ] ; then
			printf "💥"
			continue
		fi
	}
	timeout 2s
	printf $temp
	VAR=$($LEM < $temp | grep ERROR)
	if [ "$VAR" ]; then
		printf "✅"
	else
		printf "❌"
	fi
	echo " "
done

