/*
 * SPARSE MATRIX REPRESENTATION USING LINKED LISTS
 * ================================================
 * 
 * What is a Sparse Matrix?
 * ------------------------
 * A sparse matrix is a matrix where most elements are zero. For example:
 * 
 * Regular Matrix (4x4):
 * [ 0  0  3  0 ]
 * [ 0  0  0  4 ]
 * [ 5  0  0  0 ]
 * [ 0  6  0  0 ]
 * 
 * Only 4 out of 16 elements are non-zero (sparse!)
 * 
 * Why Use Linked Lists for Sparse Matrices?
 * ------------------------------------------
 * - Save memory: Store only non-zero elements
 * - Efficient operations: Skip zero elements
 * - Dynamic: Can grow/shrink as needed
 * 
 * Instead of storing all 16 elements, we store only:
 * (0,2,3), (1,3,4), (2,0,5), (3,1,6)
 * Format: (row, column, value)
 * 
 * Applications:
 * - Computer graphics (many pixels are background color)
 * - Scientific computing (finite element analysis)
 * - Social networks (most people don't know each other)
 * - Image processing (many zero values in transformations)
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Node structure for sparse matrix
 * Each node stores one non-zero element
 */
struct MatrixNode {
    int row;        // Row index
    int col;        // Column index
    int value;      // Non-zero value
    struct MatrixNode* next;  // Pointer to next non-zero element
};

/*
 * Structure to represent the sparse matrix
 */
struct SparseMatrix {
    int rows;       // Total number of rows
    int cols;       // Total number of columns
    int non_zeros;  // Number of non-zero elements
    struct MatrixNode* head;  // Head of linked list
};

/*
 * Function to create a new matrix node
 */
struct MatrixNode* create_matrix_node(int row, int col, int value) {
    struct MatrixNode* new_node = (struct MatrixNode*)malloc(sizeof(struct MatrixNode));
    
    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    
    new_node->row = row;
    new_node->col = col;
    new_node->value = value;
    new_node->next = NULL;
    
    return new_node;
}

/*
 * Function to create a new sparse matrix
 */
struct SparseMatrix* create_sparse_matrix(int rows, int cols) {
    struct SparseMatrix* matrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    
    if (matrix == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->non_zeros = 0;
    matrix->head = NULL;
    
    printf("Created sparse matrix of size %dx%d\n", rows, cols);
    return matrix;
}

/*
 * Function to insert an element in sorted order
 * Elements are sorted by row first, then by column
 */
void insert_element(struct SparseMatrix* matrix, int row, int col, int value) {
    // Don't store zero values
    if (value == 0) {
        printf("Skipping zero value at (%d,%d)\n", row, col);
        return;
    }
    
    // Check bounds
    if (row >= matrix->rows || col >= matrix->cols || row < 0 || col < 0) {
        printf("Error: Position (%d,%d) is out of bounds!\n", row, col);
        return;
    }
    
    struct MatrixNode* new_node = create_matrix_node(row, col, value);
    if (new_node == NULL) return;
    
    // If list is empty or new element should be first
    if (matrix->head == NULL || 
        (matrix->head->row > row) || 
        (matrix->head->row == row && matrix->head->col > col)) {
        
        new_node->next = matrix->head;
        matrix->head = new_node;
        matrix->non_zeros++;
        printf("Inserted (%d,%d,%d) at beginning\n", row, col, value);
        return;
    }
    
    // Find correct position to insert
    struct MatrixNode* current = matrix->head;
    
    while (current->next != NULL) {
        struct MatrixNode* next = current->next;
        
        // Check if we found the position
        if ((next->row > row) || (next->row == row && next->col > col)) {
            break;
        }
        
        // Check for duplicate position
        if (next->row == row && next->col == col) {
            printf("Updating existing element at (%d,%d) from %d to %d\n", 
                   row, col, next->value, value);
            next->value = value;
            free(new_node);
            return;
        }
        
        current = current->next;
    }
    
    // Insert after current
    new_node->next = current->next;
    current->next = new_node;
    matrix->non_zeros++;
    printf("Inserted (%d,%d,%d) in middle/end\n", row, col, value);
}

/*
 * Function to display sparse matrix in coordinate format
 */
void display_sparse_matrix(struct SparseMatrix* matrix) {
    if (matrix == NULL || matrix->head == NULL) {
        printf("Matrix is empty!\n");
        return;
    }
    
    printf("\nSparse Matrix (%dx%d) with %d non-zero elements:\n", 
           matrix->rows, matrix->cols, matrix->non_zeros);
    printf("Row  Col  Value\n");
    printf("---- ---- -----\n");
    
    struct MatrixNode* current = matrix->head;
    while (current != NULL) {
        printf("%-4d %-4d %-5d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

/*
 * Function to display as full matrix (with zeros)
 */
void display_full_matrix(struct SparseMatrix* matrix) {
    if (matrix == NULL) {
        printf("Matrix is empty!\n");
        return;
    }
    
    printf("\nFull Matrix Representation:\n");
    
    struct MatrixNode* current = matrix->head;
    
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            int value = 0;
            
            // Check if there's a non-zero element at this position
            if (current != NULL && current->row == i && current->col == j) {
                value = current->value;
                current = current->next;
            }
            
            printf("%3d ", value);
        }
        printf("\n");
    }
    
    // Reset current pointer for next use
    current = matrix->head;
}

/*
 * Function to get element at specific position
 */
int get_element(struct SparseMatrix* matrix, int row, int col) {
    if (matrix == NULL || row >= matrix->rows || col >= matrix->cols || row < 0 || col < 0) {
        return 0;  // Out of bounds treated as zero
    }
    
    struct MatrixNode* current = matrix->head;
    
    while (current != NULL) {
        if (current->row == row && current->col == col) {
            return current->value;
        }
        if (current->row > row || (current->row == row && current->col > col)) {
            break;  // Element not found
        }
        current = current->next;
    }
    
    return 0;  // Element is zero
}

/*
 * Function to add two sparse matrices
 */
struct SparseMatrix* add_sparse_matrices(struct SparseMatrix* matrix1, struct SparseMatrix* matrix2) {
    if (matrix1 == NULL || matrix2 == NULL) {
        printf("Error: One or both matrices are NULL!\n");
        return NULL;
    }
    
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Error: Matrix dimensions don't match!\n");
        return NULL;
    }
    
    printf("\nAdding two sparse matrices...\n");
    
    struct SparseMatrix* result = create_sparse_matrix(matrix1->rows, matrix1->cols);
    
    struct MatrixNode* ptr1 = matrix1->head;
    struct MatrixNode* ptr2 = matrix2->head;
    
    while (ptr1 != NULL || ptr2 != NULL) {
        if (ptr1 == NULL) {
            // Only elements from matrix2 remain
            insert_element(result, ptr2->row, ptr2->col, ptr2->value);
            ptr2 = ptr2->next;
        }
        else if (ptr2 == NULL) {
            // Only elements from matrix1 remain
            insert_element(result, ptr1->row, ptr1->col, ptr1->value);
            ptr1 = ptr1->next;
        }
        else {
            // Compare positions
            if (ptr1->row < ptr2->row || (ptr1->row == ptr2->row && ptr1->col < ptr2->col)) {
                insert_element(result, ptr1->row, ptr1->col, ptr1->value);
                ptr1 = ptr1->next;
            }
            else if (ptr1->row > ptr2->row || (ptr1->row == ptr2->row && ptr1->col > ptr2->col)) {
                insert_element(result, ptr2->row, ptr2->col, ptr2->value);
                ptr2 = ptr2->next;
            }
            else {
                // Same position - add values
                int sum = ptr1->value + ptr2->value;
                if (sum != 0) {  // Only insert non-zero sums
                    insert_element(result, ptr1->row, ptr1->col, sum);
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
    }
    
    printf("Matrix addition completed\n");
    return result;
}

/*
 * Function to transpose sparse matrix
 */
struct SparseMatrix* transpose_sparse_matrix(struct SparseMatrix* matrix) {
    if (matrix == NULL) {
        printf("Error: Matrix is NULL!\n");
        return NULL;
    }
    
    printf("\nTransposing sparse matrix...\n");
    
    // Create transposed matrix (rows and cols swapped)
    struct SparseMatrix* transposed = create_sparse_matrix(matrix->cols, matrix->rows);
    
    struct MatrixNode* current = matrix->head;
    
    while (current != NULL) {
        // Insert with swapped row and column
        insert_element(transposed, current->col, current->row, current->value);
        current = current->next;
    }
    
    printf("Matrix transposition completed\n");
    return transposed;
}

/*
 * Function to count total memory saved
 */
void analyze_memory_savings(struct SparseMatrix* matrix) {
    printf("\n=== MEMORY ANALYSIS ===\n");
    
    int total_elements = matrix->rows * matrix->cols;
    int stored_elements = matrix->non_zeros;
    
    printf("Matrix size: %dx%d = %d total elements\n", 
           matrix->rows, matrix->cols, total_elements);
    printf("Non-zero elements: %d\n", stored_elements);
    printf("Zero elements: %d\n", total_elements - stored_elements);
    
    // Memory calculation (assuming int = 4 bytes)
    int full_matrix_memory = total_elements * sizeof(int);
    int sparse_matrix_memory = stored_elements * sizeof(struct MatrixNode);
    
    printf("\nMemory usage:\n");
    printf("Full matrix: %d bytes\n", full_matrix_memory);
    printf("Sparse matrix: %d bytes\n", sparse_matrix_memory);
    printf("Memory saved: %d bytes (%.1f%%)\n", 
           full_matrix_memory - sparse_matrix_memory,
           ((float)(full_matrix_memory - sparse_matrix_memory) / full_matrix_memory) * 100);
}

/*
 * Function to free sparse matrix memory
 */
void free_sparse_matrix(struct SparseMatrix* matrix) {
    if (matrix == NULL) return;
    
    printf("\nFreeing sparse matrix memory...\n");
    
    struct MatrixNode* current = matrix->head;
    int count = 0;
    
    while (current != NULL) {
        struct MatrixNode* temp = current;
        current = current->next;
        free(temp);
        count++;
    }
    
    free(matrix);
    printf("Freed %d nodes\n", count);
}

/*
 * Practical example: Image representation
 */
void practical_example_image_processing() {
    printf("\n=== PRACTICAL EXAMPLE: SPARSE IMAGE REPRESENTATION ===\n");
    
    printf("Representing a binary image (0=black, 1=white) using sparse matrix...\n");
    printf("Image: Simple smiley face pattern\n\n");
    
    // Create 8x8 image
    struct SparseMatrix* image = create_sparse_matrix(8, 8);
    
    // Smiley face pattern (only store white pixels = 1)
    // Eyes
    insert_element(image, 2, 2, 1);
    insert_element(image, 2, 5, 1);
    
    // Nose
    insert_element(image, 4, 3, 1);
    insert_element(image, 4, 4, 1);
    
    // Mouth
    insert_element(image, 6, 1, 1);
    insert_element(image, 6, 2, 1);
    insert_element(image, 6, 5, 1);
    insert_element(image, 6, 6, 1);
    insert_element(image, 7, 3, 1);
    insert_element(image, 7, 4, 1);
    
    printf("Sparse representation:\n");
    display_sparse_matrix(image);
    
    printf("\nActual image (0=black pixel, 1=white pixel):\n");
    display_full_matrix(image);
    
    analyze_memory_savings(image);
    
    free_sparse_matrix(image);
}

/*
 * Main demonstration function
 */
void demonstrate_sparse_matrix() {
    printf("=== SPARSE MATRIX REPRESENTATION DEMONSTRATION ===\n\n");
    
    // Create example sparse matrix
    struct SparseMatrix* matrix1 = create_sparse_matrix(4, 4);
    
    printf("\n1. Creating Sparse Matrix:\n");
    printf("Inserting non-zero elements...\n");
    
    insert_element(matrix1, 0, 2, 3);
    insert_element(matrix1, 1, 3, 4);
    insert_element(matrix1, 2, 0, 5);
    insert_element(matrix1, 3, 1, 6);
    
    display_sparse_matrix(matrix1);
    display_full_matrix(matrix1);
    
    // Create second matrix for addition
    printf("\n2. Creating Second Matrix for Addition:\n");
    struct SparseMatrix* matrix2 = create_sparse_matrix(4, 4);
    
    insert_element(matrix2, 0, 1, 2);
    insert_element(matrix2, 0, 2, 1);  // Will be added to matrix1's (0,2)
    insert_element(matrix2, 1, 1, 3);
    insert_element(matrix2, 2, 3, 7);
    
    display_sparse_matrix(matrix2);
    display_full_matrix(matrix2);
    
    // Matrix addition
    printf("\n3. Matrix Addition:\n");
    struct SparseMatrix* sum = add_sparse_matrices(matrix1, matrix2);
    display_sparse_matrix(sum);
    display_full_matrix(sum);
    
    // Matrix transpose
    printf("\n4. Matrix Transpose:\n");
    struct SparseMatrix* transposed = transpose_sparse_matrix(matrix1);
    printf("Original matrix:\n");
    display_full_matrix(matrix1);
    printf("Transposed matrix:\n");
    display_full_matrix(transposed);
    
    // Memory analysis
    analyze_memory_savings(matrix1);
    
    // Practical example
    practical_example_image_processing();
    
    // Cleanup
    printf("\n5. Memory Cleanup:\n");
    free_sparse_matrix(matrix1);
    free_sparse_matrix(matrix2);
    free_sparse_matrix(sum);
    free_sparse_matrix(transposed);
}

int main() {
    demonstrate_sparse_matrix();
    return 0;
}