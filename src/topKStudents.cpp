/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	if ((students == NULL) || (len < 0) || (K <= 0))
		return NULL;

	struct student ** studentsResult = (struct student **)malloc(len*sizeof(struct student *));
	int ind1, ind2,temp;

	for (int i = 0; i < len; i++)
		studentsResult[i] = &students[i];
	if (K >= len)
		return studentsResult;
	else {
		if (K > len - K){
			for (ind1 = 0; ind1 < len-K; ind1++){
				for (ind2 = 1; ind2 < len-ind1; ind2++){
					if (studentsResult[ind2]->score > studentsResult[ind2-1]->score){
						temp = studentsResult[ind2]->score;
						studentsResult[ind2]->score = studentsResult[ind2-1]->score;
						studentsResult[ind2 - 1]->score = temp;
					}
				}
			}

			studentsResult[len - ind1] = NULL;
			return studentsResult;
		}
		else {
			for (ind1 = 0; ind1 < K; ind1++){
				for (ind2 = len-1; ind2 > ind1; ind2--){
					if (studentsResult[ind2]->score > studentsResult[ind2-1]->score){
						temp = studentsResult[ind2]->score;
						studentsResult[ind2]->score = studentsResult[ind2-1]->score;
						studentsResult[ind2 - 1]->score = temp;
					}
				}
			}

			studentsResult[ind1] = NULL;
			return studentsResult;
		}
	}
}