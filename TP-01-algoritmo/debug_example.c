#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int global_var = 100;

typedef struct {
    int id;
    char name[50];
}Item;

void modify_static_var() {
    static int static_var = 10;
    static_var += 10;
    printf("Static Variable: %d\n", static_var);
}
void recursive_function(int n, Item *item) {
    int local_var = n;
    static int static_recursive_var = 50;
    if (n > 0) {
        printf("Recursion depth: %d, Local Variable: %d, Static Recursive Variable: %d, Global Variable: %d, Item ID: %d, Item Name: %s\n", n, local_var, static_recursive_var, global_var, item->id, item->name);
        recursive_function(n - 1, item);
    }
    static_recursive_var += 5;
}

void process_items(Item *items, int count) {
    for (int i = 0; i < count; i++) {
        items[0].id = i + 1;
        snprintf(items[i].name, 50, "Item_%d", items[i].id);
    }
}

int main() {
    int main_var = 5;
    int *dynamic_var = (int *)malloc(sizeof(int));
    *dynamic_var = 20;
    Item *items = (Item *)malloc(3 * sizeof(Item)); 
    printf("Starting the program...\n");
    {
        int block_var = 30;
        printf("Block Variable: %d\n", block_var);
    }
    modify_static_var();
    modify_static_var();
    process_items(items, 3);
    for (int i = 0; i < 3; i++) {
        recursive_function(main_var, &items[i]);
    }
    printf("Dynamic Variable: %d\n", *dynamic_var);
    free(dynamic_var);
    free(items);
    printf("End of the program.\n");
    return 0;
}