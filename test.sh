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
	declare -i LINES=$($LEM < file.txt | wc -l)
	declare -i DIFF=$(($LINES - $EXPECTED))
	echo "MINE: $LINES ||| EXPECTED $EXPECTED ||| DIFFIRENCE $DIFF"
	AVG=$[$AVG+$DIFF]
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

error=("test/Errors/empty_file_1"
"test/Errors/empty_file_2"
"test/Errors/empty_line_1"
"test/Errors/empty_line_2"
"test/Errors/empty_line_3"
"test/Errors/empty_line_4"
"test/Errors/empty_line_5"
"test/Errors/empty_line_6"
"test/Errors/empty_line_7"
"test/Errors/empty_line_8"
"test/Errors/empty_line_9"
"test/Errors/empty_line_10"
"test/Errors/instruction_error_1"
"test/Errors/invalid_room_name_1"
"test/Errors/invalid_room_name_2"
"test/Errors/invalid_room_name_3"
"test/Errors/invalid_room_name_4"
"test/Errors/invalid_room_name_5"
"test/Errors/invalid_room_name_6"
"test/Errors/invalid_room_name_7"
"test/Errors/invalid_room_name_8"
"test/Errors/no_connections_1"
"test/Errors/no_connections_2"
"test/Errors/no_connections_3"
"test/Errors/no_connections_4_MissingNewline"
"test/Errors/number_of_ants_empty_line"
"test/Errors/number_of_ants_invalid_number_1"
"test/Errors/number_of_ants_invalid_number_2"
"test/Errors/number_of_ants_invalid_number_3"
"test/Errors/number_of_ants_invalid_number_4"
"test/Errors/number_of_ants_negative_number"
"test/Errors/number_of_ants_zero"
)

for t in ${!error[@]}; do
	temp=${error[$t]}
	timeout() {
		time=$1
		expect -c "set echo \"-noecho\"; set timeout $time; spawn $LEM < $temp ; expect timeout { exit 1 } eof { exit 0 }" > /dev/null
		if [ $? = 1 ] ; then
			printf "⌛"
			continue
		elif [ $? = 139 ] ; then
			printf "💥"
			continue
		fi
	}
	timeout 1s
	VAR=$($LEM < $temp 2>&1)
	if [ "$VAR" ]; then
		printf "✅"
	else
		printf "❌"
	fi
done

