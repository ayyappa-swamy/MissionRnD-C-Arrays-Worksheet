#include "FunctionHeadersArrays1.h"
#include <stdio.h>

int main(){

	//Test RemoveArraysDuplicates
	/*
	int arr[3] = { 1, 2, 7 };
	int len = removeArrayDuplicates(arr, 3);
	printf("%d", len);
	*/

	//Test Students Count
	/*
	int arr2[3]={1,4,10};
	int *newarray=sortedArrayInsertNumber(arr, 3, 3);
	printf("%d %d %d %d", newarray[0], newarray[1], newarray[2],newarray[3]);
	*/
	int Arr[5] = { 1, 2, 1, 1, 2 };
	removeArrayDuplicates(Arr, 5);

	int ind = 0;

	for (ind = 0; ind < 5; ind++)
		printf("%d ", Arr[ind]);
	
	return 0;
}