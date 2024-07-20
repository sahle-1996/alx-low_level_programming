#include "search_algos.h"

/**
 * show_array - displays elements of an array between two indices
 * @array: the array to display
 * @start: the starting index
 * @end: the ending index
 */
void show_array(int *array, int start, int end)
{
    int i;

    for (i = start; i <= end; i++)
    {
        printf("%d", array[i]);
        if (i < end)
            printf(", ");
    }
    printf("\n");
}

/**
 * recursive_binary - performs binary search on a subarray recursively
 * @array: pointer to the array of integers
 * @left: starting index of the subarray
 * @right: ending index of the subarray
 * @value: value to search for
 * 
 * Return: index of the value if found, otherwise -1
 */
int recursive_binary(int *array, int left, int right, int value)
{
    int mid = (left + right) / 2;

    printf("Searching in array: ");
    show_array(array, left, right);

    if (left > right)
        return (-1);

    if (array[mid] == value)
    {
        if (mid == left || array[mid - 1] != value)
            return (mid);
        else
            return (recursive_binary(array, left, mid - 1, value));
    }
    else if (value < array[mid])
        return (recursive_binary(array, left, mid - 1, value));
    else
        return (recursive_binary(array, mid + 1, right, value));
}

/**
 * binary_search_advanced - searches for a value in a sorted array
 *                           using an advanced binary search algorithm
 * @array: pointer to the array of integers
 * @size: number of elements in the array
 * @value: value to search for
 * 
 * Return: index of the value if found, otherwise -1
 */
int binary_search_advanced(int *array, size_t size, int value)
{
    if (!array || size == 0)
        return (-1);
    return (recursive_binary(array, 0, (int)size - 1, value));
}
