#include <stdio.h>
#include <stdlib.h>

struct list_node {
    int value;
    struct list_node *next;
};

void add_to_list(struct list_node **head, int value) {
    struct list_node *new_node;
    new_node = malloc(sizeof(struct list_node));
    
    if (new_node == NULL) {
        return;
    }
    
    new_node -> value = value;
    new_node -> next = *head;
    *head = new_node;
}

void delete_from_list(struct list_node *previous_node, struct list_node **node_to_delete) {
    if (previous_node == NULL) {
        struct list_node *new_head = (*node_to_delete) -> next;
        *node_to_delete = new_head;
        return;
    }
    
    previous_node -> next = (*node_to_delete) -> next;
    free(*node_to_delete);
}

void print_list(struct list_node *node) {    
    while (node != NULL) {
        printf("%d", node -> value);
        
        if (node -> next != NULL) {
            printf(", ");
        }
        
        node = node -> next;
    }
    
    printf("\n");
}

int main () {
    struct list_node *list = NULL;
    
    // Add
    add_to_list(&list, 10);
    add_to_list(&list, 2);
    add_to_list(&list, 3);
    add_to_list(&list, 6);
    
    print_list(list);
    
    // Remove
    delete_from_list(list, &list -> next);
    print_list(list);
    
    delete_from_list(list, &list -> next);
    print_list(list);
    
    delete_from_list(NULL, &list);
    print_list(list);
    
    delete_from_list(NULL, &list);
    print_list(list);
    
    return (EXIT_SUCCESS);
}