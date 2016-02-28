/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void swapElementsInArray(struct student *Arr, int ind1, int ind2){
	int temp = Arr[ind1].score;
	Arr[ind1].score = Arr[ind2].score;
	
	Arr[ind2].score = temp;
	return;
}

int partition(struct student *students, int left, int right)
{
	int pivotValue = students[left].score, leftInd, rightInd;

	if (left < right){
		leftInd = left + 1;
		rightInd = leftInd;

		while (rightInd < right){
			while (students[leftInd].score >= pivotValue){
				if (leftInd == right)
					break;
				else leftInd++;
			}
			rightInd = leftInd + 1;

			while (students[rightInd].score <= pivotValue){
				if (rightInd >= right)
					break;
				else rightInd++;
			}

			if ((students[rightInd].score > pivotValue) && (rightInd <= right))
				swapElementsInArray(students, leftInd, rightInd);
		}

		if (students[leftInd].score < pivotValue)
			swapElementsInArray(students, leftInd - 1, left);
		else swapElementsInArray(students, leftInd, left);
	}
	return leftInd - 1;
}

void quickSort(struct student *students, int left, int right)
{
	if (left < right){
		int mid = partition(students, left, right);

		quickSort(students, left, mid - 1);
		quickSort(students, mid + 1, right);
	}
}

void * scoresDescendingSort(struct student *students, int len) {
	if ((students == NULL) || (len <= 0))
		return NULL;
	else if (len != 1){
		quickSort(students, 0, len-1);
	}
}