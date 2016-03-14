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
	if (Arr == NULL)
		return NULL;
	if (len < 0)
		return NULL;
	int i = 0, k = 0, temp = 0, flag1 = 0, flag2 = 0;
	for (i = 0; i < len; i++)
	{
		if (Arr[i] > Arr[i + 1])
		{
			k = i;
			flag1 = 1;
			break;
		}
	}
	for (i = k + 1; i < len; i++)
	{
		if (Arr[i]>Arr[i + 1])
		{
			temp = i + 1;
			flag2 = 1;
			break;
		}
	}
	if (flag1 == 1 && flag2 == 1)
	{
		int d = Arr[temp];
		Arr[temp] = Arr[k];
		Arr[k] = d;
	}
	return Arr;
}