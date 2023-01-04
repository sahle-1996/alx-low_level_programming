#include "main.h"

int len_rec(char *s);
int pali_check(char *s, int len, int index);
int is_palindrome(char *s);

/**
 * len_rec - finds the number of characters in a string.
 * @s: string to be counted.
 * Return: returns the length of the string.
 */

int len_rec(char *s)
{
	int len = 0;

	if (!*s)
		return (0);
	if (*s)
	{
		len++;
		len += len_rec(s + 1);
	}
	return (len);
}

/**
 * pali_check - checks if a string is palindrome.
 * @s: string to be checked.
 * @len: length of string.
 * @index: index of string.
 * Return: returns if palindrome - 1.
 *		returns if not palindrome - 0.
 */

int pali_check(char *s, int len, int index)
{
	if (s[index] == s[len / 2])
		return (1);
	if (s[index] == s[len - index - 1])
		return (pali_check(s, len, index + 1));
	return (0);
}

/**
 * is_palindrome - checks if a string is palindrome
 * @s: string to be checked
 * Return: returns 1 if the string is palindrome
 *	returns 0 if the string is not palindrome
 */

int is_palindrome(char *s)
{
	int len;
	int index = 0;

	len = len_rec(s);

	if (!*s)
		return (1);
	return (pali_check(s, len, index));
}
