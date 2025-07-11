# Makefile for Unit-I: Arrays, Searching, and Sorting
# ====================================================

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET_DIR = bin
SOURCE_DIRS = arrays searching sorting

# Create bin directory if it doesn't exist
$(shell mkdir -p $(TARGET_DIR))

# Array programs
ARRAY_SOURCES = arrays/one_dimensional_array.c arrays/two_dimensional_array.c arrays/multidimensional_array.c
ARRAY_TARGETS = $(TARGET_DIR)/one_dimensional_array $(TARGET_DIR)/two_dimensional_array $(TARGET_DIR)/multidimensional_array

# Searching programs
SEARCH_SOURCES = searching/linear_search.c searching/binary_search.c
SEARCH_TARGETS = $(TARGET_DIR)/linear_search $(TARGET_DIR)/binary_search

# Sorting programs
SORT_SOURCES = sorting/selection_sort.c sorting/bubble_sort.c
SORT_TARGETS = $(TARGET_DIR)/selection_sort $(TARGET_DIR)/bubble_sort

# All targets
ALL_TARGETS = $(ARRAY_TARGETS) $(SEARCH_TARGETS) $(SORT_TARGETS)

# Default target
all: $(ALL_TARGETS)
	@echo "All Unit-I programs compiled successfully!"
	@echo "Executables are in the $(TARGET_DIR)/ directory"
	@echo ""
	@echo "Available programs:"
	@echo "  Arrays:"
	@echo "    - $(TARGET_DIR)/one_dimensional_array"
	@echo "    - $(TARGET_DIR)/two_dimensional_array" 
	@echo "    - $(TARGET_DIR)/multidimensional_array"
	@echo "  Searching:"
	@echo "    - $(TARGET_DIR)/linear_search"
	@echo "    - $(TARGET_DIR)/binary_search"
	@echo "  Sorting:"
	@echo "    - $(TARGET_DIR)/selection_sort"
	@echo "    - $(TARGET_DIR)/bubble_sort"

# Array targets
$(TARGET_DIR)/one_dimensional_array: arrays/one_dimensional_array.c
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET_DIR)/two_dimensional_array: arrays/two_dimensional_array.c
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET_DIR)/multidimensional_array: arrays/multidimensional_array.c
	$(CC) $(CFLAGS) -o $@ $<

# Searching targets
$(TARGET_DIR)/linear_search: searching/linear_search.c
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET_DIR)/binary_search: searching/binary_search.c
	$(CC) $(CFLAGS) -o $@ $< -lm

# Sorting targets
$(TARGET_DIR)/selection_sort: sorting/selection_sort.c
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET_DIR)/bubble_sort: sorting/bubble_sort.c
	$(CC) $(CFLAGS) -o $@ $<

# Individual category targets
arrays: $(ARRAY_TARGETS)
	@echo "Array programs compiled!"

searching: $(SEARCH_TARGETS)
	@echo "Searching programs compiled!"

sorting: $(SORT_TARGETS)
	@echo "Sorting programs compiled!"

# Run all programs
run-all: all
	@echo "Running all Unit-I demonstrations..."
	@echo ""
	@echo "=== 1D ARRAY DEMO ==="
	@$(TARGET_DIR)/one_dimensional_array
	@echo ""
	@echo "=== 2D ARRAY DEMO ==="
	@$(TARGET_DIR)/two_dimensional_array
	@echo ""
	@echo "=== MULTIDIMENSIONAL ARRAY DEMO ==="
	@$(TARGET_DIR)/multidimensional_array
	@echo ""
	@echo "=== LINEAR SEARCH DEMO ==="
	@$(TARGET_DIR)/linear_search
	@echo ""
	@echo "=== BINARY SEARCH DEMO ==="
	@$(TARGET_DIR)/binary_search
	@echo ""
	@echo "=== SELECTION SORT DEMO ==="
	@$(TARGET_DIR)/selection_sort
	@echo ""
	@echo "=== BUBBLE SORT DEMO ==="
	@$(TARGET_DIR)/bubble_sort

# Run specific category
run-arrays: $(ARRAY_TARGETS)
	@echo "Running Array demonstrations..."
	@$(TARGET_DIR)/one_dimensional_array
	@$(TARGET_DIR)/two_dimensional_array
	@$(TARGET_DIR)/multidimensional_array

run-searching: $(SEARCH_TARGETS)
	@echo "Running Searching demonstrations..."
	@$(TARGET_DIR)/linear_search
	@$(TARGET_DIR)/binary_search

run-sorting: $(SORT_TARGETS)
	@echo "Running Sorting demonstrations..."
	@$(TARGET_DIR)/selection_sort
	@$(TARGET_DIR)/bubble_sort

# Clean compiled files
clean:
	rm -rf $(TARGET_DIR)
	@echo "Cleaned all compiled files"

# Help target
help:
	@echo "Unit-I Data Structures Makefile"
	@echo "==============================="
	@echo ""
	@echo "Available targets:"
	@echo "  all          - Compile all programs"
	@echo "  arrays       - Compile only array programs"
	@echo "  searching    - Compile only searching programs"
	@echo "  sorting      - Compile only sorting programs"
	@echo "  run-all      - Compile and run all programs"
	@echo "  run-arrays   - Run array demonstrations"
	@echo "  run-searching- Run searching demonstrations"
	@echo "  run-sorting  - Run sorting demonstrations"
	@echo "  clean        - Remove compiled files"
	@echo "  help         - Show this help message"
	@echo ""
	@echo "Example usage:"
	@echo "  make all                    # Compile everything"
	@echo "  make arrays                 # Compile only arrays"
	@echo "  make run-sorting           # Run sorting demos"
	@echo "  ./bin/linear_search        # Run specific program"

.PHONY: all arrays searching sorting run-all run-arrays run-searching run-sorting clean help