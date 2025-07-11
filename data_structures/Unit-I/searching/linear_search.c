/*
 * LINEAR SEARCH ALGORITHM
 * =======================
 * 
 * What is Linear Search?
 * ----------------------
 * Linear search is like looking for a specific book in a library by checking
 * each book one by one from the first shelf to the last shelf.
 * 
 * How it works:
 * 1. Start from the first element
 * 2. Compare it with the target element
 * 3. If it matches, return the position
 * 4. If not, move to the next element
 * 5. Repeat until found or end of array
 * 
 * Example:
 * Array: [10, 25, 30, 45, 60, 75]
 * Target: 30
 * 
 * Step 1: Check 10 ≠ 30, move to next
 * Step 2: Check 25 ≠ 30, move to next  
 * Step 3: Check 30 = 30, FOUND at index 2!
 * 
 * Time Complexity: O(n) - In worst case, we check all n elements
 * Space Complexity: O(1) - We only use a few variables
 * 
 * When to use Linear Search:
 * - Array is not sorted
 * - Small arrays
 * - Simple implementation needed
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Basic Linear Search Function
 * Returns: index if found, -1 if not found
 */
int linear_search(int arr[], int size, int target) {
    printf("Searching for %d using Linear Search...\n", target);
    
    for (int i = 0; i < size; i++) {
        printf("Step %d: Checking arr[%d] = %d ", i + 1, i, arr[i]);
        
        if (arr[i] == target) {
            printf("✓ FOUND!\n");
            return i;  // Return the index where element is found
        }
        printf("✗ Not match, continue...\n");
    }
    
    printf("Element not found in the array.\n");
    return -1;  // Element not found
}

/*
 * Linear Search with comparison count
 * Helps understand efficiency
 */
int linear_search_with_count(int arr[], int size, int target, int *comparisons) {
    *comparisons = 0;
    
    for (int i = 0; i < size; i++) {
        (*comparisons)++;
        if (arr[i] == target) {
            return i;
        }
    }
    
    return -1;
}

/*
 * Linear Search for finding all occurrences
 * Some elements might appear multiple times
 */
int linear_search_all_occurrences(int arr[], int size, int target, int positions[]) {
    int count = 0;
    printf("Finding all occurrences of %d...\n", target);
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            positions[count] = i;
            count++;
            printf("Found at position %d\n", i);
        }
    }
    
    return count;  // Return number of occurrences
}

/*
 * Linear Search for finding maximum element
 * Application: Find the largest number in array
 */
int linear_search_maximum(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return -1;
    }
    
    int max_value = arr[0];
    int max_index = 0;
    
    printf("Finding maximum element...\n");
    printf("Starting with arr[0] = %d as maximum\n", arr[0]);
    
    for (int i = 1; i < size; i++) {
        printf("Comparing %d with current max %d: ", arr[i], max_value);
        if (arr[i] > max_value) {
            max_value = arr[i];
            max_index = i;
            printf("New maximum found!\n");
        } else {
            printf("Current max remains\n");
        }
    }
    
    printf("Maximum element: %d at index %d\n", max_value, max_index);
    return max_index;
}

/*
 * Linear Search for finding minimum element
 */
int linear_search_minimum(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return -1;
    }
    
    int min_value = arr[0];
    int min_index = 0;
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
            min_index = i;
        }
    }
    
    printf("Minimum element: %d at index %d\n", min_value, min_index);
    return min_index;
}

/*
 * Linear Search in 2D Array
 * Search in a table-like structure
 */
int linear_search_2d(int arr[][10], int rows, int cols, int target, int *found_row, int *found_col) {
    printf("Searching for %d in 2D array...\n", target);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Checking arr[%d][%d] = %d ", i, j, arr[i][j]);
            
            if (arr[i][j] == target) {
                *found_row = i;
                *found_col = j;
                printf("✓ FOUND!\n");
                return 1;  // Found
            }
            printf("✗\n");
        }
    }
    
    printf("Element not found in 2D array.\n");
    return 0;  // Not found
}

/*
 * Function to display array elements
 */
void display_array(int arr[], int size) {
    printf("Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

/*
 * Performance comparison function
 */
void compare_linear_search_performance() {
    printf("\n=== LINEAR SEARCH PERFORMANCE ANALYSIS ===\n");
    
    int sizes[] = {10, 100, 1000};
    int num_sizes = 3;
    
    for (int s = 0; s < num_sizes; s++) {
        int size = sizes[s];
        int *arr = (int*)malloc(size * sizeof(int));
        
        // Fill array with sequential numbers
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }
        
        printf("\nArray size: %d elements\n", size);
        
        // Best case: element at beginning
        int comparisons;
        linear_search_with_count(arr, size, 1, &comparisons);
        printf("Best case (element at start): %d comparisons\n", comparisons);
        
        // Average case: element in middle
        linear_search_with_count(arr, size, size/2, &comparisons);
        printf("Average case (element in middle): %d comparisons\n", comparisons);
        
        // Worst case: element at end
        linear_search_with_count(arr, size, size, &comparisons);
        printf("Worst case (element at end): %d comparisons\n", comparisons);
        
        // Element not found
        linear_search_with_count(arr, size, size + 1, &comparisons);
        printf("Element not found: %d comparisons\n", comparisons);
        
        free(arr);
    }
}

/*
 * Practical example: Student roll number search
 */
void practical_example_student_search() {
    printf("\n=== PRACTICAL EXAMPLE: STUDENT ROLL NUMBER SEARCH ===\n");
    
    int roll_numbers[] = {101, 105, 102, 108, 103, 107, 104, 106, 109, 110};
    int size = 10;
    
    printf("Student Roll Numbers: ");
    display_array(roll_numbers, size);
    
    printf("\nScenario: Teacher wants to find if student with roll number 107 is present\n");
    
    int result = linear_search(roll_numbers, size, 107);
    
    if (result != -1) {
        printf("Student with roll number 107 found at position %d in the list.\n", result);
    } else {
        printf("Student with roll number 107 not found.\n");
    }
    
    // Search for multiple students
    printf("\nSearching for multiple students: 102, 115, 109\n");
    int search_list[] = {102, 115, 109};
    
    for (int i = 0; i < 3; i++) {
        int pos = linear_search(roll_numbers, size, search_list[i]);
        if (pos != -1) {
            printf("Roll number %d: Present (position %d)\n", search_list[i], pos);
        } else {
            printf("Roll number %d: Absent\n", search_list[i]);
        }
    }
}

/*
 * Main demonstration function
 */
void demonstrate_linear_search() {
    printf("=== LINEAR SEARCH ALGORITHM DEMONSTRATION ===\n\n");
    
    // Basic array for demonstration
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("1. Basic Linear Search:\n");
    display_array(arr, size);
    
    // Search for existing element
    printf("\nSearching for element 22:\n");
    int result = linear_search(arr, size, 22);
    if (result != -1) {
        printf("Element 22 found at index %d\n", result);
    }
    
    // Search for non-existing element
    printf("\nSearching for element 99:\n");
    result = linear_search(arr, size, 99);
    
    // Find all occurrences
    printf("\n2. Finding All Occurrences:\n");
    int arr_with_duplicates[] = {5, 3, 7, 3, 9, 3, 1, 3, 8};
    int size_dup = 9;
    printf("Array with duplicates: ");
    display_array(arr_with_duplicates, size_dup);
    
    int positions[10];
    int count = linear_search_all_occurrences(arr_with_duplicates, size_dup, 3, positions);
    printf("Element 3 appears %d times at positions: ", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", positions[i]);
    }
    printf("\n");
    
    // Find max and min
    printf("\n3. Finding Maximum and Minimum:\n");
    display_array(arr, size);
    linear_search_maximum(arr, size);
    linear_search_minimum(arr, size);
    
    // 2D array search
    printf("\n4. 2D Array Search:\n");
    int arr_2d[3][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30}
    };
    
    int found_row, found_col;
    if (linear_search_2d(arr_2d, 3, 10, 25, &found_row, &found_col)) {
        printf("Element 25 found at position [%d][%d]\n", found_row, found_col);
    }
    
    // Performance analysis
    compare_linear_search_performance();
    
    // Practical example
    practical_example_student_search();
}

int main() {
    demonstrate_linear_search();
    return 0;
}