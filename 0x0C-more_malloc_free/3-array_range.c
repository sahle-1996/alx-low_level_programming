#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers ordered
 *               from min to max, inclusive
 * @min: The first value of the array
 * @max: The last value of the array
 *
 * Return: If min > max or the function fails - NULL
 *         Otherwise - a pointer to the newly created array
 */

int *array_range(int min, int max)
{
	int *arr;
	int index, size;

	if (min > max)
		return (NULL);

	size = (max - min) + 1;

	arr = malloc(size * sizeof(int));

	if (arr == NULL)
		return (NULL);

	for (index = 0; min <= max; index++)
		arr[index] = min++;

	return (arr);
}
