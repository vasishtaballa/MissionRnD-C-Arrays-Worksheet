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
#include <stdlib.h>

int  removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL)
		return -1;
	if (len < 0)
		return -1;
	int i, j, p = 0, k = 0;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (Arr[i] == Arr[j])
			{
				Arr[j] = '-';
				k++;
			}
		}
	}
	for (i = 0; i < len; i++)
	{
		if (Arr[i] != 45)
		{
			Arr[p] = Arr[i];
			p++;
		}
	}
	return p;
}