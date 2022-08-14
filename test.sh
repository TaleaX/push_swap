#!/bin/bash

rm -rf push_swap_result

for first in {1..8}; do
	for sec in {1..8}; do
		for third in {1..8}; do
			for fourth in {1..8}; do
				for fifth in {1..8}; do
					for sixth in {1..8}; do
						for sev in {1..8}; do
							for eig in {1..8}; do
								if [ "$first" -eq "$sec" ] || [ "$first" -eq "$third" ] || [ "$first" -eq "$third" ] || [ "$first" -eq "$fourth" ] || [ "$first" -eq "$fifth" ] || [ "$first" -eq "$sixth" ] || [ "$first" -eq "$sev" ] || [ "$first" -eq "$eig" ] || [ "$sec" -eq "$third" ] || [ "$sec" -eq "$fourth" ] || [ "$sec" -eq "$fifth" ] || [ "$sec" -eq "$sixth" ] || [ "$sec" -eq "$sev" ] || [ "$sec" -eq "$eig" ] || [ "$third" -eq "$fourth" ] || [ "$third" -eq "$fifth" ] || [ "$third" -eq "$sixth" ] || [ "$third" -eq "$sev" ] || [ "$third" -eq "$eig" ] || [ "$fourth" -eq "$fifth" ] || [ "$fourth" -eq "$sixth" ] || [ "$fourth" -eq "$sev" ] || [ "$fourth" -eq "$eig" ] || [ "$fifth" -eq "$sixth" ] || [ "$fifth" -eq "$sev" ] || [ "$fifth" -eq "$eig" ] || [ "$six" -eq "$sev" ] || [ "$six" -eq "$eig" ] || [ "$sev" -eq "$eig" ] 2>/dev/null; then
									continue
								fi
								./push_swap $first $sec $third $fourth $fifth $sixth $sev >> push_swap_result
							done
						done
					done
				done
			done
			
			#args+=($first $sec $third)
		done
	done
done

#echo ${args[@]}

#./push_swap ${args[@]}