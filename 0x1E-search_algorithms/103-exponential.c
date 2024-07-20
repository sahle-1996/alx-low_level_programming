#include "search_algos.h"

/**
 * display_array - prints an array from index l to r
 * @array: the array to print
 * @l: the left index
 * @r: the right index
 */
void display_array(int *array, int l, int r)
{
	int i;

	for (i = l; i <= r; i++)
	{
		printf("%d", array[i]);
		if (i < r)
			printf(", ");
	}
	printf("\n");
}

/**
 * exponential_search - searches for a value in an array using
 *                      the exponential search algorithm
 * @array: array of integers
 * @size: size of the array
 * @value: the value to search for
 * Return: the index of the value, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	int bound = 1, prev = 0;

	if (!array || size == 0)
		return (-1);

	if (array[0] == value)
		return (0);

	while (bound < (int)size && array[bound] < value)
	{
		printf("Value checked array[%d] = [%d]\n", bound, array[bound]);
		prev = bound;
		bound *= 2;
	}

	if (bound >= (int)size)
		bound = (int)size - 1;

	printf("Value found between indexes [%d] and [%d]\n", prev, bound);
	return binary_search_ex(array, prev, bound, value);
}

/**
 * binary_search_ex - auxiliary function for binary search within bounds
 * @array: array of integers
 * @left: left index of the subarray
 * @right: right index of the subarray
 * @value: the value to search for
 * Return: the index of the value, or -1 if not found
 */
int binary_search_ex(int *array, int left, int right, int value)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		printf("Searching in array: ");
		display_array(array, left, right);
		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
