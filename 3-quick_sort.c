#include "sort.h"

/**
 * swap_values - interchanges the values
 * @m:first value
 * @n:second value
 */

void swap_values(int *m, int *n)
{
	int temp;

	temp = *m;
	*m = *n;
	*n = temp;
}

/**
 * lomuto_divide - divides array into two partitions
 * @array:numbers
 * @size:number of elements in the array
 * @low:leftmost index
 * @high:rightmost index
 *
 * Return:last
 */

int lomuto_divide(int *array, size_t size, int low, int high)
{
	int *pivot;
	int floor, ceiling;

	pivot = array + high;
	for (ceiling = floor = low; floor < high; floor++)
	{
		if (array[floor] < *pivot)
		{
			if (ceiling < floor)
			{
				swap_values(array + floor, array + ceiling);
				print_array(array, size);
			}
			ceiling++;
		}
	}
	if (array[ceiling] > *pivot)
	{
		swap_values(array + ceiling, pivot);
		print_array(array, size);
	}
	return (ceiling);
}

/**
 * lomuto_sorting - quick sorts algorithm
 * @array:numbers
 * @size:number of elements in the array
 * @low:leftmost index
 * @high:rightmost index
 */

void lomuto_sorting(int *array, size_t size, int low, int high)
{
	int x;

	if (high - low > 0)
	{
		x = lomuto_divide(array, size, low, high);
		lomuto_sorting(array, size, low, x - 1);
		lomuto_sorting(array, size, x + 1, high);
	}
}

/**
 * quick_sort - sorts an array on integers in ascending order
 * using quick sort
 * @array:container that stores the integers
 * @size:number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	else
	{
		lomuto_sorting(array, size, 0, size - 1);
	}
}
