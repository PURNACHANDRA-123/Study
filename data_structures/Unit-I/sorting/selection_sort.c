/*
 * SELECTION SORT ALGORITHM
 * ========================
 * 
 * What is Selection Sort?
 * -----------------------
 * Selection sort is like organizing a deck of cards. You look through all the
 * cards, find the smallest one, and put it at the beginning. Then you look
 * through the remaining cards, find the smallest, and put it in the second
 * position. You repeat this process until all cards are sorted.
 * 
 * How it works:
 * 1. Find the minimum element in the array
 * 2. Swap it with the first element
 * 3. Find the minimum element in the remaining array (excluding first)
 * 4. Swap it with the second element
 * 5. Repeat until the entire array is sorted
 * 
 * Example:
 * Initial: [64, 25, 12, 22, 11]
 * Step 1:  [11, 25, 12, 22, 64]  (11 is minimum, swap with 64)
 * Step 2:  [11, 12, 25, 22, 64]  (12 is minimum in remaining, swap with 25)
 * Step 3:  [11, 12, 22, 25, 64]  (22 is minimum in remaining, swap with 25)
 * Step 4:  [11, 12, 22, 25, 64]  (25 is minimum in remaining, no swap needed)
 * Result:  [11, 12, 22, 25, 64]  (Sorted!)
 * 
 * Time Complexity: O(n²) - Always, regardless of input
 * Space Complexity: O(1) - Only uses a few extra variables
 * 
 * Characteristics:
 * - Not stable (relative order of equal elements may change)
 * - In-place sorting (doesn't need extra space)
 * - Simple to understand and implement
 * - Performance doesn't depend on initial order of elements
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * Function to swap two elements
 * Helper function used in sorting
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Function to display array
 */
void display_array(int arr[], int size, char *message) {
    printf("%s: [", message);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

/*
 * Selection Sort with step-by-step explanation
 */
void selection_sort_detailed(int arr[], int size) {
    printf("\n=== SELECTION SORT STEP-BY-STEP ===\n");
    display_array(arr, size, "Initial array");
    
    for (int i = 0; i < size - 1; i++) {
        // Find the minimum element in remaining unsorted array
        int min_index = i;
        
        printf("\nStep %d: Finding minimum in range [%d, %d]\n", i + 1, i, size - 1);
        printf("  Starting with arr[%d] = %d as minimum\n", i, arr[i]);
        
        for (int j = i + 1; j < size; j++) {
            printf("  Comparing arr[%d] = %d with current minimum %d: ", 
                   j, arr[j], arr[min_index]);
            
            if (arr[j] < arr[min_index]) {
                min_index = j;
                printf("New minimum found!\n");
            } else {
                printf("Current minimum remains\n");
            }
        }
        
        // Swap the found minimum element with the first element
        if (min_index != i) {
            printf("  Swapping arr[%d] = %d with arr[%d] = %d\n", 
                   i, arr[i], min_index, arr[min_index]);
            swap(&arr[i], &arr[min_index]);
        } else {
            printf("  No swap needed (minimum is already in correct position)\n");
        }
        
        display_array(arr, size, "  Array after step");
        
        // Show sorted and unsorted portions
        printf("  Sorted portion: [");
        for (int k = 0; k <= i; k++) {
            printf("%d", arr[k]);
            if (k < i) printf(", ");
        }
        printf("], Unsorted portion: [");
        for (int k = i + 1; k < size; k++) {
            printf("%d", arr[k]);
            if (k < size - 1) printf(", ");
        }
        printf("]\n");
    }
    
    display_array(arr, size, "\nFinal sorted array");
}

/*
 * Standard Selection Sort implementation
 */
void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        
        // Find minimum element in remaining array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        // Swap minimum element with first element
        if (min_index != i) {
            swap(&arr[i], &arr[min_index]);
        }
    }
}

/*
 * Selection Sort with comparison and swap counting
 */
void selection_sort_with_count(int arr[], int size, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;
    
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        
        for (int j = i + 1; j < size; j++) {
            (*comparisons)++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        if (min_index != i) {
            swap(&arr[i], &arr[min_index]);
            (*swaps)++;
        }
    }
}

/*
 * Selection Sort for finding K smallest elements
 * Useful when you only need top few elements
 */
void selection_sort_k_smallest(int arr[], int size, int k) {
    printf("\nFinding %d smallest elements using Selection Sort:\n", k);
    display_array(arr, size, "Original array");
    
    for (int i = 0; i < k && i < size - 1; i++) {
        int min_index = i;
        
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        if (min_index != i) {
            swap(&arr[i], &arr[min_index]);
        }
        
        printf("After finding %d smallest: ", i + 1);
        for (int p = 0; p < size; p++) {
            if (p <= i) printf("[%d] ", arr[p]);  // Brackets for sorted portion
            else printf("%d ", arr[p]);
        }
        printf("\n");
    }
    
    printf("\n%d smallest elements: [", k);
    for (int i = 0; i < k && i < size; i++) {
        printf("%d", arr[i]);
        if (i < k - 1 && i < size - 1) printf(", ");
    }
    printf("]\n");
}

/*
 * Selection Sort in descending order
 */
void selection_sort_descending(int arr[], int size) {
    printf("\nSelection Sort in Descending Order:\n");
    display_array(arr, size, "Original array");
    
    for (int i = 0; i < size - 1; i++) {
        int max_index = i;
        
        // Find maximum element instead of minimum
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        
        if (max_index != i) {
            swap(&arr[i], &arr[max_index]);
        }
    }
    
    display_array(arr, size, "Sorted array (descending)");
}

/*
 * Performance analysis of Selection Sort
 */
void analyze_selection_sort_performance() {
    printf("\n=== SELECTION SORT PERFORMANCE ANALYSIS ===\n");
    
    int sizes[] = {10, 50, 100, 500};
    int num_sizes = 4;
    
    printf("%-10s %-15s %-15s %-20s\n", "Size", "Comparisons", "Swaps", "Time Complexity");
    printf("-------------------------------------------------------------\n");
    
    for (int s = 0; s < num_sizes; s++) {
        int size = sizes[s];
        int *arr = (int*)malloc(size * sizeof(int));
        
        // Fill array with random numbers
        srand(42);  // Fixed seed for consistent results
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 1000;
        }
        
        int comparisons, swaps;
        selection_sort_with_count(arr, size, &comparisons, &swaps);
        
        printf("%-10d %-15d %-15d O(n²) = O(%d)\n", 
               size, comparisons, swaps, size * size);
        
        free(arr);
    }
    
    printf("\nKey Observations:\n");
    printf("- Comparisons: Always n(n-1)/2, regardless of input order\n");
    printf("- Swaps: At most n-1 (one per iteration)\n");
    printf("- Time complexity is always O(n²)\n");
    printf("- Space complexity is O(1)\n");
}

/*
 * Compare different scenarios
 */
void compare_different_scenarios() {
    printf("\n=== SELECTION SORT: DIFFERENT INPUT SCENARIOS ===\n");
    
    // Already sorted array
    printf("1. Already Sorted Array:\n");
    int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int *test_arr = (int*)malloc(size * sizeof(int));
    
    for (int i = 0; i < size; i++) test_arr[i] = sorted[i];
    display_array(test_arr, size, "Input");
    int comparisons, swaps;
    selection_sort_with_count(test_arr, size, &comparisons, &swaps);
    display_array(test_arr, size, "Output");
    printf("Comparisons: %d, Swaps: %d\n", comparisons, swaps);
    
    // Reverse sorted array
    printf("\n2. Reverse Sorted Array:\n");
    int reverse[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (int i = 0; i < size; i++) test_arr[i] = reverse[i];
    display_array(test_arr, size, "Input");
    selection_sort_with_count(test_arr, size, &comparisons, &swaps);
    display_array(test_arr, size, "Output");
    printf("Comparisons: %d, Swaps: %d\n", comparisons, swaps);
    
    // Random array
    printf("\n3. Random Array:\n");
    srand(time(NULL));
    for (int i = 0; i < size; i++) test_arr[i] = rand() % 50;
    display_array(test_arr, size, "Input");
    selection_sort_with_count(test_arr, size, &comparisons, &swaps);
    display_array(test_arr, size, "Output");
    printf("Comparisons: %d, Swaps: %d\n", comparisons, swaps);
    
    free(test_arr);
}

/*
 * Practical example: Sorting student grades
 */
void practical_example_student_grades() {
    printf("\n=== PRACTICAL EXAMPLE: SORTING STUDENT GRADES ===\n");
    
    int grades[] = {85, 92, 78, 96, 87, 73, 89, 94, 81, 88};
    int size = 10;
    char names[][20] = {"Alice", "Bob", "Charlie", "Diana", "Eve", 
                       "Frank", "Grace", "Henry", "Ivy", "Jack"};
    
    printf("Student Grades Before Sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", names[i], grades[i]);
    }
    
    printf("\nSorting grades using Selection Sort...\n");
    
    // Modified selection sort to also rearrange names
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        
        for (int j = i + 1; j < size; j++) {
            if (grades[j] < grades[min_index]) {
                min_index = j;
            }
        }
        
        if (min_index != i) {
            // Swap grades
            int temp_grade = grades[i];
            grades[i] = grades[min_index];
            grades[min_index] = temp_grade;
            
            // Swap corresponding names
            char temp_name[20];
            strcpy(temp_name, names[i]);
            strcpy(names[i], names[min_index]);
            strcpy(names[min_index], temp_name);
        }
    }
    
    printf("\nStudent Grades After Sorting (Ascending):\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", names[i], grades[i]);
    }
}

/*
 * Main demonstration function
 */
void demonstrate_selection_sort() {
    printf("=== SELECTION SORT ALGORITHM DEMONSTRATION ===\n");
    
    // Basic demonstration
    int arr[] = {64, 25, 12, 22, 11, 90, 88, 76, 50, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int *demo_arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) demo_arr[i] = arr[i];
    
    selection_sort_detailed(demo_arr, size);
    
    // K smallest elements
    printf("\n================================================\n");
    for (int i = 0; i < size; i++) demo_arr[i] = arr[i];  // Reset array
    selection_sort_k_smallest(demo_arr, size, 3);
    
    // Descending order
    printf("\n================================================\n");
    for (int i = 0; i < size; i++) demo_arr[i] = arr[i];  // Reset array
    selection_sort_descending(demo_arr, size);
    
    // Performance analysis
    analyze_selection_sort_performance();
    
    // Different scenarios
    compare_different_scenarios();
    
    // Practical example
    practical_example_student_grades();
    
    free(demo_arr);
}

int main() {
    demonstrate_selection_sort();
    return 0;
}