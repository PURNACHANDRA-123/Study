/*
 * POLYNOMIAL REPRESENTATION USING LINKED LISTS
 * =============================================
 * 
 * What is Polynomial Representation?
 * ----------------------------------
 * A polynomial is a mathematical expression like: 5x³ + 3x² - 2x + 7
 * 
 * Each term has:
 * - Coefficient: The number multiplying the variable (5, 3, -2, 7)
 * - Exponent: The power of the variable (3, 2, 1, 0)
 * 
 * Traditional representation problems:
 * - Arrays waste space for missing terms (what if no x⁵ term?)
 * - Fixed size limits polynomial degree
 * - Difficult to handle sparse polynomials
 * 
 * Linked List Advantages:
 * - Store only non-zero terms
 * - Dynamic size (no degree limit)
 * - Easy insertion/deletion of terms
 * - Memory efficient
 * 
 * Node Structure:
 * +------------+----------+------+
 * | Coefficient| Exponent | Next |
 * +------------+----------+------+
 * 
 * Example: 5x³ + 3x² - 2x + 7
 * [5,3] -> [3,2] -> [-2,1] -> [7,0] -> NULL
 * 
 * Applications:
 * - Computer algebra systems
 * - Scientific computing
 * - Graphics and animation (Bezier curves)
 * - Signal processing
 * - Mathematical software
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Node structure for polynomial term
 */
struct PolyNode {
    float coefficient;  // Coefficient of the term
    int exponent;      // Power/exponent of the term
    struct PolyNode* next;  // Pointer to next term
};

/*
 * Structure to represent a polynomial
 */
struct Polynomial {
    struct PolyNode* head;  // Head of the linked list
    int degree;             // Highest exponent in polynomial
};

/*
 * Function to create a new polynomial node
 */
struct PolyNode* create_poly_node(float coefficient, int exponent) {
    struct PolyNode* new_node = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    
    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    
    new_node->coefficient = coefficient;
    new_node->exponent = exponent;
    new_node->next = NULL;
    
    return new_node;
}

/*
 * Function to create a new polynomial
 */
struct Polynomial* create_polynomial() {
    struct Polynomial* poly = (struct Polynomial*)malloc(sizeof(struct Polynomial));
    
    if (poly == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    
    poly->head = NULL;
    poly->degree = -1;  // -1 indicates empty polynomial
    
    return poly;
}

/*
 * Function to insert a term in descending order of exponents
 */
void insert_term(struct Polynomial* poly, float coefficient, int exponent) {
    // Don't insert zero coefficients (except for zero polynomial)
    if (coefficient == 0.0) {
        printf("Skipping term with zero coefficient: %.2fx^%d\n", coefficient, exponent);
        return;
    }
    
    struct PolyNode* new_node = create_poly_node(coefficient, exponent);
    if (new_node == NULL) return;
    
    // Update degree if necessary
    if (exponent > poly->degree) {
        poly->degree = exponent;
    }
    
    // If polynomial is empty or new term has highest exponent
    if (poly->head == NULL || poly->head->exponent < exponent) {
        new_node->next = poly->head;
        poly->head = new_node;
        printf("Inserted %.2fx^%d at beginning\n", coefficient, exponent);
        return;
    }
    
    // Find correct position to maintain descending order
    struct PolyNode* current = poly->head;
    
    // Check if we need to combine with first term
    if (current->exponent == exponent) {
        current->coefficient += coefficient;
        printf("Combined with existing term: %.2fx^%d\n", current->coefficient, exponent);
        free(new_node);
        return;
    }
    
    // Traverse to find insertion point
    while (current->next != NULL && current->next->exponent > exponent) {
        current = current->next;
    }
    
    // Check if we need to combine with existing term
    if (current->next != NULL && current->next->exponent == exponent) {
        current->next->coefficient += coefficient;
        printf("Combined with existing term: %.2fx^%d\n", current->next->coefficient, exponent);
        free(new_node);
        return;
    }
    
    // Insert new term
    new_node->next = current->next;
    current->next = new_node;
    printf("Inserted %.2fx^%d in position\n", coefficient, exponent);
}

/*
 * Function to display polynomial in mathematical form
 */
void display_polynomial(struct Polynomial* poly) {
    if (poly == NULL || poly->head == NULL) {
        printf("0\n");
        return;
    }
    
    printf("Polynomial: ");
    struct PolyNode* current = poly->head;
    int first_term = 1;
    
    while (current != NULL) {
        // Handle sign
        if (first_term) {
            if (current->coefficient < 0) {
                printf("-");
            }
            first_term = 0;
        } else {
            if (current->coefficient >= 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        }
        
        // Handle coefficient
        float coeff = fabs(current->coefficient);
        if (current->exponent == 0) {
            // Constant term
            printf("%.2f", coeff);
        } else if (coeff == 1.0) {
            // Coefficient is 1, don't show it
            if (current->exponent == 1) {
                printf("x");
            } else {
                printf("x^%d", current->exponent);
            }
        } else {
            // Show coefficient
            if (current->exponent == 1) {
                printf("%.2fx", coeff);
            } else {
                printf("%.2fx^%d", coeff, current->exponent);
            }
        }
        
        current = current->next;
    }
    printf("\n");
}

/*
 * Function to display polynomial in tabular form
 */
void display_polynomial_table(struct Polynomial* poly) {
    if (poly == NULL || poly->head == NULL) {
        printf("Polynomial is empty!\n");
        return;
    }
    
    printf("\nPolynomial Terms:\n");
    printf("Coefficient | Exponent | Term\n");
    printf("-----------|----------|----------\n");
    
    struct PolyNode* current = poly->head;
    while (current != NULL) {
        printf("%-10.2f | %-8d | ", current->coefficient, current->exponent);
        
        if (current->exponent == 0) {
            printf("%.2f\n", current->coefficient);
        } else if (current->exponent == 1) {
            printf("%.2fx\n", current->coefficient);
        } else {
            printf("%.2fx^%d\n", current->coefficient, current->exponent);
        }
        
        current = current->next;
    }
    printf("Degree: %d\n", poly->degree);
}

/*
 * Function to evaluate polynomial at given value of x
 */
float evaluate_polynomial(struct Polynomial* poly, float x) {
    if (poly == NULL || poly->head == NULL) {
        return 0.0;
    }
    
    printf("\nEvaluating polynomial at x = %.2f\n", x);
    
    float result = 0.0;
    struct PolyNode* current = poly->head;
    
    while (current != NULL) {
        float term_value = current->coefficient * pow(x, current->exponent);
        printf("Term %.2fx^%d = %.2f * %.2f^%d = %.2f\n", 
               current->coefficient, current->exponent, 
               current->coefficient, x, current->exponent, term_value);
        result += term_value;
        current = current->next;
    }
    
    printf("Total result: %.2f\n", result);
    return result;
}

/*
 * Function to add two polynomials
 */
struct Polynomial* add_polynomials(struct Polynomial* poly1, struct Polynomial* poly2) {
    if (poly1 == NULL || poly2 == NULL) {
        printf("Error: One or both polynomials are NULL!\n");
        return NULL;
    }
    
    printf("\nAdding two polynomials...\n");
    
    struct Polynomial* result = create_polynomial();
    struct PolyNode* ptr1 = poly1->head;
    struct PolyNode* ptr2 = poly2->head;
    
    while (ptr1 != NULL || ptr2 != NULL) {
        if (ptr1 == NULL) {
            // Only terms from poly2 remain
            insert_term(result, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
        else if (ptr2 == NULL) {
            // Only terms from poly1 remain
            insert_term(result, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exponent > ptr2->exponent) {
            // ptr1 has higher exponent
            insert_term(result, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exponent < ptr2->exponent) {
            // ptr2 has higher exponent
            insert_term(result, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
        else {
            // Same exponent - add coefficients
            float sum = ptr1->coefficient + ptr2->coefficient;
            if (sum != 0.0) {  // Only insert non-zero terms
                insert_term(result, sum, ptr1->exponent);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    
    printf("Polynomial addition completed\n");
    return result;
}

/*
 * Function to multiply two polynomials
 */
struct Polynomial* multiply_polynomials(struct Polynomial* poly1, struct Polynomial* poly2) {
    if (poly1 == NULL || poly2 == NULL) {
        printf("Error: One or both polynomials are NULL!\n");
        return NULL;
    }
    
    printf("\nMultiplying two polynomials...\n");
    
    struct Polynomial* result = create_polynomial();
    struct PolyNode* ptr1 = poly1->head;
    
    while (ptr1 != NULL) {
        struct PolyNode* ptr2 = poly2->head;
        
        while (ptr2 != NULL) {
            float coeff = ptr1->coefficient * ptr2->coefficient;
            int exp = ptr1->exponent + ptr2->exponent;
            
            printf("Multiplying %.2fx^%d * %.2fx^%d = %.2fx^%d\n",
                   ptr1->coefficient, ptr1->exponent,
                   ptr2->coefficient, ptr2->exponent,
                   coeff, exp);
            
            insert_term(result, coeff, exp);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    
    printf("Polynomial multiplication completed\n");
    return result;
}

/*
 * Function to find derivative of polynomial
 */
struct Polynomial* derivative_polynomial(struct Polynomial* poly) {
    if (poly == NULL || poly->head == NULL) {
        printf("Error: Polynomial is NULL or empty!\n");
        return NULL;
    }
    
    printf("\nFinding derivative of polynomial...\n");
    
    struct Polynomial* derivative = create_polynomial();
    struct PolyNode* current = poly->head;
    
    while (current != NULL) {
        if (current->exponent > 0) {
            float new_coeff = current->coefficient * current->exponent;
            int new_exp = current->exponent - 1;
            
            printf("d/dx(%.2fx^%d) = %.2fx^%d\n",
                   current->coefficient, current->exponent,
                   new_coeff, new_exp);
            
            insert_term(derivative, new_coeff, new_exp);
        } else {
            printf("d/dx(%.2f) = 0 (constant term disappears)\n", current->coefficient);
        }
        
        current = current->next;
    }
    
    printf("Derivative calculation completed\n");
    return derivative;
}

/*
 * Function to free polynomial memory
 */
void free_polynomial(struct Polynomial* poly) {
    if (poly == NULL) return;
    
    printf("Freeing polynomial memory...\n");
    
    struct PolyNode* current = poly->head;
    int count = 0;
    
    while (current != NULL) {
        struct PolyNode* temp = current;
        current = current->next;
        free(temp);
        count++;
    }
    
    free(poly);
    printf("Freed %d terms\n", count);
}

/*
 * Practical example: Quadratic equation solver
 */
void practical_example_quadratic_solver() {
    printf("\n=== PRACTICAL EXAMPLE: QUADRATIC EQUATION SOLVER ===\n");
    
    printf("Creating quadratic polynomial: 2x² - 5x + 3\n");
    
    struct Polynomial* quadratic = create_polynomial();
    insert_term(quadratic, 2.0, 2);   // 2x²
    insert_term(quadratic, -5.0, 1);  // -5x
    insert_term(quadratic, 3.0, 0);   // +3
    
    display_polynomial(quadratic);
    
    // Evaluate at different points
    printf("\nEvaluating quadratic at different points:\n");
    float x_values[] = {0, 1, 1.5, 2, 3};
    
    for (int i = 0; i < 5; i++) {
        float result = evaluate_polynomial(quadratic, x_values[i]);
        printf("f(%.1f) = %.2f\n", x_values[i], result);
    }
    
    // Find derivative
    printf("\nFinding derivative (useful for finding critical points):\n");
    struct Polynomial* derivative = derivative_polynomial(quadratic);
    printf("Original: ");
    display_polynomial(quadratic);
    printf("Derivative: ");
    display_polynomial(derivative);
    
    free_polynomial(quadratic);
    free_polynomial(derivative);
}

/*
 * Main demonstration function
 */
void demonstrate_polynomial_representation() {
    printf("=== POLYNOMIAL REPRESENTATION DEMONSTRATION ===\n\n");
    
    // Create first polynomial: 3x³ + 2x² - 5x + 1
    printf("1. Creating First Polynomial: 3x³ + 2x² - 5x + 1\n");
    struct Polynomial* poly1 = create_polynomial();
    
    insert_term(poly1, 3.0, 3);
    insert_term(poly1, 2.0, 2);
    insert_term(poly1, -5.0, 1);
    insert_term(poly1, 1.0, 0);
    
    display_polynomial(poly1);
    display_polynomial_table(poly1);
    
    // Create second polynomial: 2x² + 4x - 3
    printf("\n2. Creating Second Polynomial: 2x² + 4x - 3\n");
    struct Polynomial* poly2 = create_polynomial();
    
    insert_term(poly2, 2.0, 2);
    insert_term(poly2, 4.0, 1);
    insert_term(poly2, -3.0, 0);
    
    display_polynomial(poly2);
    display_polynomial_table(poly2);
    
    // Polynomial evaluation
    printf("\n3. Polynomial Evaluation:\n");
    evaluate_polynomial(poly1, 2.0);
    evaluate_polynomial(poly2, 2.0);
    
    // Polynomial addition
    printf("\n4. Polynomial Addition:\n");
    printf("First polynomial: ");
    display_polynomial(poly1);
    printf("Second polynomial: ");
    display_polynomial(poly2);
    
    struct Polynomial* sum = add_polynomials(poly1, poly2);
    printf("Sum: ");
    display_polynomial(sum);
    
    // Polynomial multiplication
    printf("\n5. Polynomial Multiplication:\n");
    struct Polynomial* product = multiply_polynomials(poly2, create_polynomial());
    // Create simple polynomial for multiplication: x + 1
    struct Polynomial* simple = create_polynomial();
    insert_term(simple, 1.0, 1);
    insert_term(simple, 1.0, 0);
    
    printf("Multiplying ");
    display_polynomial(poly2);
    printf("with (x + 1):\n");
    product = multiply_polynomials(poly2, simple);
    printf("Product: ");
    display_polynomial(product);
    
    // Derivative
    printf("\n6. Polynomial Derivative:\n");
    struct Polynomial* derivative = derivative_polynomial(poly1);
    printf("Original: ");
    display_polynomial(poly1);
    printf("Derivative: ");
    display_polynomial(derivative);
    
    // Practical example
    practical_example_quadratic_solver();
    
    // Cleanup
    printf("\n7. Memory Cleanup:\n");
    free_polynomial(poly1);
    free_polynomial(poly2);
    free_polynomial(sum);
    free_polynomial(simple);
    free_polynomial(product);
    free_polynomial(derivative);
}

int main() {
    demonstrate_polynomial_representation();
    return 0;
}