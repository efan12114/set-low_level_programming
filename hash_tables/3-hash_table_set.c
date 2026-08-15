#include "hash_tables.h"

/**
 * make_node - creates a new hash node
 * @key: key string
 * @value: value string
 * Return: pointer to new node, or NULL
 */
static hash_node_t *make_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}
	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table pointer
 * @key: key string
 * @value: value string
 * Return: 1 if success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *tmp, *new;
	char *new_val;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			new_val = strdup(value);
			if (new_val == NULL)
				return (0);
			free(tmp->value);
			tmp->value = new_val;
			return (1);
		}
		tmp = tmp->next;
	}
	new = make_node(key, value);
	if (new == NULL)
		return (0);
	new->next = ht->array[idx];
	ht->array[idx] = new;
	return (1);
}
