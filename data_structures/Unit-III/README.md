# Unit-III: Stacks and Queues

## What are Stacks and Queues?

### Stack (LIFO - Last In, First Out)
Think of a stack like a pile of plates in a cafeteria:
- You can only add a new plate on top (PUSH operation)
- You can only remove the top plate (POP operation)
- The last plate you put becomes the first one you take

```
Visual representation:
   TOP
   ↓
|     | ← PUSH/POP happens here
| [3] |
| [2] |
| [1] |
+-----+
```

### Queue (FIFO - First In, First Out)
Think of a queue like a line at a movie theater:
- People join at the back (ENQUEUE operation)
- People leave from the front (DEQUEUE operation)
- First person in line is the first to buy tickets

```
Visual representation:
FRONT           REAR
  ↓              ↓
[1] → [2] → [3] → 
  ↑              ↑
DEQUEUE      ENQUEUE
```

## Stack Operations

### Basic Operations:
1. **PUSH**: Add element to top of stack
2. **POP**: Remove and return top element
3. **PEEK/TOP**: View top element without removing
4. **IS_EMPTY**: Check if stack is empty
5. **IS_FULL**: Check if stack is full (for array implementation)
6. **SIZE**: Get number of elements

### Stack States:
- **Empty Stack**: No elements, TOP = -1
- **Full Stack**: All positions filled (array implementation)
- **Stack Underflow**: Trying to POP from empty stack
- **Stack Overflow**: Trying to PUSH to full stack

## Queue Operations

### Basic Operations:
1. **ENQUEUE**: Add element to rear of queue
2. **DEQUEUE**: Remove and return front element
3. **FRONT**: View front element without removing
4. **REAR**: View rear element without removing
5. **IS_EMPTY**: Check if queue is empty
6. **IS_FULL**: Check if queue is full
7. **SIZE**: Get number of elements

### Queue States:
- **Empty Queue**: No elements, FRONT = REAR = -1
- **Full Queue**: All positions filled
- **Queue Underflow**: Trying to DEQUEUE from empty queue
- **Queue Overflow**: Trying to ENQUEUE to full queue

## Implementation Methods

### Stack Implementations:
1. **Array-based Stack**
   - Fixed size
   - Simple and fast
   - Memory efficient
   - Can overflow

2. **Linked List-based Stack**
   - Dynamic size
   - No overflow (until system memory exhausted)
   - Extra memory for pointers
   - More complex

### Queue Implementations:
1. **Array-based Queue**
   - Simple linear queue
   - Circular queue (efficient space usage)
   - Fixed size

2. **Linked List-based Queue**
   - Dynamic size
   - No size limitations
   - Extra memory overhead

## Types of Queues

### 1. **Simple Queue**
Basic FIFO queue with front and rear pointers

### 2. **Circular Queue**
Rear wraps around to beginning when reaching end
```
[0][1][2][3][4]
 ↑           ↑
front      rear
```

### 3. **Double-ended Queue (Deque)**
Insert and delete from both ends
```
 ← [1][2][3][4] →
   ↑           ↑
 front       rear
```

### 4. **Priority Queue**
Elements have priorities; highest priority served first
```
Priority: High → Medium → Low
Queue:   [9] → [5] → [2]
```

## Applications of Stacks

### 1. **Expression Evaluation**
- Convert infix to postfix notation
- Evaluate postfix expressions
- Check balanced parentheses

### 2. **Function Calls**
- Function call stack
- Recursion implementation
- Local variable storage

### 3. **Backtracking**
- Undo operations
- Browser back button
- Maze solving
- Game state management

### 4. **Parsing**
- Compiler syntax analysis
- HTML/XML tag matching
- Mathematical expression parsing

## Applications of Queues

### 1. **Process Scheduling**
- Operating system task scheduling
- Print job management
- CPU process scheduling

### 2. **Data Transfer**
- Network packet handling
- Buffer for data streams
- Keyboard buffer

### 3. **Breadth-First Search**
- Graph traversal
- Tree level-order traversal
- Shortest path algorithms

### 4. **Real-world Systems**
- Call center phone queues
- Printer queues
- Web server request handling

## Recursion and Stacks

### What is Recursion?
A function calling itself with a smaller problem size until reaching a base case.

### How Stacks Enable Recursion:
1. Each function call creates a new stack frame
2. Local variables and parameters stored in frame
3. Return address saved for coming back
4. Base case stops the recursion
5. Stack frames removed as functions return

### Classic Recursive Problems:
1. **Factorial**: n! = n × (n-1)!
2. **Fibonacci**: F(n) = F(n-1) + F(n-2)
3. **Tower of Hanoi**: Move disks between pegs

## Memory Representation

### Array-based Stack:
```
Stack Array: [10][20][30][ ][ ]
Index:        0   1   2   3   4
TOP pointer: 2
```

### Linked List Stack:
```
TOP → [30|•] → [20|•] → [10|NULL]
```

### Array-based Queue:
```
Queue Array: [ ][10][20][30][ ]
Index:        0   1   2   3   4
FRONT: 1, REAR: 3
```

## Files in This Unit

- `stacks/` - Array and linked list stack implementations
- `queues/` - Various queue implementations
- `recursion/` - Recursive algorithms and examples

## When to Use Stacks vs Queues

**Use Stacks when:**
- Need LIFO behavior
- Implementing recursion
- Undo/redo functionality
- Expression evaluation
- Backtracking algorithms

**Use Queues when:**
- Need FIFO behavior
- Process scheduling
- Breadth-first traversal
- Buffer management
- Print job scheduling

Start with basic stack and queue implementations, then explore their applications!