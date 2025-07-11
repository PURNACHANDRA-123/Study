# Unit-II: Linked Lists

## What are Linked Lists?

Think of a linked list like a treasure hunt where each clue tells you where to find the next clue:
- **Array**: Like houses on a street with numbered addresses (1, 2, 3, 4...)
- **Linked List**: Like a chain of paper clips, where each clip is connected to the next one

Unlike arrays where elements are stored in continuous memory locations, linked lists store elements (called **nodes**) anywhere in memory. Each node contains:
1. **Data**: The actual value you want to store
2. **Pointer**: The address of the next node

## Visual Representation

```
Singly Linked List:
[Data|Next] -> [Data|Next] -> [Data|Next] -> [Data|NULL]
     ^                                           ^
   Head                                        Tail
   
Double Linked List:
NULL<-[Prev|Data|Next]<->[Prev|Data|Next]<->[Prev|Data|Next]->NULL
           ^                                         ^
         Head                                      Tail

Circular Linked List:
[Data|Next] -> [Data|Next] -> [Data|Next]
     ^                             |
     |_____________________________|
```

## Types of Linked Lists

### 1. **Singly Linked List**
- Each node points to the next node
- Can only traverse in one direction (forward)
- Last node points to NULL

### 2. **Doubly Linked List**  
- Each node has two pointers: previous and next
- Can traverse in both directions (forward and backward)
- First node's previous pointer is NULL
- Last node's next pointer is NULL

### 3. **Circular Linked List**
- Last node points back to the first node
- No NULL pointers (except in empty list)
- Can be singly or doubly circular

### 4. **Double Circular Linked List**
- Combines doubly linked list with circular property
- Can traverse in both directions infinitely

## Advantages of Linked Lists

1. **Dynamic Size**: Can grow or shrink during runtime
2. **Memory Efficient**: Allocates memory as needed
3. **Easy Insertion/Deletion**: No need to shift elements
4. **No Memory Waste**: Only allocates what's needed

## Disadvantages of Linked Lists

1. **No Random Access**: Can't directly access arr[5] like arrays
2. **Extra Memory**: Each node needs storage for pointer(s)
3. **Not Cache Friendly**: Nodes scattered in memory
4. **Sequential Access**: Must traverse from head to reach any element

## Common Operations

### Basic Operations:
- **Traversing**: Visit each node from head to tail
- **Searching**: Find a node with specific data
- **Insertion**: Add new node at beginning, end, or middle
- **Deletion**: Remove node from beginning, end, or middle

### Advanced Operations:
- **Merging**: Combine two linked lists
- **Reversing**: Change the direction of links
- **Sorting**: Arrange nodes in order
- **Finding Middle**: Locate the center node

## Memory Representation

Unlike arrays, linked list nodes are scattered in memory:

```
Array in Memory:
[1000: 10][1004: 20][1008: 30][1012: 40]
 Continuous addresses

Linked List in Memory:
Node 1: [2000: 10|1500] -> Node 2: [1500: 20|3000] -> Node 3: [3000: 30|NULL]
Random addresses connected by pointers
```

## Applications of Linked Lists

1. **Sparse Matrix Representation**: Store only non-zero elements
2. **Polynomial Representation**: Store coefficients and exponents
3. **Implementation of Stacks and Queues**
4. **Undo functionality** in applications
5. **Music Playlists**: Next/Previous song navigation
6. **Browser History**: Back/Forward navigation

## When to Use Linked Lists vs Arrays

**Use Linked Lists when:**
- Frequent insertions and deletions
- Unknown or varying data size
- Memory is limited
- Don't need random access

**Use Arrays when:**
- Need random access to elements
- Memory access speed is critical
- Mostly reading data
- Fixed or predictable size

## Files in This Unit

- `singly_linked_list/` - Single linked list implementation
- `doubly_linked_list/` - Double linked list implementation  
- `circular_lists/` - Circular and double circular implementations
- Applications: Sparse matrix and polynomial representations

Start with singly linked list to understand the basic concepts, then progress to more complex variations!