#include "function_pointers.h"

/**
 * int_index - Searches for an integer
 * @array: Array to be searched
 * @size: Size of the array
 * @cmp: Pointer to function to be executed
 *
 * Return: Nothing.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0)
		return (-1);

	if (array != NULL &&  cmp != NULL)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}
	return (-1);
}
