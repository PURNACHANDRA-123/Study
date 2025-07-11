/*
 * ONE-DIMENSIONAL ARRAY IMPLEMENTATION
 * ====================================
 * 
 * What is an Array?
 * ----------------
 * An array is like a row of numbered boxes where you can store items.
 * Each box has a number (index) starting from 0.
 * 
 * Example: If you have 5 boxes, they are numbered 0, 1, 2, 3, 4
 * 
 * Visual representation:
 * +-----+-----+-----+-----+-----+
 * | 10  | 20  | 30  | 40  | 50  |
 * +-----+-----+-----+-----+-----+
 *   [0]   [1]   [2]   [3]   [4]
 * 
 * Memory Layout:
 * - All elements are stored in continuous memory locations
 * - If first element is at address 1000, next will be at 1004 (for integers)
 * - Formula: Address of arr[i] = Base_Address + (i * size_of_datatype)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum size of array

/*
 * Function to display the array
 * This is called "Traversing" - visiting each element one by one
 */
void display_array(int arr[], int size) {
    printf("\nArray elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
 * Function to insert an element at a specific position
 * 
 * Think of it like this:
 * - You have a row of people standing
 * - You want to insert a new person at position 2
 * - Everyone from position 2 onwards has to move one step right
 * - Then you place the new person at position 2
 */
int insert_element(int arr[], int *size, int element, int position) {
    // Check if array is full
    if (*size >= MAX_SIZE) {
        printf("Error: Array is full!\n");
        return 0;
    }
    
    // Check if position is valid
    if (position < 0 || position > *size) {
        printf("Error: Invalid position! Position should be between 0 and %d\n", *size);
        return 0;
    }
    
    // Move elements to the right to make space
    // Start from the last element and move backwards
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert the new element
    arr[position] = element;
    
    // Increase the size
    (*size)++;
    
    printf("Element %d inserted at position %d successfully!\n", element, position);
    return 1;  // Success
}

/*
 * Function to delete an element from a specific position
 * 
 * Think of it like this:
 * - You have a row of people standing
 * - You want to remove person at position 2
 * - Remove that person
 * - Everyone after position 2 moves one step left to fill the gap
 */
int delete_element(int arr[], int *size, int position) {
    // Check if array is empty
    if (*size == 0) {
        printf("Error: Array is empty!\n");
        return 0;
    }
    
    // Check if position is valid
    if (position < 0 || position >= *size) {
        printf("Error: Invalid position! Position should be between 0 and %d\n", *size - 1);
        return 0;
    }
    
    int deleted_element = arr[position];
    
    // Move elements to the left to fill the gap
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Decrease the size
    (*size)--;
    
    printf("Element %d deleted from position %d successfully!\n", deleted_element, position);
    return 1;  // Success
}

/*
 * Function to search for an element in the array
 * This is Linear Search - check each element one by one
 */
int search_element(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;  // Return the position where element is found
        }
    }
    return -1;  // Element not found
}

/*
 * Function to merge two arrays
 * Like combining two groups of people into one big group
 */
void merge_arrays(int arr1[], int size1, int arr2[], int size2, int result[], int *result_size) {
    int i = 0;
    
    // Copy all elements from first array
    for (int j = 0; j < size1; j++) {
        result[i] = arr1[j];
        i++;
    }
    
    // Copy all elements from second array
    for (int j = 0; j < size2; j++) {
        result[i] = arr2[j];
        i++;
    }
    
    *result_size = size1 + size2;
    printf("Arrays merged successfully!\n");
}

/*
 * Demonstration function showing all array operations
 */
void demonstrate_array_operations() {
    int arr[MAX_SIZE];
    int size = 0;
    
    printf("=== ONE-DIMENSIONAL ARRAY DEMONSTRATION ===\n\n");
    
    // 1. Initialize array with some values
    printf("1. Initializing array with values: 10, 20, 30, 40, 50\n");
    arr[0] = 10; arr[1] = 20; arr[2] = 30; arr[3] = 40; arr[4] = 50;
    size = 5;
    display_array(arr, size);
    
    // 2. Insert operation
    printf("\n2. Inserting element 25 at position 2:\n");
    insert_element(arr, &size, 25, 2);
    display_array(arr, size);
    
    // 3. Search operation
    printf("\n3. Searching for element 30:\n");
    int position = search_element(arr, size, 30);
    if (position != -1) {
        printf("Element 30 found at position %d\n", position);
    } else {
        printf("Element 30 not found\n");
    }
    
    // 4. Delete operation
    printf("\n4. Deleting element at position 1:\n");
    delete_element(arr, &size, 1);
    display_array(arr, size);
    
    // 5. Merge operation
    printf("\n5. Merging with another array [60, 70, 80]:\n");
    int arr2[] = {60, 70, 80};
    int size2 = 3;
    int merged[MAX_SIZE];
    int merged_size;
    
    printf("Original array: ");
    display_array(arr, size);
    printf("Second array: ");
    display_array(arr2, size2);
    
    merge_arrays(arr, size, arr2, size2, merged, &merged_size);
    printf("Merged array: ");
    display_array(merged, merged_size);
}

/*
 * Function to explain memory representation
 */
void explain_memory_representation() {
    printf("\n=== MEMORY REPRESENTATION ===\n\n");
    
    int arr[5] = {10, 20, 30, 40, 50};
    
    printf("Array: [10, 20, 30, 40, 50]\n");
    printf("Memory addresses:\n");
    
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, Address = %p\n", i, arr[i], (void*)&arr[i]);
    }
    
    printf("\nNotice how addresses are consecutive!\n");
    printf("Each integer takes %zu bytes in memory.\n", sizeof(int));
}

int main() {
    demonstrate_array_operations();
    explain_memory_representation();
    
    return 0;
}