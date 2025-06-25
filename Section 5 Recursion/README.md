## 📘 All About **Recursion** in Data Structures and Algorithms (DSA)



### 🔁 What is Recursion?

**Recursion** is a programming technique where a function **calls itself** to solve smaller instances of a problem.

---

### 🧠 Key Concepts

1. **Base Case**
   The condition under which the recursion stops.

2. **Recursive Case**
   The part of the function where it calls itself with a smaller or simpler input.

3. **Call Stack**
   Each recursive call adds a new frame to the call stack. Too many calls without a base case can cause a **stack overflow**.

---

### 🧩 Why Use Recursion?

* Elegant solution for **divide and conquer** problems
* Simplifies code for problems like:

  * Tree traversals
  * Graph algorithms (DFS)
  * Combinatorics (permutations, subsets)
  * Backtracking (N-Queens, Sudoku)
  * Dynamic Programming (memoized solutions)

---

### 🛠️ General Structure

```c
void recursiveFunction(parameters) {
    if (base_condition) {
        return; // Base case
    } else {
        // Recursive call
        recursiveFunction(smaller_problem);
    }
}
```

---

### 🧮 Examples

#### 1. Factorial (n!)

```c
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
```

#### 2. Fibonacci Numbers

```c
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
```

#### 3. Sum of Digits

```c
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return n % 10 + sumOfDigits(n / 10);
}
```

---

### 🧠 Types of Recursion

| Type                   | Example                    |
| ---------------------- | -------------------------- |
| **Tail Recursion**     | Call is the last operation |
| **Head Recursion**     | Recursive call before ops  |
| **Tree Recursion**     | Multiple recursive calls   |
| **Indirect Recursion** | A() → B() → A()            |
| **Nested Recursion**   | A(A(n-1))                  |

---

### 📊 Time and Space Complexity

* **Time Complexity** depends on the number of recursive calls.
* **Space Complexity** includes stack space due to function calls.

#### Example:

Factorial:

* Time: O(n)
* Space: O(n)

Fibonacci (naive):

* Time: O(2ⁿ)
* Space: O(n)

---

### ✅ Pros

* Clean and elegant code
* Suits naturally recursive problems (like trees)

### ❌ Cons

* Overhead of function calls
* Can lead to **stack overflow**
* May be **less efficient** than iteration

---

### 🧠 Tips

* Always write a base case.
* Consider **memoization** to optimize overlapping subproblems.
* Convert to **iteration** when stack depth is a concern.

---

### 🔄 Recursion vs Iteration

| Feature     | Recursion                 | Iteration        |
| ----------- | ------------------------- | ---------------- |
| Memory      | More (call stack)         | Less             |
| Performance | May be slower             | Usually faster   |
| Simplicity  | Simpler for trees, graphs | Simple for loops |

---

### 📚 Practice Problems

1. Reverse a string
2. Check for palindrome
3. Tower of Hanoi
4. Merge Sort / Quick Sort
5. DFS in Graph
6. Find all subsets/permutations

---
### 🧠 Stack Calling in Recursion — Explained with Example
  
---

### 📚 Concept: **Call Stack in Recursion**

When a function calls itself recursively, **each call is pushed onto the call stack** (a memory structure that stores function calls).

Every recursive call:

1. Pauses the current function,
2. Saves its state (local variables, return address) on the **call stack**,
3. Begins a new function call,
4. When a base case is hit, the calls **unwind** (pop off the stack one by one).

---

### 🔄 Example: Factorial of a Number

Let's find `factorial(4)` using recursion.

```c
int factorial(int n) {
    if (n == 0) return 1;         // Base case
    return n * factorial(n - 1);  // Recursive case
}
```

---

### 📊 Step-by-Step Call Stack

| Call Stack (Top = Latest Call) | Description                |
| ------------------------------ | -------------------------- |
| `factorial(0)`                 | Base case returns 1        |
| `factorial(1)`                 | 1 \* 1 = 1                 |
| `factorial(2)`                 | 2 \* 1 = 2                 |
| `factorial(3)`                 | 3 \* 2 = 6                 |
| `factorial(4)`                 | 4 \* 6 = 24 (final result) |

---

### 🪜 Stack Behavior Visually

#### 🔼 Function Calls Go **Up** (Pushed):

```
factorial(4)
  -> factorial(3)
      -> factorial(2)
          -> factorial(1)
              -> factorial(0) // returns 1 (base case)
```

#### 🔽 Return Values Come **Down** (Popped):

```
factorial(1) returns 1 * 1 = 1
factorial(2) returns 2 * 1 = 2
factorial(3) returns 3 * 2 = 6
factorial(4) returns 4 * 6 = 24
```

---

### 🧠 Memory Insight:

Each function call uses:

* Stack memory for local variables
* Space to remember "where to return"

If the recursive depth is too large → **Stack Overflow**.

---

### 🧪 Try It Yourself: Simple Recursion Tracer

```c
#include <stdio.h>

int factorial(int n) {
    printf("Calling factorial(%d)\n", n);
    if (n == 0) {
        printf("Returning 1\n");
        return 1;
    }
    int result = n * factorial(n - 1);
    printf("Returning %d for factorial(%d)\n", result, n);
    return result;
}

int main() {
    printf("Factorial: %d\n", factorial(4));
    return 0;
}
```

---

Recursion is a fundamental concept in computer science where a function calls itself to solve smaller instances of a problem. There are several **types of recursion**, classified based on **how** and **when** the recursive calls are made. Here's a detailed overview:

---

### 🔁 **1. Direct Recursion**

The function calls itself directly.

**Example (C/C++/Java-like):**

```c
void func() {
    // some code
    func();  // direct recursive call
}
```

---

### 🔁 **2. Indirect Recursion**

A function calls another function, which eventually calls the first one back.

**Example:**

```c
void A() {
    // some code
    B();  // calls B
}

void B() {
    // some code
    A();  // calls A again
}
```

---

### 🔁 **3. Tail Recursion**

The recursive call is the **last operation** in the function.

**Optimized by compilers** to reduce stack usage.

**Example:**

```c
void tailRec(int n) {
    if (n == 0) return;
    tailRec(n - 1);  // last operation
}
```

---

### 🔁 **4. Head Recursion**

The recursive call is the **first operation**, and processing happens after the call returns.

**Example:**

```c
void headRec(int n) {
    if (n == 0) return;
    headRec(n - 1);  // first operation
    printf("%d ", n);
}
```

---

### 🔁 **5. Tree Recursion**

The function makes **multiple recursive calls** in each invocation, forming a tree-like structure.

**Example:**

```c
void treeRec(int n) {
    if (n == 0) return;
    treeRec(n - 1);
    treeRec(n - 1);
}
```

---

### 🔁 **6. Nested Recursion**

The function’s recursive call is **inside the parameters** of another recursive call.

**Example:**

```c
int nestedRec(int n) {
    if (n > 100)
        return n - 10;
    return nestedRec(nestedRec(n + 11));
}
```

---

### 🔁 **7. Mutual Recursion**

Two or more functions call each other in a circular manner (a form of indirect recursion).

**Example:**

```c
void even(int n);
void odd(int n);

void even(int n) {
    if (n == 0) printf("Even\n");
    else odd(n - 1);
}

void odd(int n) {
    if (n == 0) printf("Odd\n");
    else even(n - 1);
}
```

---
