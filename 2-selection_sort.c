#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array:cointains the elements
 * @size:number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, smaller;

	if (size < 2)
	{
		return;
	}
	for (i = 1; i < size; i++)
	{
		smaller = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smaller])
			{
				smaller = j;
			}
		}
			if (i != smaller)
			{
				temp = array[j];
				array[j] = array[smaller];
				array[smaller] = temp;
				print_array(array, size);
			}
	}
}
