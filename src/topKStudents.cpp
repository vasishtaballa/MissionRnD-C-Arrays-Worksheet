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
void * mergearray(struct student *students, int i, int j);
void * dividing(struct student *students, int i, int j);

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) 
{
	if (students == NULL)
		return NULL;
	if (len < 0)
		return NULL;
	if (K < 0)
		return NULL;
	if (K == 0)
		return NULL;
	if (K>len)
		K = len;
	int i, j;
	dividing(students, 0, len - 1);
	struct student **result = (student **)malloc(sizeof(student)*K);
	for (int i = 0; i < K; i++)
	{
		result[i] = &students[i];
	}
	return result;
}

void * dividing(struct student *students, int i, int j)
{
	int k, mid = 0;
	if (i >= j)
		return students;
	mid = (i + j) / 2;
	dividing(students, i, mid);
	dividing(students, mid + 1, j);
	mergearray(students, i, j);
	return students;
}
void * mergearray(struct student *students, int i, int j)
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