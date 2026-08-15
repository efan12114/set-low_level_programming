#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

int main(void)
{
    shash_table_t *ht;
    ht = shash_table_create(1024);
    shash_table_set(ht, "y", "0");
    shash_table_print(ht);
    shash_table_delete(ht);
    return (EXIT_SUCCESS);
}
