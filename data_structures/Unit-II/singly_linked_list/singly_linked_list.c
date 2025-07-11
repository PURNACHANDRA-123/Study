/*
 * SINGLY LINKED LIST IMPLEMENTATION
 * =================================
 * 
 * What is a Singly Linked List?
 * ----------------------------
 * A singly linked list is like a chain of train cars where:
 * - Each car (node) has passengers (data) and a connector to the next car (pointer)
 * - You can only move forward from one car to the next
 * - The last car has no car attached to it (NULL pointer)
 * - You need to know where the first car is (head pointer)
 * 
 * Structure of a Node:
 * +-------+-------+
 * | Data  | Next  |
 * +-------+-------+
 * 
 * Complete List:
 * Head -> [10|•] -> [20|•] -> [30|•] -> [40|NULL]
 * 
 * Memory Layout:
 * Unlike arrays, nodes can be anywhere in memory:
 * 
 * Memory Address: 1000    1500    2000    3000
 * Content:       [10|1500][20|2000][30|3000][40|NULL]
 * 
 * Advantages:
 * - Dynamic size (grows/shrinks as needed)
 * - Easy insertion and deletion at any position
 * - Memory efficient (no wasted space)
 * 
 * Disadvantages:
 * - No random access (can't directly get 3rd element)
 * - Extra memory for storing pointers
 * - Sequential access only (must start from head)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Node Structure Definition
 * This is the building block of our linked list
 */
struct Node {
    int data;           // The actual data we want to store
    struct Node* next;  // Pointer to the next node
};

/*
 * Function to create a new node
 * This is like manufacturing a new train car
 */
struct Node* create_node(int data) {
    // Allocate memory for a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation was successful
    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    
    // Set the data and initialize next pointer
    new_node->data = data;
    new_node->next = NULL;
    
    printf("Created new node with data: %d\n", data);
    return new_node;
}

/*
 * Function to display the entire linked list
 * This is like walking through all train cars and counting passengers
 */
void display_list(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Linked List: ");
    struct Node* current = head;
    int position = 0;
    
    while (current != NULL) {
        printf("[%d]", current->data);
        
        if (current->next != NULL) {
            printf(" -> ");
        } else {
            printf(" -> NULL");
        }
        
        current = current->next;
        position++;
    }
    printf("\nTotal nodes: %d\n", position);
}

/*
 * Function to display list with memory addresses
 * Shows how nodes are connected in memory
 */
void display_list_with_addresses(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("\nLinked List with Memory Addresses:\n");
    struct Node* current = head;
    int position = 0;
    
    while (current != NULL) {
        printf("Node %d: Address=%p, Data=%d, Next=%p\n", 
               position, (void*)current, current->data, (void*)current->next);
        current = current->next;
        position++;
    }
}

/*
 * Function to insert a node at the beginning of the list
 * This is like adding a new train car at the front
 */
struct Node* insert_at_beginning(struct Node* head, int data) {
    printf("\nInserting %d at the beginning...\n", data);
    
    // Create a new node
    struct Node* new_node = create_node(data);
    if (new_node == NULL) return head;
    
    // Make new node point to current head
    new_node->next = head;
    
    // Update head to point to new node
    head = new_node;
    
    printf("Successfully inserted %d at the beginning\n", data);
    return head;
}

/*
 * Function to insert a node at the end of the list
 * This is like adding a new train car at the back
 */
struct Node* insert_at_end(struct Node* head, int data) {
    printf("\nInserting %d at the end...\n", data);
    
    // Create a new node
    struct Node* new_node = create_node(data);
    if (new_node == NULL) return head;
    
    // If list is empty, new node becomes the head
    if (head == NULL) {
        printf("List was empty, %d becomes the first node\n", data);
        return new_node;
    }
    
    // Traverse to the last node
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Make the last node point to new node
    current->next = new_node;
    
    printf("Successfully inserted %d at the end\n", data);
    return head;
}

/*
 * Function to insert a node at a specific position
 * Position starts from 0 (like array indexing)
 */
struct Node* insert_at_position(struct Node* head, int data, int position) {
    printf("\nInserting %d at position %d...\n", data, position);
    
    // If position is 0, insert at beginning
    if (position == 0) {
        return insert_at_beginning(head, data);
    }
    
    // Create new node
    struct Node* new_node = create_node(data);
    if (new_node == NULL) return head;
    
    // Traverse to position-1
    struct Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    // Check if position is valid
    if (current == NULL) {
        printf("Error: Position %d is out of bounds!\n", position);
        free(new_node);
        return head;
    }
    
    // Insert the new node
    new_node->next = current->next;
    current->next = new_node;
    
    printf("Successfully inserted %d at position %d\n", data, position);
    return head;
}

/*
 * Function to delete a node from the beginning
 */
struct Node* delete_from_beginning(struct Node* head) {
    printf("\nDeleting from beginning...\n");
    
    if (head == NULL) {
        printf("Error: List is empty!\n");
        return head;
    }
    
    struct Node* temp = head;
    int deleted_data = head->data;
    head = head->next;
    
    free(temp);
    printf("Successfully deleted %d from beginning\n", deleted_data);
    return head;
}

/*
 * Function to delete a node from the end
 */
struct Node* delete_from_end(struct Node* head) {
    printf("\nDeleting from end...\n");
    
    if (head == NULL) {
        printf("Error: List is empty!\n");
        return head;
    }
    
    // If only one node
    if (head->next == NULL) {
        int deleted_data = head->data;
        free(head);
        printf("Successfully deleted %d (was the only node)\n", deleted_data);
        return NULL;
    }
    
    // Traverse to second last node
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    // Delete last node
    int deleted_data = current->next->data;
    free(current->next);
    current->next = NULL;
    
    printf("Successfully deleted %d from end\n", deleted_data);
    return head;
}

/*
 * Function to delete a node from specific position
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
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    // Check if position is valid
    if (current == NULL || current->next == NULL) {
        printf("Error: Position %d is out of bounds!\n", position);
        return head;
    }
    
    // Delete the node
    struct Node* temp = current->next;
    int deleted_data = temp->data;
    current->next = temp->next;
    free(temp);
    
    printf("Successfully deleted %d from position %d\n", deleted_data, position);
    return head;
}

/*
 * Function to search for a value in the list
 */
int search_list(struct Node* head, int target) {
    printf("\nSearching for %d...\n", target);
    
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
    
    printf("Element %d not found in the list\n", target);
    return -1;
}

/*
 * Function to get the length of the list
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
 * Function to reverse the linked list
 * Changes direction of all pointers
 */
struct Node* reverse_list(struct Node* head) {
    printf("\nReversing the linked list...\n");
    
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        // Store next node
        next = current->next;
        
        // Reverse the link
        current->next = prev;
        
        // Move pointers forward
        prev = current;
        current = next;
    }
    
    printf("List reversed successfully\n");
    return prev;  // prev is now the new head
}

/*
 * Function to find the middle element
 * Uses two-pointer technique (tortoise and hare)
 */
struct Node* find_middle(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    struct Node* slow = head;  // Moves one step at a time
    struct Node* fast = head;  // Moves two steps at a time
    
    printf("\nFinding middle element using two-pointer technique...\n");
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        printf("Slow pointer at: %d, Fast pointer at: %d\n", 
               slow->data, fast ? fast->data : -1);
    }
    
    printf("Middle element: %d\n", slow->data);
    return slow;
}

/*
 * Function to merge two sorted linked lists
 */
struct Node* merge_sorted_lists(struct Node* list1, struct Node* list2) {
    printf("\nMerging two sorted lists...\n");
    
    // Create a dummy node to simplify the logic
    struct Node dummy;
    struct Node* current = &dummy;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    // Append remaining nodes
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    
    printf("Lists merged successfully\n");
    return dummy.next;
}

/*
 * Function to free all memory allocated for the list
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
 * Practical example: Student record system
 */
void practical_example_student_records() {
    printf("\n=== PRACTICAL EXAMPLE: STUDENT RECORD SYSTEM ===\n");
    
    struct Node* students = NULL;
    
    printf("Creating student record system using linked list...\n");
    
    // Add students (roll numbers)
    students = insert_at_end(students, 101);
    students = insert_at_end(students, 102);
    students = insert_at_end(students, 103);
    students = insert_at_end(students, 104);
    
    display_list(students);
    
    // New student admission
    printf("\nNew student admission (roll number 105):\n");
    students = insert_at_end(students, 105);
    display_list(students);
    
    // Student withdrawal
    printf("\nStudent with roll number 102 withdraws:\n");
    students = delete_from_position(students, 1);  // 102 is at position 1
    display_list(students);
    
    // Search for a student
    search_list(students, 104);
    
    printf("Total students: %d\n", get_length(students));
    
    free_list(students);
}

/*
 * Main demonstration function
 */
void demonstrate_singly_linked_list() {
    printf("=== SINGLY LINKED LIST DEMONSTRATION ===\n\n");
    
    struct Node* head = NULL;  // Start with empty list
    
    printf("1. Creating an empty linked list\n");
    display_list(head);
    
    // Insert operations
    printf("\n2. Insertion Operations:\n");
    head = insert_at_beginning(head, 10);
    display_list(head);
    
    head = insert_at_end(head, 30);
    display_list(head);
    
    head = insert_at_position(head, 20, 1);
    display_list(head);
    
    head = insert_at_beginning(head, 5);
    display_list(head);
    
    // Show memory layout
    display_list_with_addresses(head);
    
    // Search operations
    printf("\n3. Search Operations:\n");
    search_list(head, 20);
    search_list(head, 99);
    
    // Find middle
    find_middle(head);
    
    // Deletion operations
    printf("\n4. Deletion Operations:\n");
    display_list(head);
    
    head = delete_from_beginning(head);
    display_list(head);
    
    head = delete_from_end(head);
    display_list(head);
    
    head = delete_from_position(head, 1);
    display_list(head);
    
    // Reverse the list
    printf("\n5. Reverse Operation:\n");
    display_list(head);
    head = reverse_list(head);
    display_list(head);
    
    // Merge example
    printf("\n6. Merge Operation:\n");
    struct Node* list2 = NULL;
    list2 = insert_at_end(list2, 15);
    list2 = insert_at_end(list2, 25);
    list2 = insert_at_end(list2, 35);
    
    printf("List 1: ");
    display_list(head);
    printf("List 2: ");
    display_list(list2);
    
    struct Node* merged = merge_sorted_lists(head, list2);
    printf("Merged: ");
    display_list(merged);
    
    // Practical example
    practical_example_student_records();
    
    // Clean up memory
    printf("\n7. Memory Cleanup:\n");
    free_list(merged);
}

int main() {
    demonstrate_singly_linked_list();
    return 0;
}