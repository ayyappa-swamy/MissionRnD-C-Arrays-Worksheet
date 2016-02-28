/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if ((Arr == NULL) || (len < 0))
		return NULL;
	int index1 = 0, index2 = len - 1, temp;

	for (; index1 <= index2; index1++){
		if (Arr[index1-1] > Arr[index1])
			break;
	}
	index1--;
	if (index1 < index2){
		for (; index2 >= index1; index2--){
			if (Arr[index2] < Arr[index2-1])
				break;
		}
		if (index1 != index2){
			temp = Arr[index1];
			Arr[index1] = Arr[index2];
			Arr[index2] = temp;
		}
	}

	return NULL;
}