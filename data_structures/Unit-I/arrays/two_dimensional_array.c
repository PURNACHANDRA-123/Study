/*
 * TWO-DIMENSIONAL ARRAY IMPLEMENTATION
 * ====================================
 * 
 * What is a Two-Dimensional Array?
 * --------------------------------
 * A 2D array is like a table or a chess board with rows and columns.
 * Think of it as multiple one-dimensional arrays placed one below the other.
 * 
 * Visual representation of a 3x4 array:
 * 
 *      Column 0  Column 1  Column 2  Column 3
 * Row 0   [10]     [20]     [30]     [40]
 * Row 1   [50]     [60]     [70]     [80]
 * Row 2   [90]     [100]    [110]    [120]
 * 
 * To access element: arr[row][column]
 * Example: arr[1][2] = 70
 * 
 * Memory Representation:
 * ----------------------
 * Even though we think of it as a table, computer stores it as a continuous line:
 * [10][20][30][40][50][60][70][80][90][100][110][120]
 * 
 * Formula for memory address:
 * Address = Base_Address + ((row * num_columns) + column) * size_of_element
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

/*
 * Function to display a 2D array in table format
 * This makes it easy to see the structure
 */
void display_2d_array(int arr[][MAX_COLS], int rows, int cols) {
    printf("\n2D Array (Table format):\n");
    printf("   ");
    
    // Print column headers
    for (int j = 0; j < cols; j++) {
        printf("Col%d  ", j);
    }
    printf("\n");
    
    // Print rows with data
    for (int i = 0; i < rows; i++) {
        printf("R%d ", i);
        for (int j = 0; j < cols; j++) {
            printf("%4d  ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * Function to initialize a 2D array with sample values
 */
void initialize_2d_array(int arr[][MAX_COLS], int rows, int cols) {
    int value = 10;
    printf("Initializing %dx%d array with values starting from %d:\n", rows, cols, value);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value;
            value += 10;
        }
    }
}

/*
 * Function to traverse (visit) all elements of 2D array
 * Row-wise traversal: go through each row from left to right
 */
void traverse_row_wise(int arr[][MAX_COLS], int rows, int cols) {
    printf("Row-wise traversal (left to right, top to bottom):\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

/*
 * Function to traverse column-wise
 * Column-wise traversal: go through each column from top to bottom
 */
void traverse_column_wise(int arr[][MAX_COLS], int rows, int cols) {
    printf("\nColumn-wise traversal (top to bottom, left to right):\n");
    for (int j = 0; j < cols; j++) {
        printf("Column %d: ", j);
        for (int i = 0; i < rows; i++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

/*
 * Function to search for an element in 2D array
 * Returns 1 if found, 0 if not found
 */
int search_2d_array(int arr[][MAX_COLS], int rows, int cols, int target, int *found_row, int *found_col) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == target) {
                *found_row = i;
                *found_col = j;
                return 1;  // Found
            }
        }
    }
    return 0;  // Not found
}

/*
 * Function to insert an element at specific position
 * (Replace the existing element)
 */
void insert_element_2d(int arr[][MAX_COLS], int rows, int cols, int element, int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        int old_value = arr[row][col];
        arr[row][col] = element;
        printf("Element %d inserted at position [%d][%d] (replaced %d)\n", 
               element, row, col, old_value);
    } else {
        printf("Error: Invalid position [%d][%d]\n", row, col);
    }
}

/*
 * Function to calculate sum of all elements
 */
int calculate_sum_2d(int arr[][MAX_COLS], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

/*
 * Function to find maximum and minimum elements
 */
void find_max_min_2d(int arr[][MAX_COLS], int rows, int cols, int *max, int *min) {
    *max = arr[0][0];
    *min = arr[0][0];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > *max) {
                *max = arr[i][j];
            }
            if (arr[i][j] < *min) {
                *min = arr[i][j];
            }
        }
    }
}

/*
 * Function to transpose a matrix (swap rows and columns)
 * Original:     Transposed:
 * [1 2 3]      [1 4]
 * [4 5 6]  =>  [2 5]
 *              [3 6]
 */
void transpose_matrix(int arr[][MAX_COLS], int rows, int cols, int result[][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = arr[i][j];
        }
    }
    printf("Matrix transposed successfully!\n");
}

/*
 * Function to demonstrate memory layout
 */
void explain_memory_layout_2d() {
    printf("\n=== MEMORY LAYOUT EXPLANATION ===\n");
    
    int arr[3][4] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120}
    };
    
    printf("2D Array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMemory addresses:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("arr[%d][%d] = %3d, Address = %p\n", 
                   i, j, arr[i][j], (void*)&arr[i][j]);
        }
    }
    
    printf("\nNotice: Memory is continuous even though we think of it as a table!\n");
}

/*
 * Main demonstration function
 */
void demonstrate_2d_array_operations() {
    int arr[MAX_ROWS][MAX_COLS];
    int rows = 3, cols = 4;
    
    printf("=== TWO-DIMENSIONAL ARRAY DEMONSTRATION ===\n\n");
    
    // 1. Initialize array
    initialize_2d_array(arr, rows, cols);
    display_2d_array(arr, rows, cols);
    
    // 2. Traversal operations
    printf("2. Traversal Operations:\n");
    traverse_row_wise(arr, rows, cols);
    traverse_column_wise(arr, rows, cols);
    
    // 3. Search operation
    printf("\n3. Search Operation:\n");
    int target = 70;
    int found_row, found_col;
    if (search_2d_array(arr, rows, cols, target, &found_row, &found_col)) {
        printf("Element %d found at position [%d][%d]\n", target, found_row, found_col);
    } else {
        printf("Element %d not found\n", target);
    }
    
    // 4. Insert operation
    printf("\n4. Insert Operation:\n");
    insert_element_2d(arr, rows, cols, 999, 1, 2);
    display_2d_array(arr, rows, cols);
    
    // 5. Calculate sum
    printf("5. Sum of all elements: %d\n", calculate_sum_2d(arr, rows, cols));
    
    // 6. Find max and min
    int max, min;
    find_max_min_2d(arr, rows, cols, &max, &min);
    printf("Maximum element: %d, Minimum element: %d\n", max, min);
    
    // 7. Transpose
    printf("\n7. Matrix Transpose:\n");
    int transposed[MAX_ROWS][MAX_COLS];
    transpose_matrix(arr, rows, cols, transposed);
    printf("Original matrix:\n");
    display_2d_array(arr, rows, cols);
    printf("Transposed matrix:\n");
    display_2d_array(transposed, cols, rows);  // Note: rows and cols are swapped
}

int main() {
    demonstrate_2d_array_operations();
    explain_memory_layout_2d();
    
    return 0;
}