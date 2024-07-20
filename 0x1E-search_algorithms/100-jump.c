#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array
 *               of integers using the Jump search algorithm
 * @array: pointer to the first element of the array to search
 * @size: number of elements in array
 * @value: value to search for
 * 
 * Return: the first index where value is located,
 *         or -1 if value is not present
 */
int jump_search(int *array, size_t size, int value)
{
	int start = 0, end = 0, length = (int) size;

	if (array == NULL || size == 0)
		return (-1);

	while (end < length && array[end] < value)
	{
		printf("Value checked array[%d] = [%d]\n", end, array[end]);
		start = end;
		end += (int) sqrt(length);
	}

	printf("Value found between indexes [%d] and [%d]\n", start, end);

	while (start <= end && start < length)
	{
		printf("Value checked array[%d] = [%d]\n", start, array[start]);
		if (array[start] == value)
			return (start);
		start++;
	}

	return (-1);
}
