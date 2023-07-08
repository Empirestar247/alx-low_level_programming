#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table and its elements.
 * @ht: A pointer to the hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	if (ht == NULL)
		return;

	hash_node_t *node, *tmp;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			tmp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = tmp;
		}
	}

	free(ht->array);
	free(ht);
}

