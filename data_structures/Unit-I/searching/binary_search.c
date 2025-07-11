/*
 * BINARY SEARCH ALGORITHM
 * =======================
 * 
 * What is Binary Search?
 * ----------------------
 * Binary search is like looking for a word in a dictionary. You don't start from
 * page 1 and check every word. Instead, you open the dictionary in the middle and
 * decide whether to look in the first half or second half.
 * 
 * IMPORTANT: Binary search only works on SORTED arrays!
 * 
 * How it works:
 * 1. Find the middle element of the array
 * 2. Compare it with the target
 * 3. If target is smaller, search the left half
 * 4. If target is larger, search the right half
 * 5. If target equals middle element, found!
 * 6. Repeat until found or no more elements to search
 * 
 * Example:
 * Sorted Array: [10, 20, 30, 40, 50, 60, 70, 80, 90]
 * Target: 60
 * 
 * Step 1: middle = arr[4] = 50, target > 50, search right half [60,70,80,90]
 * Step 2: middle = arr[6] = 70, target < 70, search left half [60]
 * Step 3: middle = arr[5] = 60, target = 60, FOUND at index 5!
 * 
 * Time Complexity: O(log n) - Much faster than linear search
 * Space Complexity: O(1) for iterative, O(log n) for recursive
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Iterative Binary Search
 * Uses loops instead of function calls
 */
int binary_search_iterative(int arr[], int size, int target) {
    int left = 0;           // Start of search range
    int right = size - 1;   // End of search range
    int step = 1;
    
    printf("Searching for %d using Iterative Binary Search...\n", target);
    printf("Array must be sorted for binary search to work!\n\n");
    
    while (left <= right) {
        int middle = left + (right - left) / 2;  // Calculate middle index
        
        printf("Step %d:\n", step);
        printf("  Search range: index %d to %d\n", left, right);
        printf("  Middle index: %d, Middle value: %d\n", middle, arr[middle]);
        printf("  Comparing %d with %d: ", target, arr[middle]);
        
        if (arr[middle] == target) {
            printf("EQUAL - FOUND!\n");
            return middle;  // Target found at middle
        }
        else if (target < arr[middle]) {
            printf("TARGET SMALLER - search left half\n");
            right = middle - 1;  // Search left half
        }
        else {
            printf("TARGET LARGER - search right half\n");
            left = middle + 1;   // Search right half
        }
        
        step++;
        printf("\n");
    }
    
    printf("Element not found.\n");
    return -1;  // Target not found
}

/*
 * Recursive Binary Search
 * Function calls itself with smaller problem size
 */
int binary_search_recursive(int arr[], int left, int right, int target, int step) {
    printf("Step %d: Searching range [%d, %d]\n", step, left, right);
    
    if (left > right) {
        return -1;  // Base case: element not found
    }
    
    int middle = left + (right - left) / 2;
    printf("  Middle index: %d, Middle value: %d\n", middle, arr[middle]);
    
    if (arr[middle] == target) {
        printf("  FOUND at index %d!\n", middle);
        return middle;  // Base case: element found
    }
    else if (target < arr[middle]) {
        printf("  Target smaller, searching left half\n");
        return binary_search_recursive(arr, left, middle - 1, target, step + 1);
    }
    else {
        printf("  Target larger, searching right half\n");
        return binary_search_recursive(arr, middle + 1, right, target, step + 1);
    }
}

/*
 * Binary Search with comparison count
 */
int binary_search_with_count(int arr[], int size, int target, int *comparisons) {
    int left = 0;
    int right = size - 1;
    *comparisons = 0;
    
    while (left <= right) {
        int middle = left + (right - left) / 2;
        (*comparisons)++;
        
        if (arr[middle] == target) {
            return middle;
        }
        else if (target < arr[middle]) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    
    return -1;
}

/*
 * Find first occurrence of target (for arrays with duplicates)
 */
int binary_search_first_occurrence(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int result = -1;
    
    printf("Finding FIRST occurrence of %d...\n", target);
    
    while (left <= right) {
        int middle = left + (right - left) / 2;
        
        if (arr[middle] == target) {
            result = middle;  // Store the result
            right = middle - 1;  // Continue searching in left half
            printf("Found at %d, checking if there's an earlier occurrence...\n", middle);
        }
        else if (target < arr[middle]) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    
    return result;
}

/*
 * Find last occurrence of target
 */
int binary_search_last_occurrence(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int result = -1;
    
    printf("Finding LAST occurrence of %d...\n", target);
    
    while (left <= right) {
        int middle = left + (right - left) / 2;
        
        if (arr[middle] == target) {
            result = middle;  // Store the result
            left = middle + 1;  // Continue searching in right half
            printf("Found at %d, checking if there's a later occurrence...\n", middle);
        }
        else if (target < arr[middle]) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    
    return result;
}

/*
 * Binary search for insertion position
 * Finds where to insert element to keep array sorted
 */
int binary_search_insertion_point(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    printf("Finding insertion point for %d...\n", target);
    
    while (left <= right) {
        int middle = left + (right - left) / 2;
        
        if (arr[middle] < target) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    
    printf("Element %d should be inserted at index %d\n", target, left);
    return left;
}

/*
 * Function to display array
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
 * Performance comparison: Linear vs Binary Search
 */
void compare_search_performance() {
    printf("\n=== PERFORMANCE COMPARISON: LINEAR vs BINARY SEARCH ===\n");
    
    int sizes[] = {100, 1000, 10000, 100000};
    int num_sizes = 4;
    
    printf("%-12s %-15s %-15s %-15s\n", "Array Size", "Linear (Worst)", "Binary (Worst)", "Improvement");
    printf("--------------------------------------------------------\n");
    
    for (int s = 0; s < num_sizes; s++) {
        int size = sizes[s];
        
        // Linear search worst case: O(n)
        int linear_comparisons = size;
        
        // Binary search worst case: O(log n)
        int binary_comparisons = (int)ceil(log2(size));
        
        float improvement = (float)linear_comparisons / binary_comparisons;
        
        printf("%-12d %-15d %-15d %-15.1fx\n", 
               size, linear_comparisons, binary_comparisons, improvement);
    }
}

/*
 * Practical example: Phone book search
 */
void practical_example_phone_book() {
    printf("\n=== PRACTICAL EXAMPLE: PHONE BOOK SEARCH ===\n");
    
    // Sorted phone numbers (like a phone book)
    int phone_numbers[] = {1001, 1002, 1005, 1008, 1012, 1015, 1020, 1025, 1030, 1035};
    int size = 10;
    
    printf("Phone Book (sorted phone numbers): ");
    display_array(phone_numbers, size);
    
    printf("\nScenario: Customer service wants to find if phone number 1015 is registered\n");
    
    int result = binary_search_iterative(phone_numbers, size, 1015);
    
    if (result != -1) {
        printf("Phone number 1015 found at position %d in the database.\n", result);
    } else {
        printf("Phone number 1015 not found in the database.\n");
    }
}

/*
 * Demonstrate why array must be sorted
 */
void demonstrate_sorted_requirement() {
    printf("\n=== WHY ARRAY MUST BE SORTED ===\n");
    
    printf("Unsorted array: [30, 10, 50, 20, 60, 40]\n");
    printf("Searching for 20 using binary search...\n");
    printf("Result will be INCORRECT because array is not sorted!\n\n");
    
    int unsorted[] = {30, 10, 50, 20, 60, 40};
    int result = binary_search_iterative(unsorted, 6, 20);
    
    printf("\nNow let's sort the array first:\n");
    int sorted[] = {10, 20, 30, 40, 50, 60};
    printf("Sorted array: ");
    display_array(sorted, 6);
    
    printf("Searching for 20 in sorted array:\n");
    result = binary_search_iterative(sorted, 6, 20);
    
    if (result != -1) {
        printf("Correct! Element 20 found at index %d\n", result);
    }
}

/*
 * Main demonstration function
 */
void demonstrate_binary_search() {
    printf("=== BINARY SEARCH ALGORITHM DEMONSTRATION ===\n\n");
    
    // Sorted array for demonstration
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("1. Basic Binary Search (Iterative):\n");
    printf("Sorted array: ");
    display_array(arr, size);
    
    // Search for existing element
    printf("\nSearching for element 60:\n");
    int result = binary_search_iterative(arr, size, 60);
    if (result != -1) {
        printf("Element 60 found at index %d\n", result);
    }
    
    // Search for non-existing element
    printf("\nSearching for element 55:\n");
    result = binary_search_iterative(arr, size, 55);
    
    // Recursive binary search
    printf("\n2. Recursive Binary Search:\n");
    printf("Searching for element 30 using recursive approach:\n");
    result = binary_search_recursive(arr, 0, size - 1, 30, 1);
    
    // Handle duplicates
    printf("\n3. Handling Duplicates:\n");
    int arr_dup[] = {10, 20, 20, 20, 30, 40, 50, 60, 70, 80};
    int size_dup = 10;
    printf("Array with duplicates: ");
    display_array(arr_dup, size_dup);
    
    int first = binary_search_first_occurrence(arr_dup, size_dup, 20);
    int last = binary_search_last_occurrence(arr_dup, size_dup, 20);
    
    if (first != -1) {
        printf("Element 20: First occurrence at index %d, Last occurrence at index %d\n", 
               first, last);
        printf("Total occurrences: %d\n", last - first + 1);
    }
    
    // Insertion point
    printf("\n4. Finding Insertion Point:\n");
    binary_search_insertion_point(arr, size, 55);
    
    // Performance comparison
    compare_search_performance();
    
    // Practical example
    practical_example_phone_book();
    
    // Sorted requirement
    demonstrate_sorted_requirement();
}

int main() {
    demonstrate_binary_search();
    return 0;
}