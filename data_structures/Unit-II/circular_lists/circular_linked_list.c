/*
 * CIRCULAR LINKED LIST IMPLEMENTATION
 * ===================================
 * 
 * What is a Circular Linked List?
 * ------------------------------
 * A circular linked list is like a circle of people holding hands where:
 * - The last person holds the hand of the first person
 * - You can start from any person and eventually come back to them
 * - There's no "end" - you can keep going around the circle forever
 * - No NULL pointers (except in empty list)
 * 
 * Unlike a regular linked list that ends with NULL:
 * Regular: [A] -> [B] -> [C] -> NULL
 * 
 * Circular linked list forms a complete circle:
 * Circular: [A] -> [B] -> [C]
 *            ^              |
 *            |______________|
 * 
 * Visual Representation:
 *        +---+    +---+    +---+
 *        | A |--->| B |--->| C |
 *        +---+    +---+    +---+
 *         ^                  |
 *         |__________________|
 * 
 * Types:
 * 1. Singly Circular: Only next pointer, last node points to first
 * 2. Doubly Circular: Both next and prev pointers, forms complete circle
 * 
 * Applications:
 * - Round-robin scheduling in operating systems
 * - Music playlists (repeat mode)
 * - Games where players take turns
 * - Josephus problem
 * - Representing circular data structures
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Node structure for singly circular linked list
 */
struct Node {
    int data;
    struct Node* next;
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
    new_node->next = new_node;  // Points to itself initially
    
    printf("Created new node with data: %d\n", data);
    return new_node;
}

/*
 * Function to display circular linked list
 * Note: We need to be careful not to infinite loop!
 */
void display_circular_list(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Circular List: ");
    struct Node* current = head;
    int count = 0;
    
    do {
        printf("[%d]", current->data);
        current = current->next;
        count++;
        
        if (current != head) {
            printf(" -> ");
        }
        
        // Safety check to prevent infinite loop in case of error
        if (count > 100) {
            printf(" ... (stopping to prevent infinite loop)");
            break;
        }
    } while (current != head);
    
    printf(" -> [back to %d]\n", head->data);
    printf("Total nodes: %d\n", count);
}

/*
 * Function to display with addresses to show circular nature
 */
void display_with_addresses(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("\nCircular List with Addresses:\n");
    printf("Position | Address  | Data | Next Address\n");
    printf("---------|----------|------|-------------\n");
    
    struct Node* current = head;
    int position = 0;
    
    do {
        printf("%-8d | %p | %-4d | %p", 
               position, (void*)current, current->data, (void*)current->next);
        
        if (current->next == head) {
            printf(" (back to head)");
        }
        printf("\n");
        
        current = current->next;
        position++;
    } while (current != head);
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
    
    // Find the last node (the one pointing to head)
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    // Insert new node
    new_node->next = head;
    last->next = new_node;
    
    printf("Successfully inserted %d at the beginning\n", data);
    return new_node;  // new_node becomes new head
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
    
    // Find the last node
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    // Insert new node
    last->next = new_node;
    new_node->next = head;
    
    printf("Successfully inserted %d at the end\n", data);
    return head;
}

/*
 * Function to insert at specific position
 */
struct Node* insert_at_position(struct Node* head, int data, int position) {
    printf("\nInserting %d at position %d...\n", data, position);
    
    // If position is 0, insert at beginning
    if (position == 0) {
        return insert_at_beginning(head, data);
    }
    
    if (head == NULL) {
        printf("Error: Cannot insert at position %d in empty list\n", position);
        return head;
    }
    
    struct Node* new_node = create_node(data);
    if (new_node == NULL) return head;
    
    // Traverse to position-1
    struct Node* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == head) {
            printf("Error: Position %d is out of bounds!\n", position);
            free(new_node);
            return head;
        }
    }
    
    // Insert new node
    new_node->next = current->next;
    current->next = new_node;
    
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
    
    // If only one node
    if (head->next == head) {
        int deleted_data = head->data;
        free(head);
        printf("Successfully deleted %d (was the only node)\n", deleted_data);
        return NULL;
    }
    
    // Find last node
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    // Delete head
    int deleted_data = head->data;
    last->next = head->next;
    struct Node* new_head = head->next;
    free(head);
    
    printf("Successfully deleted %d from beginning\n", deleted_data);
    return new_head;
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
    
    // If only one node
    if (head->next == head) {
        int deleted_data = head->data;
        free(head);
        printf("Successfully deleted %d (was the only node)\n", deleted_data);
        return NULL;
    }
    
    // Find second last node
    struct Node* current = head;
    while (current->next->next != head) {
        current = current->next;
    }
    
    // Delete last node
    int deleted_data = current->next->data;
    free(current->next);
    current->next = head;
    
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
    
    // Traverse to position-1
    struct Node* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == head) {
            printf("Error: Position %d is out of bounds!\n", position);
            return head;
        }
    }
    
    // Check if next node exists
    if (current->next == head) {
        printf("Error: Position %d is out of bounds!\n", position);
        return head;
    }
    
    // Delete the node
    struct Node* node_to_delete = current->next;
    int deleted_data = node_to_delete->data;
    current->next = node_to_delete->next;
    free(node_to_delete);
    
    printf("Successfully deleted %d from position %d\n", deleted_data, position);
    return head;
}

/*
 * Function to search for a value
 */
int search_circular_list(struct Node* head, int target) {
    printf("\nSearching for %d...\n", target);
    
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    
    struct Node* current = head;
    int position = 0;
    
    do {
        printf("Checking position %d: %d ", position, current->data);
        
        if (current->data == target) {
            printf("✓ FOUND!\n");
            return position;
        }
        printf("✗\n");
        
        current = current->next;
        position++;
    } while (current != head);
    
    printf("Element %d not found\n", target);
    return -1;
}

/*
 * Function to traverse N times around the circle
 */
void traverse_n_times(struct Node* head, int n) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("\nTraversing %d times around the circle:\n", n);
    struct Node* current = head;
    int count = 0;
    
    while (count < n) {
        printf("[%d] -> ", current->data);
        current = current->next;
        
        if (current == head) {
            count++;
            if (count < n) {
                printf("(completed round %d) -> ", count);
            }
        }
    }
    printf("(completed %d rounds)\n", n);
}

/*
 * Function to get length of circular list
 */
int get_length(struct Node* head) {
    if (head == NULL) return 0;
    
    int count = 0;
    struct Node* current = head;
    
    do {
        count++;
        current = current->next;
    } while (current != head);
    
    return count;
}

/*
 * Function to split circular list into two halves
 */
void split_circular_list(struct Node* head, struct Node** head1, struct Node** head2) {
    printf("\nSplitting circular list into two halves...\n");
    
    if (head == NULL) {
        *head1 = NULL;
        *head2 = NULL;
        return;
    }
    
    // Use slow and fast pointers to find middle
    struct Node* slow = head;
    struct Node* fast = head;
    
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Set up first half
    *head1 = head;
    
    // Set up second half
    *head2 = slow->next;
    slow->next = head;  // Complete first circle
    
    // Find end of second half and complete second circle
    struct Node* current = *head2;
    while (current->next != head) {
        current = current->next;
    }
    current->next = *head2;
    
    printf("List split into two circular lists\n");
}

/*
 * Josephus Problem solution
 * People stand in circle, every k-th person is eliminated
 */
int josephus_problem(int n, int k) {
    printf("\n=== JOSEPHUS PROBLEM ===\n");
    printf("Finding survivor when %d people stand in circle and every %d-th person is eliminated\n", n, k);
    
    // Create circular list with n people
    struct Node* head = NULL;
    for (int i = 1; i <= n; i++) {
        head = insert_at_end(head, i);
    }
    
    printf("Initial circle: ");
    display_circular_list(head);
    
    struct Node* current = head;
    
    // Eliminate people until only one remains
    while (current->next != current) {
        // Move k-1 steps
        for (int i = 1; i < k; i++) {
            current = current->next;
        }
        
        // Eliminate the k-th person
        struct Node* to_eliminate = current->next;
        printf("Eliminating person %d\n", to_eliminate->data);
        
        current->next = to_eliminate->next;
        
        // If we eliminated the head, update head
        if (to_eliminate == head) {
            head = current->next;
        }
        
        free(to_eliminate);
    }
    
    int survivor = current->data;
    printf("Survivor: Person %d\n", survivor);
    free(current);
    
    return survivor;
}

/*
 * Function to free circular list memory
 */
void free_circular_list(struct Node* head) {
    if (head == NULL) return;
    
    printf("\nFreeing memory for circular list...\n");
    
    struct Node* current = head->next;
    int count = 1;
    
    // Free all nodes except head
    while (current != head) {
        struct Node* temp = current;
        current = current->next;
        printf("Freeing node with data: %d\n", temp->data);
        free(temp);
        count++;
    }
    
    // Free head
    printf("Freeing head node with data: %d\n", head->data);
    free(head);
    
    printf("Total nodes freed: %d\n", count);
}

/*
 * Practical example: Round-robin scheduler
 */
void practical_example_round_robin() {
    printf("\n=== PRACTICAL EXAMPLE: ROUND-ROBIN SCHEDULER ===\n");
    
    struct Node* process_queue = NULL;
    
    printf("Creating process queue for round-robin scheduling...\n");
    
    // Add processes
    process_queue = insert_at_end(process_queue, 101);  // Process 101
    process_queue = insert_at_end(process_queue, 102);  // Process 102
    process_queue = insert_at_end(process_queue, 103);  // Process 103
    process_queue = insert_at_end(process_queue, 104);  // Process 104
    
    display_circular_list(process_queue);
    
    printf("\nSimulating round-robin scheduling (3 time slices):\n");
    struct Node* current_process = process_queue;
    
    for (int time_slice = 1; time_slice <= 8; time_slice++) {
        printf("Time slice %d: Running process %d\n", 
               time_slice, current_process->data);
        current_process = current_process->next;
    }
    
    printf("\nNotice how processes get CPU time in circular order!\n");
    
    free_circular_list(process_queue);
}

/*
 * Main demonstration function
 */
void demonstrate_circular_linked_list() {
    printf("=== CIRCULAR LINKED LIST DEMONSTRATION ===\n\n");
    
    struct Node* head = NULL;
    
    printf("1. Creating empty circular list\n");
    display_circular_list(head);
    
    // Insert operations
    printf("\n2. Insertion Operations:\n");
    head = insert_at_beginning(head, 20);
    display_circular_list(head);
    
    head = insert_at_end(head, 30);
    display_circular_list(head);
    
    head = insert_at_beginning(head, 10);
    display_circular_list(head);
    
    head = insert_at_position(head, 25, 2);
    display_circular_list(head);
    
    // Show addresses to prove circular nature
    display_with_addresses(head);
    
    // Multiple traversals
    printf("\n3. Multiple Traversals:\n");
    traverse_n_times(head, 3);
    
    // Search operation
    printf("\n4. Search Operation:\n");
    search_circular_list(head, 25);
    search_circular_list(head, 99);
    
    // Deletion operations
    printf("\n5. Deletion Operations:\n");
    display_circular_list(head);
    
    head = delete_from_position(head, 1);
    display_circular_list(head);
    
    head = delete_from_beginning(head);
    display_circular_list(head);
    
    head = delete_from_end(head);
    display_circular_list(head);
    
    // Add more elements for advanced operations
    head = insert_at_end(head, 40);
    head = insert_at_end(head, 50);
    head = insert_at_end(head, 60);
    head = insert_at_end(head, 70);
    display_circular_list(head);
    
    // Split operation
    printf("\n6. Split Operation:\n");
    struct Node* head1, *head2;
    split_circular_list(head, &head1, &head2);
    printf("First half: ");
    display_circular_list(head1);
    printf("Second half: ");
    display_circular_list(head2);
    
    // Josephus problem
    josephus_problem(7, 3);
    
    // Practical example
    practical_example_round_robin();
    
    // Clean up
    printf("\n7. Memory Cleanup:\n");
    free_circular_list(head1);
    free_circular_list(head2);
}

int main() {
    demonstrate_circular_linked_list();
    return 0;
}