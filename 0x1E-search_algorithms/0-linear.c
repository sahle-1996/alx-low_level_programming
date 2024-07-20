#include "search_algos.h"

/**
  * linear_search - searches for a value in an array
  * @array: pointer to the first element of the array
  * @size: number of elements in the array
  * @value: value to search for
  * Return: the first index where value is located, or -1 if not found
*/
int linear_search(int *array, size_t size, int value)
{
	size_t idx;

	if (array == NULL || size == 0)
		return (-1);

	for (idx = 0; idx < size; idx++)
	{
		printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);
		if (array[idx] == value)
			return (idx);
	}

	return (-1);
}
