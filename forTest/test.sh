#!/bin/bash

function func() {
	str=$1

	reference=$(echo "$str" | bc)

	result=$(echo "$str" | ../build/calc -result)

	if [ $reference == $result ]
	then
		echo "OK. $str = $reference, result = $result"
	else
		echo "ERROR. $str = $reference, result = $result"
	fi
}

arr[0]="5 * 4 + (40 * 3 + 5 * 20) + (60 - 10) * 2"
arr[1]="5 + 60 - 10 * 2"
arr[2]="5 * 4 + 40 * 3 + 5 * 20 + 60 - 10 * 3"
arr[3]="5 * 4 + (40 * 3 + 5 * 20) + (60 - 10) * 2"
arr[4]="5 * 4 + (40 * (3 + (25 + 30) * 10) + 5 * 20) + (60 - 10) * 2"
arr[5]="5 * 4 + (40 * (3 + 5) * 20) + (60 - 10) * 2"

for var in "${arr[@]}"
do
	func "$var"
done



