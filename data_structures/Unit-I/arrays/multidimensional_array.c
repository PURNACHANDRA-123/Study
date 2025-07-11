/*
 * MULTIDIMENSIONAL ARRAY IMPLEMENTATION
 * =====================================
 * 
 * What is a Multidimensional Array?
 * ---------------------------------
 * A multidimensional array is like having multiple tables stacked on top of each other.
 * 
 * 1D Array: A single row of boxes
 * 2D Array: A table (rows and columns)
 * 3D Array: Multiple tables stacked (like a cube)
 * 4D Array: Multiple cubes arranged (like time-series of cubes)
 * 
 * Example of 3D Array (2x3x4):
 * Think of it as 2 tables, each having 3 rows and 4 columns
 * 
 * Table 0:          Table 1:
 * [1  2  3  4]      [13 14 15 16]
 * [5  6  7  8]      [17 18 19 20]
 * [9  10 11 12]     [21 22 23 24]
 * 
 * To access: arr[table][row][column]
 * Example: arr[1][2][3] = 24
 * 
 * Memory Formula for 3D:
 * Address = Base + ((table * rows * cols) + (row * cols) + col) * sizeof(element)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLES 5
#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_DIMENSION 4

/*
 * Function to display a 3D array
 * Shows each table separately for easy understanding
 */
void display_3d_array(int arr[][MAX_ROWS][MAX_COLS], int tables, int rows, int cols) {
    printf("\n3D Array Display:\n");
    printf("================\n");
    
    for (int t = 0; t < tables; t++) {
        printf("Table %d:\n", t);
        printf("--------\n");
        
        // Print column headers
        printf("    ");
        for (int j = 0; j < cols; j++) {
            printf("C%-3d", j);
        }
        printf("\n");
        
        // Print rows with data
        for (int i = 0; i < rows; i++) {
            printf("R%d: ", i);
            for (int j = 0; j < cols; j++) {
                printf("%-4d", arr[t][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

/*
 * Function to initialize 3D array with sequential values
 */
void initialize_3d_array(int arr[][MAX_ROWS][MAX_COLS], int tables, int rows, int cols) {
    int value = 1;
    printf("Initializing 3D array (%dx%dx%d) with sequential values:\n", tables, rows, cols);
    
    for (int t = 0; t < tables; t++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[t][i][j] = value++;
            }
        }
    }
}

/*
 * Function to traverse 3D array in different ways
 */
void traverse_3d_array(int arr[][MAX_ROWS][MAX_COLS], int tables, int rows, int cols) {
    printf("3D Array Traversal Methods:\n");
    printf("===========================\n");
    
    // Method 1: Table by table
    printf("1. Table-wise traversal:\n");
    for (int t = 0; t < tables; t++) {
        printf("Table %d: ", t);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", arr[t][i][j]);
            }
        }
        printf("\n");
    }
    
    // Method 2: Row by row across all tables
    printf("\n2. Row-wise across tables:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i);
        for (int t = 0; t < tables; t++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", arr[t][i][j]);
            }
        }
        printf("\n");
    }
    
    // Method 3: Column by column across all tables
    printf("\n3. Column-wise across tables:\n");
    for (int j = 0; j < cols; j++) {
        printf("Column %d: ", j);
        for (int t = 0; t < tables; t++) {
            for (int i = 0; i < rows; i++) {
                printf("%d ", arr[t][i][j]);
            }
        }
        printf("\n");
    }
}

/*
 * Function to search in 3D array
 */
int search_3d_array(int arr[][MAX_ROWS][MAX_COLS], int tables, int rows, int cols, 
                   int target, int *found_table, int *found_row, int *found_col) {
    for (int t = 0; t < tables; t++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (arr[t][i][j] == target) {
                    *found_table = t;
                    *found_row = i;
                    *found_col = j;
                    return 1;  // Found
                }
            }
        }
    }
    return 0;  // Not found
}

/*
 * Function to calculate sum of all elements in 3D array
 */
int calculate_sum_3d(int arr[][MAX_ROWS][MAX_COLS], int tables, int rows, int cols) {
    int sum = 0;
    for (int t = 0; t < tables; t++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum += arr[t][i][j];
            }
        }
    }
    return sum;
}

/*
 * Function to demonstrate 4D array concept
 * 4D array is like having multiple 3D arrays
 */
void demonstrate_4d_concept() {
    printf("\n=== 4D ARRAY CONCEPT ===\n");
    printf("A 4D array can be thought of as multiple 3D arrays.\n");
    printf("Example: arr[w][x][y][z] where:\n");
    printf("- w: Which 3D array (like time periods)\n");
    printf("- x: Which table in that 3D array\n");
    printf("- y: Which row in that table\n");
    printf("- z: Which column in that row\n\n");
    
    // Small 4D array example (2x2x2x2)
    int arr_4d[2][2][2][2];
    int value = 1;
    
    // Initialize
    for (int w = 0; w < 2; w++) {
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                for (int z = 0; z < 2; z++) {
                    arr_4d[w][x][y][z] = value++;
                }
            }
        }
    }
    
    // Display
    for (int w = 0; w < 2; w++) {
        printf("3D Array %d:\n", w);
        for (int x = 0; x < 2; x++) {
            printf("  Table %d: ", x);
            for (int y = 0; y < 2; y++) {
                for (int z = 0; z < 2; z++) {
                    printf("%d ", arr_4d[w][x][y][z]);
                }
                printf("| ");
            }
            printf("\n");
        }
        printf("\n");
    }
}

/*
 * Function to explain memory layout of 3D array
 */
void explain_3d_memory_layout() {
    printf("=== 3D ARRAY MEMORY LAYOUT ===\n");
    
    int arr[2][2][3] = {
        {{1, 2, 3}, {4, 5, 6}},
        {{7, 8, 9}, {10, 11, 12}}
    };
    
    printf("3D Array structure:\n");
    printf("Table 0: [[1,2,3], [4,5,6]]\n");
    printf("Table 1: [[7,8,9], [10,11,12]]\n\n");
    
    printf("Memory addresses (showing continuous layout):\n");
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                printf("arr[%d][%d][%d] = %2d, Address = %p\n", 
                       t, i, j, arr[t][i][j], (void*)&arr[t][i][j]);
            }
        }
    }
    
    printf("\nNotice: Even 3D arrays are stored continuously in memory!\n");
}

/*
 * Practical application: Student grades system
 * 3D array to store grades: [student][subject][exam]
 */
void practical_example_grades() {
    printf("\n=== PRACTICAL EXAMPLE: STUDENT GRADES ===\n");
    
    // 3 students, 2 subjects, 3 exams each
    int grades[3][2][3] = {
        // Student 0
        {{85, 90, 88}, {92, 87, 91}},  // Math, Science
        // Student 1  
        {{78, 82, 80}, {88, 85, 89}},  // Math, Science
        // Student 2
        {{92, 95, 90}, {85, 88, 87}}   // Math, Science
    };
    
    char subjects[2][10] = {"Math", "Science"};
    
    printf("Student Grade System (3D Array):\n");
    printf("Structure: grades[student][subject][exam]\n\n");
    
    for (int student = 0; student < 3; student++) {
        printf("Student %d:\n", student);
        for (int subject = 0; subject < 2; subject++) {
            printf("  %s: ", subjects[subject]);
            int total = 0;
            for (int exam = 0; exam < 3; exam++) {
                printf("Exam%d=%d ", exam+1, grades[student][subject][exam]);
                total += grades[student][subject][exam];
            }
            printf("(Average: %.1f)\n", total / 3.0);
        }
        printf("\n");
    }
    
    // Find best performing student in Math
    int best_student = 0;
    float best_average = 0;
    
    for (int student = 0; student < 3; student++) {
        int total = 0;
        for (int exam = 0; exam < 3; exam++) {
            total += grades[student][0][exam];  // Math is subject 0
        }
        float average = total / 3.0;
        if (average > best_average) {
            best_average = average;
            best_student = student;
        }
    }
    
    printf("Best Math student: Student %d with average %.1f\n", best_student, best_average);
}

/*
 * Main demonstration function
 */
void demonstrate_multidimensional_arrays() {
    printf("=== MULTIDIMENSIONAL ARRAY DEMONSTRATION ===\n\n");
    
    // 3D Array demonstration
    int arr3d[MAX_TABLES][MAX_ROWS][MAX_COLS];
    int tables = 2, rows = 3, cols = 4;
    
    printf("1. 3D Array Operations:\n");
    initialize_3d_array(arr3d, tables, rows, cols);
    display_3d_array(arr3d, tables, rows, cols);
    
    printf("2. 3D Array Traversal:\n");
    traverse_3d_array(arr3d, tables, rows, cols);
    
    printf("\n3. Search in 3D Array:\n");
    int target = 15;
    int found_table, found_row, found_col;
    if (search_3d_array(arr3d, tables, rows, cols, target, &found_table, &found_row, &found_col)) {
        printf("Element %d found at position [%d][%d][%d]\n", 
               target, found_table, found_row, found_col);
    } else {
        printf("Element %d not found\n", target);
    }
    
    printf("\n4. Sum of all elements: %d\n", calculate_sum_3d(arr3d, tables, rows, cols));
    
    // 4D concept
    demonstrate_4d_concept();
    
    // Memory layout
    explain_3d_memory_layout();
    
    // Practical example
    practical_example_grades();
}

int main() {
    demonstrate_multidimensional_arrays();
    return 0;
}