/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL)
		return NULL;
	if (len < 0)
		return NULL;
	int i, j = 0, k;
	k = len;
	for (i = 0; i < k; i++)
	{
		if (Arr[i] < num)
			j++;
	}
	Arr = (int *)realloc(Arr, (k + 1) * (sizeof(int)));
	while (k > j)
	{
		Arr[k] = Arr[k - 1];
		k--;
	}
	Arr[j] = num;
	return Arr;
}