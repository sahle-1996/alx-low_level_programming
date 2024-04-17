#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: is the hash table you want to add or update the key/value to
 * @key: is the key. key can not be an empty string
 * @value: is the value associated with the key. value must be duplicated.
 *         value can be an empty string
 *
 * Return: 1 if it succeeded, 0 otherwise
 * In case of collision, add the new node at the beginning of the list
 **/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
        unsigned long int idx;
        hash_node_t *new_node, *temp;

        if (!ht || !key || !*key || !value)
                return (0);

        idx = key_index((const unsigned char *)key, ht->size);
        temp = ht->array[idx];

        while (temp)
        {
                if (strcmp(temp->key, key) == 0)
                {
                        free(temp->value);
                        temp->value = strdup(value);
                        return (1);
                }
                temp = temp->next;
        }
        new_node = malloc(sizeof(hash_node_t));
        if (!new_node)
                return (0);

        new_node->key = strdup(key);
        if (!new_node->key)
        {
                free(new_node);
                return (0);
        }

        new_node->value = strdup(value);
        if (!new_node->value)
        {
                free(new_node->key);
                free(new_node);
                return (0);
        }

        new_node->next = ht->array[idx];
        ht->array[idx] = new_node;

        return (1);
}
