#include "hash_tables.h"

/**
 * shash_table_set - Adds or updates an element to the sorted hash table
 * @ht: The sorted hash table
 * @key: The key, unique in the hash table
 * @value: The value associated with the key
 * Return: 1 if succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
        unsigned long int index;
        shash_node_t *new, *curr;

        if (!ht || !key || !*key || !value)
                return (0);

        index = key_index((unsigned char *)key, ht->size);
        curr = ht->array[index];
        while (curr && strcmp(curr->key, key))
                curr = curr->next;

        if (curr)
        {
                free(curr->value);
                curr->value = strdup(value);
                return (1);
        }

        new = malloc(sizeof(shash_node_t));
        if (!new)
                return (0);
        new->key = strdup(key);
        new->value = strdup(value);
        new->next = ht->array[index];
        ht->array[index] = new;

        new->snext = NULL;
        new->sprev = ht->stail;
        if (ht->stail)
                ht->stail->snext = new;
        ht->stail = new;
        if (!ht->shead)
                ht->shead = new;

        return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The sorted hash table
 * @key: The key to look for
 * Return: The value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
        unsigned long int index;
        shash_node_t *curr;

        if (!ht || !key || !*key)
                return (NULL);

        index = key_index((unsigned char *)key, ht->size);
        curr = ht->array[index];
        while (curr && strcmp(curr->key, key))
                curr = curr->next;

        return (curr ? curr->value : NULL);
}

/**
* shash_table_print - Prints a sorted hash table
* @ht: The sorted hash table
* 
* Return: void
*/
void shash_table_print(const shash_table_t *ht)
{
        shash_node_t *curr;

        if (!ht)
                return;

        curr = ht->shead;
        while (curr)
        {
                printf("'%s': '%s'", curr->key, curr->value);
                curr = curr->snext;
                if (curr)
                printf(", ");
        }
        printf("\n");
}

/**
* shash_table_print_rev - Prints a sorted
*       hash table in reverse order
* @ht: The sorted hash table
*
*Return: void
*/
void shash_table_print_rev(const shash_table_t *ht)
{
        shash_node_t *temp = ht->stail;
        if (!ht)
                return;

        while (temp)
        {
                printf("%s: %s\n", temp->key, temp->value);
                temp = temp->sprev;
        }
}

/**
* shash_table_delete - Deletes a sorted hash table
* @ht: The sorted hash table
*
* Return: void
*/
void shash_table_delete(shash_table_t *ht)
{
        unsigned int i;
        shash_node_t *temp, *temp_del;
        if (!ht)
                return;

        for (i = 0; i < ht->size; i++)
        {
                temp = ht->array[i];
                while (temp)
                {
                        temp_del = temp;
                        temp = temp->next;
                        free(temp_del->key);
                        free(temp_del->value);
                        free(temp_del);
                }
        }

        free(ht->array);
        free(ht);
}
