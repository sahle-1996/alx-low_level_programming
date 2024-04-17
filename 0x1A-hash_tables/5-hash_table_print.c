#include "hash_tables.h"

/**
 * hash_table_print - print a hash table
 * @ht: is the hash table
 *
 * Return: void
 **/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *temp;
	char *delimiter = "";

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp)
		{
			printf("%s'%s': '%s'", delimiter, temp->key, temp->value);
			delimiter = ", ";
			temp = temp->next;
		}
	}
	printf("}\n");
}
