/*
 * BUBBLE SORT ALGORITHM
 * =====================
 * 
 * What is Bubble Sort?
 * --------------------
 * Bubble sort is like bubbles rising to the surface of water. In this algorithm,
 * larger elements "bubble up" to the end of the array by repeatedly swapping
 * adjacent elements that are in the wrong order.
 * 
 * Think of it like this: You have a line of students arranged by height, but
 * they're not in order. You go down the line comparing each pair of adjacent
 * students. If the taller student is in front of the shorter one, you swap them.
 * After one complete pass, the tallest student will be at the end.
 * 
 * How it works:
 * 1. Compare adjacent elements (arr[i] and arr[i+1])
 * 2. If they are in wrong order, swap them
 * 3. Continue through the entire array
 * 4. After one pass, the largest element is at the end
 * 5. Repeat for the remaining elements
 * 6. Stop when no swaps are needed
 * 
 * Example:
 * Initial: [64, 34, 25, 12, 22]
 * Pass 1:  [34, 25, 12, 22, 64]  (64 bubbles to the end)
 * Pass 2:  [25, 12, 22, 34, 64]  (34 bubbles to second last)
 * Pass 3:  [12, 22, 25, 34, 64]  (25 bubbles to third last)
 * Pass 4:  [12, 22, 25, 34, 64]  (22 bubbles to fourth last)
 * Result:  [12, 22, 25, 34, 64]  (Sorted!)
 * 
 * Time Complexity: 
 * - Best case: O(n) when array is already sorted
 * - Average case: O(n²)
 * - Worst case: O(n²) when array is reverse sorted
 * 
 * Space Complexity: O(1) - Only uses a few extra variables
 * 
 * Characteristics:
 * - Stable sorting (maintains relative order of equal elements)
 * - In-place sorting (doesn't need extra space)
 * - Simple to understand and implement
 * - Adaptive (performs better on partially sorted arrays)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/*
 * Function to swap two elements
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
 * Bubble Sort with detailed step-by-step explanation
 */
void bubble_sort_detailed(int arr[], int size) {
    printf("\n=== BUBBLE SORT STEP-BY-STEP ===\n");
    display_array(arr, size, "Initial array");
    
    int total_swaps = 0;
    
    for (int pass = 0; pass < size - 1; pass++) {
        printf("\n--- PASS %d ---\n", pass + 1);
        int swaps_in_pass = 0;
        bool swapped = false;
        
        for (int i = 0; i < size - pass - 1; i++) {
            printf("Comparing arr[%d]=%d and arr[%d]=%d: ", 
                   i, arr[i], i + 1, arr[i + 1]);
            
            if (arr[i] > arr[i + 1]) {
                printf("Swap needed! ");
                swap(&arr[i], &arr[i + 1]);
                swaps_in_pass++;
                total_swaps++;
                swapped = true;
                printf("Result: arr[%d]=%d, arr[%d]=%d\n", 
                       i, arr[i], i + 1, arr[i + 1]);
            } else {
                printf("No swap needed\n");
            }
        }
        
        display_array(arr, size, "Array after pass");
        printf("Swaps in this pass: %d\n", swaps_in_pass);
        
        // Show which elements are in their final position
        printf("Fixed positions: ");
        for (int j = size - 1; j >= size - pass - 1; j--) {
            printf("arr[%d]=%d ", j, arr[j]);
        }
        printf("\n");
        
        // Early termination if no swaps occurred
        if (!swapped) {
            printf("No swaps in this pass - array is sorted!\n");
            break;
        }
    }
    
    printf("\nTotal swaps performed: %d\n", total_swaps);
    display_array(arr, size, "Final sorted array");
}

/*
 * Standard Bubble Sort implementation
 */
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/*
 * Optimized Bubble Sort (stops early if array becomes sorted)
 */
void bubble_sort_optimized(int arr[], int size, int *passes, int *comparisons, int *swaps) {
    *passes = 0;
    *comparisons = 0;
    *swaps = 0;
    
    for (int i = 0; i < size - 1; i++) {
        (*passes)++;
        bool swapped = false;
        
        for (int j = 0; j < size - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                (*swaps)++;
                swapped = true;
            }
        }
        
        // If no swapping occurred, array is sorted
        if (!swapped) {
            break;
        }
    }
}

/*
 * Bubble Sort for finding largest K elements
 */
void bubble_sort_k_largest(int arr[], int size, int k) {
    printf("\nFinding %d largest elements using Bubble Sort:\n", k);
    display_array(arr, size, "Original array");
    
    for (int pass = 0; pass < k && pass < size - 1; pass++) {
        printf("\nPass %d (finding element for position %d):\n", 
               pass + 1, size - pass - 1);
        
        for (int i = 0; i < size - pass - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
            }
        }
        
        printf("After pass %d: ", pass + 1);
        for (int p = 0; p < size; p++) {
            if (p >= size - pass - 1) printf("[%d] ", arr[p]);  // Brackets for sorted portion
            else printf("%d ", arr[p]);
        }
        printf("\n");
    }
    
    printf("\n%d largest elements: [", k);
    for (int i = size - k; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

/*
 * Bubble Sort in descending order
 */
void bubble_sort_descending(int arr[], int size) {
    printf("\nBubble Sort in Descending Order:\n");
    display_array(arr, size, "Original array");
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Change condition to sort in descending order
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    
    display_array(arr, size, "Sorted array (descending)");
}

/*
 * Cocktail Shaker Sort (Bidirectional Bubble Sort)
 * Bubbles in both directions
 */
void cocktail_shaker_sort(int arr[], int size) {
    printf("\nCocktail Shaker Sort (Bidirectional Bubble Sort):\n");
    display_array(arr, size, "Original array");
    
    int start = 0;
    int end = size - 1;
    bool swapped = true;
    int pass = 1;
    
    while (swapped) {
        swapped = false;
        
        printf("\nPass %d - Left to Right:\n", pass);
        // Forward pass
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        end--;
        
        if (!swapped) break;
        
        printf("After forward pass: ");
        for (int p = 0; p < size; p++) {
            printf("%d ", arr[p]);
        }
        printf("\n");
        
        printf("Pass %d - Right to Left:\n", pass);
        swapped = false;
        
        // Backward pass
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(&arr[i], &arr[i - 1]);
                swapped = true;
            }
        }
        start++;
        
        printf("After backward pass: ");
        for (int p = 0; p < size; p++) {
            printf("%d ", arr[p]);
        }
        printf("\n");
        
        pass++;
    }
    
    display_array(arr, size, "Final sorted array");
}

/*
 * Performance analysis of Bubble Sort
 */
void analyze_bubble_sort_performance() {
    printf("\n=== BUBBLE SORT PERFORMANCE ANALYSIS ===\n");
    
    int sizes[] = {10, 50, 100};
    int num_sizes = 3;
    
    printf("%-10s %-8s %-12s %-12s %-8s %-15s\n", 
           "Scenario", "Size", "Passes", "Comparisons", "Swaps", "Time Complexity");
    printf("------------------------------------------------------------------\n");
    
    for (int s = 0; s < num_sizes; s++) {
        int size = sizes[s];
        int *arr = (int*)malloc(size * sizeof(int));
        
        // Test 1: Already sorted array (Best case)
        for (int i = 0; i < size; i++) arr[i] = i + 1;
        int passes, comparisons, swaps;
        bubble_sort_optimized(arr, size, &passes, &comparisons, &swaps);
        printf("%-10s %-8d %-12d %-12d %-8d O(n)\n", 
               "Best", size, passes, comparisons, swaps);
        
        // Test 2: Reverse sorted array (Worst case)
        for (int i = 0; i < size; i++) arr[i] = size - i;
        bubble_sort_optimized(arr, size, &passes, &comparisons, &swaps);
        printf("%-10s %-8d %-12d %-12d %-8d O(n²)\n", 
               "Worst", size, passes, comparisons, swaps);
        
        // Test 3: Random array (Average case)
        srand(42);  // Fixed seed for consistent results
        for (int i = 0; i < size; i++) arr[i] = rand() % 100;
        bubble_sort_optimized(arr, size, &passes, &comparisons, &swaps);
        printf("%-10s %-8d %-12d %-12d %-8d O(n²)\n", 
               "Average", size, passes, comparisons, swaps);
        
        if (s < num_sizes - 1) printf("\n");
        free(arr);
    }
}

/*
 * Compare different scenarios
 */
void compare_different_scenarios() {
    printf("\n=== BUBBLE SORT: DIFFERENT INPUT SCENARIOS ===\n");
    
    int size = 8;
    int *test_arr = (int*)malloc(size * sizeof(int));
    
    // Nearly sorted array
    printf("1. Nearly Sorted Array (only one element out of place):\n");
    int nearly_sorted[] = {1, 2, 3, 4, 6, 5, 7, 8};
    for (int i = 0; i < size; i++) test_arr[i] = nearly_sorted[i];
    display_array(test_arr, size, "Input");
    int passes, comparisons, swaps;
    bubble_sort_optimized(test_arr, size, &passes, &comparisons, &swaps);
    display_array(test_arr, size, "Output");
    printf("Passes: %d, Comparisons: %d, Swaps: %d\n", passes, comparisons, swaps);
    
    // Array with duplicates
    printf("\n2. Array with Duplicate Elements:\n");
    int duplicates[] = {5, 2, 8, 2, 9, 1, 5, 5};
    for (int i = 0; i < size; i++) test_arr[i] = duplicates[i];
    display_array(test_arr, size, "Input");
    bubble_sort_optimized(test_arr, size, &passes, &comparisons, &swaps);
    display_array(test_arr, size, "Output");
    printf("Passes: %d, Comparisons: %d, Swaps: %d\n", passes, comparisons, swaps);
    
    free(test_arr);
}

/*
 * Practical example: Sorting temperatures
 */
void practical_example_temperatures() {
    printf("\n=== PRACTICAL EXAMPLE: SORTING DAILY TEMPERATURES ===\n");
    
    float temperatures[] = {23.5, 19.2, 25.8, 21.1, 27.3, 18.9, 24.6, 22.4};
    int size = 8;
    char days[][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
                      "Friday", "Saturday", "Sunday", "Next Mon"};
    
    printf("Daily Temperatures Before Sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %.1f°C\n", days[i], temperatures[i]);
    }
    
    printf("\nSorting temperatures using Bubble Sort...\n");
    
    // Modified bubble sort for floats with corresponding day names
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (temperatures[j] > temperatures[j + 1]) {
                // Swap temperatures
                float temp_val = temperatures[j];
                temperatures[j] = temperatures[j + 1];
                temperatures[j + 1] = temp_val;
                
                // Swap corresponding day names
                char temp_day[10];
                strcpy(temp_day, days[j]);
                strcpy(days[j], days[j + 1]);
                strcpy(days[j + 1], temp_day);
                
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    
    printf("\nDaily Temperatures After Sorting (Ascending):\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %.1f°C\n", days[i], temperatures[i]);
    }
}

/*
 * Demonstrate why Bubble Sort is called "Bubble" Sort
 */
void demonstrate_bubbling_effect() {
    printf("\n=== WHY IT'S CALLED \"BUBBLE\" SORT ===\n");
    
    int arr[] = {5, 2, 8, 1, 9};
    int size = 5;
    
    printf("Watch how the largest element (9) 'bubbles up' to the top:\n");
    display_array(arr, size, "Initial");
    
    printf("\nFirst pass - tracking element 9:\n");
    for (int i = 0; i < size - 1; i++) {
        printf("Step %d: Compare arr[%d]=%d and arr[%d]=%d -> ", 
               i + 1, i, arr[i], i + 1, arr[i + 1]);
        
        if (arr[i] > arr[i + 1]) {
            swap(&arr[i], &arr[i + 1]);
            printf("Swap -> ");
        } else {
            printf("No swap -> ");
        }
        
        // Show current array with 9 highlighted
        printf("[");
        for (int j = 0; j < size; j++) {
            if (arr[j] == 9) printf("*%d*", arr[j]);
            else printf("%d", arr[j]);
            if (j < size - 1) printf(", ");
        }
        printf("]\n");
    }
    
    printf("\nElement 9 has 'bubbled up' to its correct position at the end!\n");
}

/*
 * Main demonstration function
 */
void demonstrate_bubble_sort() {
    printf("=== BUBBLE SORT ALGORITHM DEMONSTRATION ===\n");
    
    // Basic demonstration
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int *demo_arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) demo_arr[i] = arr[i];
    
    bubble_sort_detailed(demo_arr, size);
    
    // Demonstrate bubbling effect
    demonstrate_bubbling_effect();
    
    // K largest elements
    printf("\n================================================\n");
    for (int i = 0; i < size; i++) demo_arr[i] = arr[i];  // Reset array
    bubble_sort_k_largest(demo_arr, size, 3);
    
    // Descending order
    printf("\n================================================\n");
    for (int i = 0; i < size; i++) demo_arr[i] = arr[i];  // Reset array
    bubble_sort_descending(demo_arr, size);
    
    // Cocktail shaker sort
    printf("\n================================================\n");
    for (int i = 0; i < size; i++) demo_arr[i] = arr[i];  // Reset array
    cocktail_shaker_sort(demo_arr, size);
    
    // Performance analysis
    analyze_bubble_sort_performance();
    
    // Different scenarios
    compare_different_scenarios();
    
    // Practical example
    practical_example_temperatures();
    
    free(demo_arr);
}

int main() {
    demonstrate_bubble_sort();
    return 0;
}