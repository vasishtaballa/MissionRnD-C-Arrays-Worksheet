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
void * breaking(struct student *students, int i, int j);
void * merge(struct student *students, int i, int j);

struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) 
{
	if (students == NULL)
		return NULL;
	if (len < 0)
		return NULL;
	int i, j;
	breaking(students, 0, len - 1);
	return NULL;
}

void * breaking(struct student *students, int i, int j)
{
	int k, mid = 0;
	if (i >= j)
		return students;
	mid = (i + j) / 2;
	breaking(students, i, mid);
	breaking(students, mid + 1, j);
	merge(students, i, j);
	return students;
}
void * merge(struct student *students, int i, int j)
{
	int k, mid, l, p;
	struct student b[100];
	p = i;
	mid = (i + j) / 2;
	k = mid + 1;
	l = i;
	while (i <= mid && k <= j)
	{
		if (students[i].score >= students[k].score)
			b[l++] = students[i++];
		else
			b[l++] = students[k++];
	}
	if (i > mid)
	{
		for (; k <= j;)
			b[l++] = students[k++];
	}
	else if (k > j)
	{
		for (; i <= mid;)
			b[l++] = students[i++];
	}
	for (l = p; l <= j; l++)
		students[l] = b[l];
	return students;
}