## 1. Problem Statement

The Tower of Hanoi is a mathematical puzzle consisting of:

* **Three pegs** (often labeled A, B, C).
* **N disks** of distinct sizes, initially all stacked on peg A in order of decreasing size (largest at the bottom, smallest at the top).

**Goal:** Move the entire stack from peg A to peg C, obeying:

1. **One disk at a time** may be moved.
2. You can only take the **top** disk on any peg.
3. A disk may never be placed **on top** of a smaller disk.

---

## 2. Why It’s Interesting

* Illustrates **recursion** beautifully.
* Minimum moves required is exactly $2^N - 1$.
* Appears in teaching algorithms, mathematical induction, and in analyses of exponential‐time processes.

---

## 3. Illustrative Diagram (N = 3)

Let’s label pegs **A → B → C** from left to right. Disks numbered **1** (smallest) to **3** (largest).

```
Initial state (all on A):
    |       |       |
   ===      |       |       ← Disk 1
  =====     |       |       ← Disk 2
 =======    |       |       ← Disk 3
———A——— ———B——— ———C———
```

### Step-by-Step for 3 Disks

| Move # | From → To | State on A, B, C                         |
| -----: | :-------- | :--------------------------------------- |
|      1 | A → C     | A: \[3,2], B: \[], C: \[1]               |
|      2 | A → B     | A: \[3],   B: \[2], C: \[1]              |
|      3 | C → B     | A: \[3],   B: \[2,1], C: \[]             |
|      4 | A → C     | A: \[],    B: \[2,1], C: \[3]            |
|      5 | B → A     | A: \[1],   B: \[2],   C: \[3]            |
|      6 | B → C     | A: \[1],   B: \[],   C: \[3,2]           |
|      7 | A → C     | A: \[],    B: \[],   C: \[3,2,1] ← done! |

Visually, after move 4:

```
    |      |       |
   ===     |      ===     ← Disk 1 on B
  =====   ===      |      ← Disk 2 on B
 =======   |      ===     ← Disk 3 on C
———A——— ———B——— ———C———
```

---

## 4. Recursive Algorithm

The recursive insight:

> To move $N$ disks from **source** to **target** using **auxiliary** peg:
>
> 1. Move $N−1$ disks from **source** to **auxiliary**.
> 2. Move the remaining largest disk from **source** to **target**.
> 3. Move the $N−1$ disks from **auxiliary** to **target**.

### Pseudocode

```
procedure Hanoi(n, source, auxiliary, target):
    if n == 1 then
        move disk from source → target
    else
        Hanoi(n-1, source, target, auxiliary)
        move disk from source → target
        Hanoi(n-1, auxiliary, source, target)
    end if
end procedure
```

* **Base case** $n=1$: trivial one‐move.
* **Recursive case** breaks the problem into two smaller ones of size $n-1$.

**Time complexity:** $\displaystyle T(n) = 2\,T(n-1) + 1$, giving $T(n)=2^n - 1$ moves (**exponential**).

---

## 5. Iterative (Non-Recursive) Algorithm

You can also solve it iteratively using bit-patterns or a simple loop given the parity of $N$:

1. **Number pegs**: 1 = source, 2 = auxiliary, 3 = target.
2. If $N$ is even, **swap** the roles of auxiliary and target.
3. For moves $k = 1$ to $2^N - 1$:

   * If $k$ is **odd**, move the smallest disk one peg **forward** (1→2→3→1).
   * If $k$ is **even**, make the only legal move **not** involving the smallest disk.

### Pseudocode Sketch

```
procedure HanoiIterative(n):
    total_moves = 2^n - 1
    if n is even:
        swap(auxiliary, target)
    for k from 1 to total_moves:
        if k mod 2 == 1:
            move smallest disk one peg forward (in cyclic order)
        else:
            move one legal non-smallest move
```

This runs in $O(2^n)$ time as well (you still make all moves), but avoids recursion.

---

## 6. Summary of Key Points

* **Minimum moves**: $2^N - 1$.
* **Recursive structure**: Move top $N-1$ twice, around one big disk.
* **Iterative approach**: Rely on parity and legal-move rules.
* **Teaching tool**: Illustrates induction, recursion, and algorithmic complexity.
