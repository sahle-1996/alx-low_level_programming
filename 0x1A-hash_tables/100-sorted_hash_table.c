#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the created sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    if (!ht)
        return NULL;

    ht->size = size;
    ht->array = calloc(size, sizeof(shash_node_t *));
    if (!ht->array)
    {
        free(ht);
        return NULL;
    }
    ht->shead = NULL;
    ht->stail = NULL;
    return ht;
}

/**
 * shash_table_set - Adds or updates an element to the sorted hash table
 * @ht: The sorted hash table
 * @key: The key, unique in the hash table
 * @value: The value associated with the key
 *
 * Return: 1 if succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    if (!ht || !key || !*key || !value)
        return 0;

    unsigned long int index = key_index((unsigned char *)key, ht->size);
    shash_node_t *new_node = malloc(sizeof(shash_node_t));
    if (!new_node)
        return 0;

    new_node->key = strdup(key);
    if (!new_node->key)
    {
        free(new_node);
        return 0;
    }
    new_node->value = strdup(value);
    if (!new_node->value)
    {
        free(new_node->key);
        free(new_node);
        return 0;
    }

    shash_node_t **prev_next = &ht->array[index];
    while (*prev_next && strcmp((*prev_next)->key, key) < 0)
        prev_next = &(*prev_next)->snext;

    new_node->snext = *prev_next;
    *prev_next = new_node;

    if (!new_node->snext)
        ht->stail = new_node;
    if (!*prev_next)
        ht->shead = new_node;

    return 1;
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The sorted hash table
 * @key: The key to look for
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    if (!ht || !key)
        return NULL;

    unsigned long int index = key_index((unsigned char *)key, ht->size);
    shash_node_t *node = ht->array[index];
    while (node && strcmp(node->key, key) != 0)
        node = node->snext;

    return node ? node->value : NULL;
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    if (!ht)
        return;

    shash_node_t *node = ht->shead;
    printf("{");
    while (node)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->snext;
        if (node)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    if (!ht)
        return;

    shash_node_t *node = ht->stail;
    printf("{");
    while (node)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->sprev;
        if (node)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
    if (!ht)
        return;

    for (unsigned long int i = 0; i < ht->size; i++)
    {
        shash_node_t *node = ht->array[i];
        while (node)
        {
            shash_node_t *next = node->snext;
            free(node->key);
            free(node->value);
            free(node);
            node = next;
        }
    }

    free(ht->array);
    free(ht);
}
