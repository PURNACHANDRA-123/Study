# Unit-I: Introduction to Data Structures and Arrays

## What are Data Structures?

Think of data structures like different types of containers in your kitchen:
- **Arrays** are like egg cartons - items stored in a row, each in its own slot
- **Lists** are like a chain of paper clips - each connected to the next
- **Stacks** are like a pile of plates - you can only add/remove from the top
- **Queues** are like a line at a store - first person in line gets served first

## Classification of Data Structures

### 1. **Primitive Data Structures**
These are the basic building blocks:
- `int` (integers like 5, 10, -3)
- `float` (decimal numbers like 3.14, 2.5)
- `char` (single characters like 'A', 'x', '5')

### 2. **Non-Primitive Data Structures**

#### **Linear Data Structures** (items arranged in a line):
- **Arrays**: Fixed-size containers with indexed slots
- **Linked Lists**: Dynamic chains of connected elements
- **Stacks**: Last-In-First-Out (LIFO) structure
- **Queues**: First-In-First-Out (FIFO) structure

#### **Non-Linear Data Structures** (items arranged in hierarchy/network):
- **Trees**: Hierarchical structure like a family tree
- **Graphs**: Network of connected nodes like a map

## Topics in This Unit

### 1. Arrays
- **One-Dimensional Arrays**: Like a single row of lockers
- **Two-Dimensional Arrays**: Like a chess board with rows and columns
- **Multidimensional Arrays**: Like a Rubik's cube with multiple dimensions

### 2. Array Operations
- **Traversing**: Visiting each element one by one
- **Searching**: Finding if an element exists
- **Insertion**: Adding new elements
- **Deletion**: Removing elements
- **Merging**: Combining two arrays

### 3. Searching Algorithms
- **Linear Search**: Check each element one by one
- **Binary Search**: Smart search that divides and conquers

### 4. Sorting Algorithms
- **Selection Sort**: Find the smallest, put it first, repeat
- **Bubble Sort**: Compare neighbors and swap if needed

## Memory Representation

When you create an array, the computer allocates continuous memory slots:

```
Array: [10, 20, 30, 40, 50]
Memory: [1000][1004][1008][1012][1016]
        ^     ^     ^     ^     ^
       arr[0] arr[1] arr[2] arr[3] arr[4]
```

Each integer takes 4 bytes, so addresses are 4 bytes apart.

## Why Study Data Structures?

1. **Efficiency**: Choose the right tool for the job
2. **Organization**: Keep data organized and accessible
3. **Problem Solving**: Many programming problems have standard solutions
4. **Real-world Applications**: Used in databases, games, web browsers, etc.

## Files in This Unit

- `arrays/` - Array implementations and operations
- `searching/` - Linear and Binary search algorithms
- `sorting/` - Selection and Bubble sort implementations

Start with the arrays folder and work your way through each concept!