#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

int main(void)
{
    hash_table_t *ht;
    char *value;
    ht = hash_table_create(1024);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Street");
    value = hash_table_get(ht, "python");
    printf("%s\n", value);
    value = hash_table_get(ht, "Bob");
    printf("%s\n", value);
    value = hash_table_get(ht, "98");
    printf("%s\n", value);
    value = hash_table_get(ht, "Betty");
    printf("%s\n", value);
    value = hash_table_get(ht, "Bettyyy");
    printf("%p\n", (void *)value);
    return (EXIT_SUCCESS);
}
