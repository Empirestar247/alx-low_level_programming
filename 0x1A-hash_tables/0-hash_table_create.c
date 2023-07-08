#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: Size of the hash table array
 *
 * Return: Pointer to the newly created hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	unsigned long int i;

    /* Allocate memory for the hash table structure */
	hash_table = malloc(sizeof(hash_table_t));

	if (hash_table == NULL)
	{
		return (NULL);
	}

	hash_table->size = size;

    /* Allocate memory for the array of hash nodes */
	hash_table->array = malloc(size * sizeof(hash_node_t *));

	if (hash_table->array == NULL)

	{
		free(hash_table);  /* Free the hash table structure */
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		hash_table->array[i] = NULL;
	}

	return (hash_table);
}

