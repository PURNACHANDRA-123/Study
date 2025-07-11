# Makefile for Unit-II: Linked Lists
# ===================================

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET_DIR = bin
SOURCE_DIRS = singly_linked_list doubly_linked_list circular_lists

# Create bin directory if it doesn't exist
$(shell mkdir -p $(TARGET_DIR))

# Singly Linked List programs
SINGLY_SOURCES = singly_linked_list/singly_linked_list.c
SINGLY_TARGETS = $(TARGET_DIR)/singly_linked_list

# Doubly Linked List programs
DOUBLY_SOURCES = doubly_linked_list/doubly_linked_list.c
DOUBLY_TARGETS = $(TARGET_DIR)/doubly_linked_list

# Circular Lists and Applications
CIRCULAR_SOURCES = circular_lists/circular_linked_list.c circular_lists/sparse_matrix.c circular_lists/polynomial_representation.c
CIRCULAR_TARGETS = $(TARGET_DIR)/circular_linked_list $(TARGET_DIR)/sparse_matrix $(TARGET_DIR)/polynomial_representation

# All targets
ALL_TARGETS = $(SINGLY_TARGETS) $(DOUBLY_TARGETS) $(CIRCULAR_TARGETS)

# Default target
all: $(ALL_TARGETS)
	@echo "All Unit-II programs compiled successfully!"
	@echo "Executables are in the $(TARGET_DIR)/ directory"
	@echo ""
	@echo "Available programs:"
	@echo "  Singly Linked List:"
	@echo "    - $(TARGET_DIR)/singly_linked_list"
	@echo "  Doubly Linked List:"
	@echo "    - $(TARGET_DIR)/doubly_linked_list"
	@echo "  Circular Lists and Applications:"
	@echo "    - $(TARGET_DIR)/circular_linked_list"
	@echo "    - $(TARGET_DIR)/sparse_matrix"
	@echo "    - $(TARGET_DIR)/polynomial_representation"

# Singly Linked List target
$(TARGET_DIR)/singly_linked_list: singly_linked_list/singly_linked_list.c
	$(CC) $(CFLAGS) -o $@ $<

# Doubly Linked List target
$(TARGET_DIR)/doubly_linked_list: doubly_linked_list/doubly_linked_list.c
	$(CC) $(CFLAGS) -o $@ $<

# Circular Linked List target
$(TARGET_DIR)/circular_linked_list: circular_lists/circular_linked_list.c
	$(CC) $(CFLAGS) -o $@ $<

# Sparse Matrix target
$(TARGET_DIR)/sparse_matrix: circular_lists/sparse_matrix.c
	$(CC) $(CFLAGS) -o $@ $<

# Polynomial Representation target
$(TARGET_DIR)/polynomial_representation: circular_lists/polynomial_representation.c
	$(CC) $(CFLAGS) -o $@ $< -lm

# Individual category targets
singly: $(SINGLY_TARGETS)
	@echo "Singly linked list programs compiled!"

doubly: $(DOUBLY_TARGETS)
	@echo "Doubly linked list programs compiled!"

circular: $(CIRCULAR_TARGETS)
	@echo "Circular lists and applications compiled!"

# Run all programs
run-all: all
	@echo "Running all Unit-II demonstrations..."
	@echo ""
	@echo "=== SINGLY LINKED LIST DEMO ==="
	@$(TARGET_DIR)/singly_linked_list
	@echo ""
	@echo "=== DOUBLY LINKED LIST DEMO ==="
	@$(TARGET_DIR)/doubly_linked_list
	@echo ""
	@echo "=== CIRCULAR LINKED LIST DEMO ==="
	@$(TARGET_DIR)/circular_linked_list
	@echo ""
	@echo "=== SPARSE MATRIX DEMO ==="
	@$(TARGET_DIR)/sparse_matrix
	@echo ""
	@echo "=== POLYNOMIAL REPRESENTATION DEMO ==="
	@$(TARGET_DIR)/polynomial_representation

# Run specific category
run-singly: $(SINGLY_TARGETS)
	@echo "Running Singly Linked List demonstration..."
	@$(TARGET_DIR)/singly_linked_list

run-doubly: $(DOUBLY_TARGETS)
	@echo "Running Doubly Linked List demonstration..."
	@$(TARGET_DIR)/doubly_linked_list

run-circular: $(CIRCULAR_TARGETS)
	@echo "Running Circular Lists demonstrations..."
	@$(TARGET_DIR)/circular_linked_list
	@$(TARGET_DIR)/sparse_matrix
	@$(TARGET_DIR)/polynomial_representation

run-applications: $(TARGET_DIR)/sparse_matrix $(TARGET_DIR)/polynomial_representation
	@echo "Running Linked List Applications..."
	@$(TARGET_DIR)/sparse_matrix
	@$(TARGET_DIR)/polynomial_representation

# Clean compiled files
clean:
	rm -rf $(TARGET_DIR)
	@echo "Cleaned all compiled files"

# Help target
help:
	@echo "Unit-II Linked Lists Makefile"
	@echo "============================="
	@echo ""
	@echo "Available targets:"
	@echo "  all              - Compile all programs"
	@echo "  singly           - Compile only singly linked list"
	@echo "  doubly           - Compile only doubly linked list"
	@echo "  circular         - Compile circular lists and applications"
	@echo "  run-all          - Compile and run all programs"
	@echo "  run-singly       - Run singly linked list demo"
	@echo "  run-doubly       - Run doubly linked list demo"
	@echo "  run-circular     - Run circular lists demos"
	@echo "  run-applications - Run application demos"
	@echo "  clean            - Remove compiled files"
	@echo "  help             - Show this help message"
	@echo ""
	@echo "Example usage:"
	@echo "  make all                      # Compile everything"
	@echo "  make singly                   # Compile only singly linked list"
	@echo "  make run-applications         # Run application demos"
	@echo "  ./bin/polynomial_representation # Run specific program"

.PHONY: all singly doubly circular run-all run-singly run-doubly run-circular run-applications clean help