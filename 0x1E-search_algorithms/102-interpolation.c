#include "search_algos.h"

/**
 * interpolation_search - searches for a value in an array of
 *                        integers using the interpolation search algorithm
 * @array: array of integers
 * @size: size of the array
 * @value: the value to search for
 * 
 * Return: the index of the value, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t start, pos, end;

	start = 0;
	end = size - 1;

	if (!array || size == 0)
		return (-1);

	while (array[start] != array[end] && value >= array[start] && value <= array[end])
	{
		pos = start + (((double)(end - start) / (array[end] - array[start])) * (value - array[start]));

		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);

		if (array[pos] < value)
			start = pos + 1;
		else if (array[pos] > value)
			end = pos - 1;
		else
			return (pos);
	}

	pos = start + (((double)(end - start) / (array[end] - array[start])) * (value - array[start]));
	printf("Value checked array[%ld] is out of range\n", pos);

	return (-1);
}
