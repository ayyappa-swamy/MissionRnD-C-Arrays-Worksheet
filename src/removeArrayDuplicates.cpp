/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void swapElementsInArray(int *Arr, int ind1, int ind2){
	int temp = Arr[ind1];
	Arr[ind1] = Arr[ind2];
	Arr[ind2] = temp;
	return;
}

int removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len < 0)
		return -1;

	int ind1 = 0,ind2 = 0, count = 0;

	for (ind1 = 0; ind1 < len;){
		for (ind2 = ind1+1; ind2 < len; ind2++){
			if (Arr[ind2] == Arr[ind1]){
				count++;
				Arr[ind2] = -1;
			}
		}
		ind1++;
		while ((Arr[ind1] == -1) && (ind1 < len))
			ind1++;
		if (ind1 == len)
			break;
	}

	int ind = 0;

	for (ind = 0; ind < 5; ind++)
		printf("%d ", Arr[ind]);

	ind2 = 0;
	
	ind1 = 0;
	if (count < len){
		while (ind2 < len){
			while ((Arr[ind1] != -1) && (ind1 < len))
					ind1++;
			ind2 = ind1+1;
			while ((Arr[ind2] == -1) && (ind2 < len))
				ind2++;
			if (ind2 < len) 
				swapElementsInArray(Arr, ind1, ind2);
			ind1++;
		}
	}
	
	return len-count;
}