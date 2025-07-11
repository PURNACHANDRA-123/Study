/*
 * DOUBLY LINKED LIST IMPLEMENTATION
 * =================================
 * 
 * What is a Doubly Linked List?
 * ----------------------------
 * A doubly linked list is like a two-way street where you can travel in both
 * directions. Unlike a singly linked list (one-way street), each node has TWO
 * pointers: one pointing to the next node and one pointing to the previous node.
 * 
 * Think of it like a train where:
 * - Each car has doors on both sides
 * - You can walk forward to the next car OR backward to the previous car
 * - Each car knows which car is in front AND which car is behind
 * 
 * Structure of a Node:
 * +------+-------+------+
 * | Prev | Data  | Next |
 * +------+-------+------+
 * 
 * Complete List:
 * NULL <- [•|10|•] <-> [•|20|•] <-> [•|30|•] <-> [•|40|•] -> NULL
 *           ^                                      ^
 *         Head                                   Tail
 * 
 * Advantages over Singly Linked List:
 * - Bidirectional traversal (forward and backward)
 * - Easier deletion (no need to find previous node)
 * - Better for implementing certain algorithms
 * 
 * Disadvantages:
 * - Extra memory for storing previous pointer
 * - More complex insertion/deletion operations
 * - Slightly slower due to managing two pointers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Node Structure Definition
 * Each node has data and TWO pointers
 */
struct Node {
    int data;           // The actual data
    struct Node* next;  // Pointer to next node
    struct Node* prev;  // Pointer to previous node
};

/*
 * Function to create a new node
 */
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    
    printf("Created new node with data: %d\n", data);
    return new_node;
}

/*
 * Function to display list from head to tail (forward)
 */
void display_forward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Forward traversal: ");
    struct Node* current = head;
    int count = 0;
    
    while (current != NULL) {
        printf("[%d]", current->data);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
        count++;
    }
    printf(" -> NULL\n");
    printf("Total nodes: %d\n", count);
}

/*
 * Function to display list from tail to head (backward)
 */
void display_backward(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Backward traversal: ");
    struct Node* current = tail;
    int count = 0;
    
    while (current != NULL) {
        printf("[%d]", current->data);
        if (current->prev != NULL) {
            printf(" <-> ");
        }
        current = current->prev;
        count++;
    }
    printf(" -> NULL\n");
    printf("Total nodes: %d\n", count);
}

/*
 * Function to find the tail node
 */
struct Node* find_tail(struct Node* head) {
    if (head == NULL) return NULL;
    
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

/*
 * Function to display detailed node information
 */
void display_detailed(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("\nDetailed Node Information:\n");
    printf("Position | Address  | Prev     | Data | Next\n");
    printf("---------|----------|----------|------|----------\n");
    
    struct Node* current = head;
    int position = 0;
    
    while (current != NULL) {
        printf("%-8d | %p | %p | %-4d | %p\n",
               position, (void*)current, (void*)current->prev, 
               current->data, (void*)current->next);
        current = current->next;
        position++;
    }
}

/*
 * Function to insert at the beginning
 */
struct Node* insert_at_beginning(struct Node* head, int data) {
    printf("\nInserting %d at the beginning...\n", data);
    
    struct Node* new_node = create_node(data);
    if (new_node == NULL) return head;
    
    // If list is empty
    if (head == NULL) {
        printf("List was empty, %d becomes the first node\n", data);
        return new_node;
    }
    
    // Set new node's next to current head
    new_node->next = head;
    
    // Set current head's previous to new node
    head->prev = new_node;
    
    printf("Successfully inserted %d at the beginning\n", data);
    return new_node;  // new_node becomes the new head
}

/*
 * Function to insert at the end
 */
struct Node* insert_at_end(struct Node* head, int data) {
    printf("\nInserting %d at the end...\n", data);
    
    struct Node* new_node = create_node(data);
    if (new_node == NULL) return head;
    
    // If list is empty
    if (head == NULL) {
        printf("List was empty, %d becomes the first node\n", data);
        return new_node;
    }
    
    // Find the tail
    struct Node* tail = find_tail(head);
    
    // Set connections
    tail->next = new_node;
    new_node->prev = tail;
    
    printf("Successfully inserted %d at the end\n", data);
    return head;
}

/*
 * Function to insert at a specific position
 */
struct Node* insert_at_position(struct Node* head, int data, int position) {
    printf("\nInserting %d at position %d...\n", data, position);
    
    // If position is 0, insert at beginning
    if (position == 0) {
        return insert_at_beginning(head, data);
    }
    
    struct Node* new_node = create_node(data);
    if (new_node == NULL) return head;
    
    // Traverse to the position
    struct Node* current = head;
    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }
    
    // Check if position is valid
    if (current == NULL) {
        printf("Error: Position %d is out of bounds!\n", position);
        free(new_node);
        return head;
    }
    
    // Insert the new node
    new_node->next = current;
    new_node->prev = current->prev;
    
    // Update surrounding nodes
    if (current->prev != NULL) {
        current->prev->next = new_node;
    }
    current->prev = new_node;
    
    printf("Successfully inserted %d at position %d\n", data, position);
    return head;
}

/*
 * Function to delete from beginning
 */
struct Node* delete_from_beginning(struct Node* head) {
    printf("\nDeleting from beginning...\n");
    
    if (head == NULL) {
        printf("Error: List is empty!\n");
        return head;
    }
    
    struct Node* temp = head;
    int deleted_data = head->data;
    
    // Update head
    head = head->next;
    
    // Update new head's prev pointer
    if (head != NULL) {
        head->prev = NULL;
    }
    
    free(temp);
    printf("Successfully deleted %d from beginning\n", deleted_data);
    return head;
}

/*
 * Function to delete from end
 */
struct Node* delete_from_end(struct Node* head) {
    printf("\nDeleting from end...\n");
    
    if (head == NULL) {
        printf("Error: List is empty!\n");
        return head;
    }
    
    // Find the tail
    struct Node* tail = find_tail(head);
    int deleted_data = tail->data;
    
    // If only one node
    if (tail->prev == NULL) {
        free(tail);
        printf("Successfully deleted %d (was the only node)\n", deleted_data);
        return NULL;
    }
    
    // Update the second last node
    tail->prev->next = NULL;
    
    free(tail);
    printf("Successfully deleted %d from end\n", deleted_data);
    return head;
}

/*
 * Function to delete from specific position
 */
struct Node* delete_from_position(struct Node* head, int position) {
    printf("\nDeleting from position %d...\n", position);
    
    if (head == NULL) {
        printf("Error: List is empty!\n");
        return head;
    }
    
    // If deleting first node
    if (position == 0) {
        return delete_from_beginning(head);
    }
    
    // Traverse to the position
    struct Node* current = head;
    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }
    
    // Check if position is valid
    if (current == NULL) {
        printf("Error: Position %d is out of bounds!\n", position);
        return head;
    }
    
    int deleted_data = current->data;
    
    // Update surrounding nodes
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    
    free(current);
    printf("Successfully deleted %d from position %d\n", deleted_data, position);
    return head;
}

/*
 * Function to search for a value
 */
int search_forward(struct Node* head, int target) {
    printf("\nSearching for %d (forward direction)...\n", target);
    
    struct Node* current = head;
    int position = 0;
    
    while (current != NULL) {
        printf("Checking position %d: %d ", position, current->data);
        
        if (current->data == target) {
            printf("✓ FOUND!\n");
            return position;
        }
        printf("✗\n");
        
        current = current->next;
        position++;
    }
    
    printf("Element %d not found\n", target);
    return -1;
}

/*
 * Function to search backwards from tail
 */
int search_backward(struct Node* head, int target) {
    printf("\nSearching for %d (backward direction)...\n", target);
    
    // Find tail first
    struct Node* tail = find_tail(head);
    if (tail == NULL) {
        printf("List is empty\n");
        return -1;
    }
    
    struct Node* current = tail;
    int position_from_end = 0;
    
    while (current != NULL) {
        printf("Checking from end position %d: %d ", position_from_end, current->data);
        
        if (current->data == target) {
            printf("✓ FOUND!\n");
            return position_from_end;
        }
        printf("✗\n");
        
        current = current->prev;
        position_from_end++;
    }
    
    printf("Element %d not found\n", target);
    return -1;
}

/*
 * Function to reverse the doubly linked list
 */
struct Node* reverse_list(struct Node* head) {
    printf("\nReversing the doubly linked list...\n");
    
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    
    struct Node* current = head;
    struct Node* temp = NULL;
    
    // Swap next and prev pointers for each node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // Move to next node (which is in prev now)
    }
    
    // Update head to the new first node
    if (temp != NULL) {
        head = temp->prev;
    }
    
    printf("List reversed successfully\n");
    return head;
}

/*
 * Function to find and delete all occurrences of a value
 */
struct Node* delete_all_occurrences(struct Node* head, int target) {
    printf("\nDeleting all occurrences of %d...\n", target);
    
    struct Node* current = head;
    int deleted_count = 0;
    
    while (current != NULL) {
        if (current->data == target) {
            printf("Found %d at address %p, deleting...\n", target, (void*)current);
            
            struct Node* node_to_delete = current;
            
            // Update links
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                // Deleting head
                head = current->next;
            }
            
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            
            current = current->next;
            free(node_to_delete);
            deleted_count++;
        } else {
            current = current->next;
        }
    }
    
    printf("Deleted %d occurrences of %d\n", deleted_count, target);
    return head;
}

/*
 * Function to get length of the list
 */
int get_length(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

/*
 * Function to free all memory
 */
void free_list(struct Node* head) {
    printf("\nFreeing memory for all nodes...\n");
    
    struct Node* current = head;
    int count = 0;
    
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        printf("Freeing node with data: %d\n", temp->data);
        free(temp);
        count++;
    }
    
    printf("Total nodes freed: %d\n", count);
}

/*
 * Practical example: Browser history
 */
void practical_example_browser_history() {
    printf("\n=== PRACTICAL EXAMPLE: BROWSER HISTORY ===\n");
    
    struct Node* history = NULL;
    struct Node* current_page = NULL;
    
    printf("Simulating browser history using doubly linked list...\n");
    
    // Visit some pages
    printf("\nVisiting pages:\n");
    history = insert_at_end(history, 1);  // Homepage
    history = insert_at_end(history, 2);  // Search page
    history = insert_at_end(history, 3);  // Results page
    history = insert_at_end(history, 4);  // Article page
    
    // Set current page to the last visited
    current_page = find_tail(history);
    
    printf("Current page: Page %d\n", current_page->data);
    
    // Go back in history
    printf("\nGoing back in history:\n");
    for (int i = 0; i < 2 && current_page->prev != NULL; i++) {
        current_page = current_page->prev;
        printf("Went back to: Page %d\n", current_page->data);
    }
    
    // Go forward in history
    printf("\nGoing forward in history:\n");
    if (current_page->next != NULL) {
        current_page = current_page->next;
        printf("Went forward to: Page %d\n", current_page->data);
    }
    
    printf("\nComplete browsing history:\n");
    display_forward(history);
    
    free_list(history);
}

/*
 * Main demonstration function
 */
void demonstrate_doubly_linked_list() {
    printf("=== DOUBLY LINKED LIST DEMONSTRATION ===\n\n");
    
    struct Node* head = NULL;
    
    printf("1. Creating an empty doubly linked list\n");
    display_forward(head);
    
    // Insert operations
    printf("\n2. Insertion Operations:\n");
    head = insert_at_beginning(head, 20);
    display_forward(head);
    
    head = insert_at_end(head, 30);
    display_forward(head);
    
    head = insert_at_beginning(head, 10);
    display_forward(head);
    
    head = insert_at_position(head, 25, 2);
    display_forward(head);
    
    // Show detailed information
    display_detailed(head);
    
    // Bidirectional traversal
    printf("\n3. Bidirectional Traversal:\n");
    display_forward(head);
    struct Node* tail = find_tail(head);
    display_backward(tail);
    
    // Search operations
    printf("\n4. Search Operations:\n");
    search_forward(head, 25);
    search_backward(head, 25);
    
    // Deletion operations
    printf("\n5. Deletion Operations:\n");
    display_forward(head);
    
    head = delete_from_position(head, 1);
    display_forward(head);
    
    head = delete_from_beginning(head);
    display_forward(head);
    
    head = delete_from_end(head);
    display_forward(head);
    
    // Add more elements for testing
    head = insert_at_end(head, 40);
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 50);
    head = insert_at_end(head, 30);
    display_forward(head);
    
    // Delete all occurrences
    printf("\n6. Delete All Occurrences:\n");
    head = delete_all_occurrences(head, 30);
    display_forward(head);
    
    // Reverse the list
    printf("\n7. Reverse Operation:\n");
    display_forward(head);
    head = reverse_list(head);
    display_forward(head);
    
    // Practical example
    practical_example_browser_history();
    
    // Clean up
    printf("\n8. Memory Cleanup:\n");
    free_list(head);
}

int main() {
    demonstrate_doubly_linked_list();
    return 0;
}