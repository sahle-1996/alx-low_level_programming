#include "function_pointers.h"

/**
 * print_name - Prints a name
 * @name: String to be printed
 * @f: Pointer to function to be called back
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
