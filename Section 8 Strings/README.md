# Strings in DSA — Complete Notes and Interview Guide

A practical guide to strings for Data Structures and Algorithms (DSA), including fundamentals, operations, complexity, common patterns, algorithms, examples in C++, and interview tips.

---

## Table of Contents

1. [What Is a String?](#1-what-is-a-string)
2. [Important Terminology](#2-important-terminology)
3. [Strings in C++](#3-strings-in-c)
4. [Common String Operations](#4-common-string-operations)
5. [Time and Space Complexity](#5-time-and-space-complexity)
6. [ASCII, Characters, and Character Handling](#6-ascii-characters-and-character-handling)
7. [Substring vs Subsequence vs Subarray](#7-substring-vs-subsequence-vs-subarray)
8. [Essential String Techniques](#8-essential-string-techniques)
9. [Important String Algorithms](#9-important-string-algorithms)
10. [Common DSA Problem Patterns](#10-common-dsa-problem-patterns)
11. [Frequently Asked String Problems](#11-frequently-asked-string-problems)
12. [Common Mistakes](#12-common-mistakes)
13. [How to Approach a String Problem](#13-how-to-approach-a-string-problem)
14. [Interview Questions and Short Answers](#14-interview-questions-and-short-answers)
15. [Practice Roadmap](#15-practice-roadmap)
16. [Quick Revision Sheet](#16-quick-revision-sheet)

---

## 1. What Is a String?

A **string** is a sequence of characters. Characters may include letters, digits, spaces, punctuation, and symbols.

Examples:

```text
"hello"
"DSA2026"
"Hello World!"
""
```

The last example is an **empty string**: a string with zero characters.

### Why are strings important in DSA?

Strings are used in:
- Text processing and searching
- Input validation
- Password and username checks
- Search engines
- Compilers and interpreters
- Data compression
- DNA sequence analysis
- Natural language processing
- Pattern matching

A string problem often involves finding, comparing, counting, rearranging, or matching characters.

### String indexing

In C++, string indexing starts at `0`.

For:

```cpp
string s = "hello";
```

| Index | Character |
|---:|:---|
| 0 | `h` |
| 1 | `e` |
| 2 | `l` |
| 3 | `l` |
| 4 | `o` |

For a non-empty string of length `n`, valid indices are `0` through `n - 1`.

---

## 2. Important Terminology

- **Character:** One symbol, such as `'a'`, `'7'`, or `'?'`.
- **String length:** Number of characters in a string.
- **Empty string:** A string containing no characters.
- **Substring:** A contiguous sequence of characters from a string.
- **Subsequence:** Characters selected in their original order, but not necessarily contiguously.
- **Prefix:** A substring that begins at index `0`.
- **Suffix:** A substring that ends at the final character.
- **Palindrome:** A string that reads the same forward and backward.
- **Anagram:** Two strings containing the same characters with the same frequencies, usually ignoring order.
- **Rotation:** A string produced by moving some leading characters to the end, or vice versa.
- **Lexicographical order:** Dictionary-like order based on character comparison.
- **Pattern matching:** Finding where a pattern occurs inside a larger string.
- **Frequency:** Number of times a character occurs.
- **Case-sensitive comparison:** Treating uppercase and lowercase letters as different characters.

### Examples

For `s = "banana"`:
- Prefixes include `"b"`, `"ba"`, and `"ban"`.
- Suffixes include `"a"`, `"na"`, and `"ana"`.
- Substring `"ana"` occurs starting at indices `1` and `3`.
- `"bna"` is a subsequence, but not a substring.
- `"ananab"` is the reverse of `"banana"`.

---

## 3. Strings in C++

C++ provides `std::string` in the `<string>` header.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Rakibul";
    cout << name << '\n';
    cout << name.length() << '\n';
    return 0;
}
```

### Declaring strings

```cpp
string a = "hello";
string b("world");
string empty = "";
string repeated(5, 'x');  // "xxxxx"
```

### Reading input

```cpp
string word;
cin >> word;  // Reads until whitespace
```

To read a full line including spaces:

```cpp
string line;
getline(cin, line);
```

If `getline()` follows a `cin >>` operation, a leftover newline may cause it to read an empty line. One common solution is:

```cpp
int n;
cin >> n;
cin.ignore();
string line;
getline(cin, line);
```

For robust input handling, `getline(cin >> ws, line)` can also skip leading whitespace.

### Accessing and modifying characters

```cpp
string s = "hello";
char first = s[0];  // 'h'
s[0] = 'H';         // "Hello"
```

` s[i] ` does not perform bounds checking. Use `s.at(i)` when bounds checking is desired.

### Useful methods

```cpp
s.size();                 // Number of characters
s.length();               // Same as size()
s.empty();                // True if empty
s.push_back('!');         // Add one character at the end
s.pop_back();             // Remove the final character
s += " world";             // Append text
s.append("!");             // Append text
s.substr(1, 3);            // Three characters starting at index 1
s.find("ll");              // Position of first match, or string::npos
s.find('o');               // Position of character, or string::npos
s.rfind('l');              // Position of last match, or string::npos
s.insert(1, "ABC");        // Insert at index 1
s.erase(1, 2);             // Remove 2 characters starting at index 1
s.replace(0, 2, "Hi");     // Replace 2 characters starting at index 0
s.clear();                 // Remove all characters
```

Example of checking `find()`:

```cpp
if (s.find("cat") != string::npos) {
    cout << "Found";
}
```

### Sorting a string

```cpp
#include <algorithm>
sort(s.begin(), s.end());
```

Sorting rearranges characters in ascending order according to the character comparison rules. It is useful for many anagram problems.

### Reversing a string

```cpp
#include <algorithm>
reverse(s.begin(), s.end());
```

### Character conversion

```cpp
#include <cctype>

char c = 'a';
char upper = static_cast<char>(toupper(static_cast<unsigned char>(c)));
char lower = static_cast<char>(tolower(static_cast<unsigned char>(c)));
```

For ordinary English letters, `toupper()` and `tolower()` are often enough. For general Unicode text, these functions are not a complete Unicode case-conversion solution.

### C-style strings vs `std::string`

- A C-style string is usually stored in a character array ending with the null character `'\0'`.
- `std::string` manages its own length and memory and is generally easier and safer for DSA problems.
- Do not confuse the character `'0'` with the null character `'\0'`.

---

## 4. Common String Operations

### 4.1 Find the length

```cpp
int n = static_cast<int>(s.size());
```

For a `std::string`, `size()` is constant time.

### 4.2 Reverse a string

```cpp
string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}
```

Time: `O(n)`.

### 4.3 Check a palindrome

```cpp
bool isPalindrome(const string& s) {
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;

    while (left < right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    return true;
}
```

Time: `O(n)`, auxiliary space: `O(1)`.

This version compares characters exactly. If a problem says to ignore spaces, punctuation, or letter case, preprocess the input or skip irrelevant characters while comparing.

### 4.4 Count character frequencies

For input restricted to standard English letters:

```cpp
int freq[256] = {0};
for (unsigned char c : s) {
    ++freq[c];
}
```

For lowercase English letters only:

```cpp
int freq[26] = {0};
for (char c : s) {
    if (c >= 'a' && c <= 'z') {
        ++freq[c - 'a'];
    }
}
```

Use an array of size `26` only when the input constraints guarantee lowercase English letters. For a broader character set, choose an appropriate map or representation.

### 4.5 Check anagrams

For lowercase English letters:

```cpp
bool areAnagrams(const string& a, const string& b) {
    if (a.size() != b.size()) return false;

    int freq[26] = {0};
    for (char c : a) ++freq[c - 'a'];
    for (char c : b) --freq[c - 'a'];

    for (int count : freq) {
        if (count != 0) return false;
    }
    return true;
}
```

Time: `O(n)`; space: `O(1)` for the fixed 26-letter array.

This implementation assumes both strings contain only lowercase English letters. For other inputs, define how case, spaces, punctuation, and Unicode should be handled.

### 4.6 Remove duplicate characters

A common approach uses a `seen` array or set and appends each character only the first time it appears. If order must be preserved, do not sort the string first.

### 4.7 Reverse the words in a sentence

Clarify the requirement:
- Reverse the order of words: `"I love DSA"` becomes `"DSA love I"`.
- Reverse each word: `"I love DSA"` becomes `"I evol ASD"`.
- Reverse every character in the entire string: `"I love DSA"` becomes `"ASD evol I"`.

These are different problems.

### 4.8 Find a substring

```cpp
string s = "hello world";
size_t pos = s.find("world");

if (pos != string::npos) {
    cout << "Found at index " << pos;
}
```

`find()` is convenient, but when a problem asks you to implement pattern matching, you may need to use a dedicated algorithm such as KMP or Rabin–Karp.

---

## 5. Time and Space Complexity

Let `n` be the string length and `m` be the pattern length.

| Operation | Typical complexity | Notes |
|---|---:|---|
| Access `s[i]` | `O(1)` | Requires a valid index |
| Get `s.size()` | `O(1)` | For `std::string` |
| Traverse all characters | `O(n)` | One pass |
| Compare two strings | `O(min(n, m))` best/early mismatch; up to `O(n)` when lengths are equal | Depends on the input |
| Copy a string | `O(n)` | Copies characters |
| Reverse a string | `O(n)` | In-place algorithm |
| Sort characters | `O(n log n)` | Comparison-based sorting |
| Build a frequency array | `O(n)` | Fixed alphabet gives `O(1)` extra space |
| Naive pattern search | `O(nm)` worst case | Checks the pattern at each possible position |
| KMP pattern search | `O(n + m)` | After building the LPS array |
| Rabin–Karp | Expected `O(n + m)` with suitable hashing; worst case can be `O(nm)` | Hash collisions require verification |
| Sliding window | Often `O(n)` | When each pointer moves forward at most `n` times |
| Dynamic programming on two strings | Often `O(nm)` | Depends on the problem |

**Important:** Complexity depends on the exact operation, input constraints, implementation, and language. Do not memorize a complexity without understanding the algorithm.

---

## 6. ASCII, Characters, and Character Handling

### Character arithmetic

For lowercase English letters:

```cpp
int index = c - 'a';  // 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
```

For uppercase English letters:

```cpp
int index = c - 'A';  // 'A' -> 0, ..., 'Z' -> 25
```

This technique is valid only when the input character is within the expected range.

### Useful C++ character functions

Include `<cctype>`:

- `isalpha(c)` — checks whether a character is alphabetic in the active C locale.
- `isdigit(c)` — checks whether it is a digit.
- `islower(c)` — checks for lowercase.
- `isupper(c)` — checks for uppercase.
- `isspace(c)` — checks for whitespace.
- `tolower(c)` — converts to lowercase where supported.
- `toupper(c)` — converts to uppercase where supported.

When passing a possibly signed `char` to these functions, convert it to `unsigned char` first:

```cpp
if (isdigit(static_cast<unsigned char>(c))) {
    // c is a digit according to the active C locale
}
```

### Unicode warning

A visible character is not always one byte. UTF-8 text may use multiple bytes per Unicode code point, and a displayed symbol can involve multiple code points. Many coding-platform problems restrict input to English letters, but real-world text processing may require Unicode-aware libraries and grapheme-cluster handling.

---

## 7. Substring vs Subsequence vs Subarray

### Substring

A **substring** is contiguous.

For `"ABCDE"`:
- `"BCD"` is a substring.
- `"ACE"` is not a substring.

A string of length `n` has `n(n + 1) / 2` non-empty substring occurrences when different positions are counted, though some substrings may have identical text.

### Subsequence

A **subsequence** preserves character order but may skip characters.

For `"ABCDE"`:
- `"ACE"` is a subsequence.
- `"AEC"` is not a subsequence because the order changes.

A string of length `n` has `2^n` subsequences when the empty subsequence is included and different selections of positions are counted. Repeated characters can make different selections produce identical text.

### Subarray

A **subarray** is the contiguous equivalent for arrays. In string problems, the usual term is **substring**.

### Prefix and suffix

For `"coding"`:
- Prefixes: `""`, `"c"`, `"co"`, `"cod"`, `"codi"`, `"codin"`, `"coding"`.
- Suffixes: `""`, `"g"`, `"ng"`, `"ing"`, `"ding"`, `"oding"`, `"coding"`.

The empty prefix and suffix are often included in mathematical definitions.

---

## 8. Essential String Techniques

### 8.1 Two pointers

Use two indices, commonly one at the start and one at the end.

Useful for:
- Palindrome checks
- Reversing a string
- Comparing characters from both ends
- Removing or skipping selected characters

Typical structure:

```cpp
int left = 0;
int right = static_cast<int>(s.size()) - 1;

while (left < right) {
    // Compare or process s[left] and s[right]
    ++left;
    --right;
}
```

### 8.2 Frequency counting

Count how often each character appears using:
- An array for a small, known alphabet
- `unordered_map<char, int>` for a general set of byte-sized characters
- An appropriate Unicode-aware representation for Unicode text

Useful for:
- Anagrams
- Duplicate characters
- First non-repeating character
- Frequency-based rearrangement

### 8.3 Hashing

A hash maps data to a numeric value that can help compare strings quickly. Hash equality does **not** guarantee string equality because collisions are possible. Verify actual strings when correctness requires it.

Useful for:
- Rabin–Karp
- Comparing substrings
- Detecting repeated sequences
- Rolling-hash problems

### 8.4 Sliding window

Maintain a range `[left, right]` and move its boundaries while tracking relevant information.

Useful for:
- Longest substring without repeating characters
- Longest substring with at most `k` distinct characters
- Minimum window substring
- Anagram searches

A typical window expands by moving `right`. When a constraint is violated, move `left` until the window becomes valid again. The exact rule depends on the problem.

### 8.5 Sorting

Sorting characters can make anagrams easy to compare.

Example:
- `"listen"` sorted becomes `"eilnst"`.
- `"silent"` sorted becomes `"eilnst"`.

Sorting usually costs `O(n log n)`, so a frequency array can be faster when the alphabet is small and known.

### 8.6 Prefix sums / prefix counts

Precompute counts up to each index to answer range-frequency questions efficiently.

For example, a prefix count of vowels can answer how many vowels occur between indices `l` and `r` using a subtraction of two prefix values.

### 8.7 Dynamic programming (DP)

DP is useful when a problem asks about:
- Longest common subsequence
- Edit distance
- Palindrome partitioning
- Distinct subsequences
- Wildcard or regular-expression matching
- Word break

A DP solution usually defines a state, a transition, base cases, and an order of computation.

### 8.8 Greedy methods

Some string problems can be solved by making locally optimal choices, such as certain character-rearrangement or lexicographical construction tasks. A greedy choice needs a proof; it is not automatically correct just because it looks reasonable.

### 8.9 Stack

A stack is useful when the latest character or group must be processed first.

Examples:
- Decode nested encoded strings
- Remove adjacent duplicates
- Validate brackets
- Simplify strings using cancellation rules

### 8.10 Trie (prefix tree)

A trie stores words by their prefixes.

Useful for:
- Prefix search
- Dictionary lookup
- Autocomplete
- Word search
- Prefix-based grouping

For an alphabet of size `A`, each node may store up to `A` child references. Memory use depends on the number of nodes and the representation.

---

## 9. Important String Algorithms

### 9.1 Naive pattern matching

Try aligning the pattern at every possible position in the text and compare characters.

- Text length: `n`
- Pattern length: `m`
- Worst-case time: `O(nm)`
- Extra space: often `O(1)`

It is easy to implement and useful for small inputs.

### 9.2 Knuth–Morris–Pratt (KMP)

KMP avoids rechecking text characters unnecessarily when a mismatch occurs.

Core concept:
- Build the **LPS array** (Longest Proper Prefix that is also a Suffix) for the pattern.
- Use LPS to determine how far the pattern pointer can move after a mismatch.

Complexity:
- Preprocessing: `O(m)`
- Search: `O(n)`
- Total: `O(n + m)`

Learn:
1. Proper prefix and suffix
2. How to build the LPS array
3. How to handle mismatches
4. How to find overlapping pattern matches

### 9.3 Rabin–Karp

Rabin–Karp uses rolling hashes to compare the pattern hash with hashes of text windows.

Basic process:
1. Hash the pattern.
2. Hash the first text window.
3. Slide the window and update the hash efficiently.
4. When hashes match, verify the characters to handle collisions.

Expected performance can be close to `O(n + m)` with good hashing, but worst-case performance can be `O(nm)`.

### 9.4 Z-algorithm

The Z-array stores, for each index, the length of the longest substring starting there that matches the prefix of the whole string.

For pattern matching, construct a combined sequence such as:

```text
pattern + separator + text
```

Choose a separator that cannot occur in the input, or use a representation that avoids separator ambiguity.

Complexity: `O(n + m)`.

### 9.5 Manacher's algorithm

Manacher's algorithm finds the longest palindromic substring in linear time.

Core idea:
- Track the rightmost palindrome found so far.
- Use symmetry around its center to initialize palindrome radii.
- Expand only when needed.

Complexity: `O(n)` time and typically `O(n)` extra space.

### 9.6 Longest Common Subsequence (LCS)

The LCS of two strings is the longest sequence appearing in both in the same relative order; characters do not need to be adjacent.

For strings `a` and `b`, a common DP recurrence is:

- If `a[i - 1] == b[j - 1]`, then `dp[i][j] = 1 + dp[i - 1][j - 1]`.
- Otherwise, `dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])`.

With a standard table:
- Time: `O(nm)`
- Space: `O(nm)`, reducible to `O(min(n, m))` if only the length is required.

### 9.7 Edit distance (Levenshtein distance)

Find the minimum number of insertions, deletions, and substitutions needed to convert one string into another.

The standard DP solution takes:
- Time: `O(nm)`
- Space: `O(nm)`, reducible for the distance alone.

### 9.8 Suffix array

A suffix array stores the starting indices of all suffixes in sorted order. It supports powerful substring and repeated-pattern tasks when combined with additional structures such as the LCP array.

Construction complexity depends on the algorithm; efficient methods can achieve `O(n log n)` or better under suitable assumptions.

### 9.9 Suffix tree

A suffix tree is a compressed trie of all suffixes of a string. It can support many substring queries efficiently but is more complex to implement correctly and memory-efficiently.

### 9.10 Aho–Corasick

Aho–Corasick searches for many patterns in a text in one pass after building a trie with failure links.

Useful for:
- Dictionary matching
- Multiple keyword detection
- Search filters

Typical complexity is proportional to total pattern length plus text length and the number of matches, subject to implementation details.

### 9.11 Trie

A trie is a tree of prefixes. Insertion and lookup typically take `O(L)` time for a word of length `L`, assuming child access is constant time. Memory can be substantial for large alphabets or sparse data.

### 9.12 Rolling hash

A rolling hash updates the hash of a window as it moves, rather than recomputing the entire hash. It is useful for comparing substrings, but collision handling matters.

### 9.13 Palindrome DP

For many palindrome problems, define `dp[i][j]` to indicate whether substring `s[i..j]` is a palindrome.

A common recurrence is:
- The endpoints must match.
- The inside substring must be a palindrome, with special base cases for lengths 1 and 2.

This approach is often `O(n^2)` in time and space.

---

## 10. Common DSA Problem Patterns

| Pattern | Recognize it when the problem asks for | Typical tools |
|---|---|---|
| Two pointers | Compare or process both ends | Two indices |
| Frequency counting | Count or compare characters | Array, map |
| Sliding window | Longest/shortest valid substring | Two pointers + counts |
| Sorting | Compare character multisets | Sorting |
| Hashing | Compare sequences or windows quickly | Hash map, rolling hash |
| Stack | Nested or last-in-first-out processing | Stack |
| Greedy | Build a result through justified local choices | Counts, priority queue |
| Dynamic programming | Optimal value or number of ways across prefixes/states | DP table |
| Trie | Prefix or dictionary queries | Trie |
| KMP / Z | Find a pattern efficiently | Prefix/LPS or Z array |
| Binary search on answer | Feasibility changes monotonically with a candidate answer | Binary search + check |
| Backtracking | Enumerate valid combinations or partitions | Recursion |
| Graph search | Word transformation or grid word paths | BFS/DFS |
| Suffix structures | Many substring/repetition queries | Suffix array/tree/automaton |

### A quick decision guide

- **Small fixed alphabet?** Consider a frequency array.
- **Need to compare character counts?** Consider frequency counting or sorting.
- **Need the longest/shortest substring satisfying a condition?** Consider sliding window.
- **Need a palindrome check?** Consider two pointers.
- **Need the longest common subsequence or edit distance?** Consider DP.
- **Need fast exact pattern search?** Consider KMP or Z.
- **Need to search for many patterns?** Consider Aho–Corasick.
- **Need prefix lookup across many words?** Consider a trie.
- **Need many advanced substring queries?** Consider suffix arrays or related structures.

These are starting points, not automatic answers. Check the constraints and prove that the chosen approach works.

---

## 11. Frequently Asked String Problems

### Basic

1. Reverse a string.
2. Check whether a string is a palindrome.
3. Count vowels and consonants.
4. Count character frequencies.
5. Remove spaces from a string.
6. Convert lowercase letters to uppercase.
7. Count words in a sentence.
8. Find the first repeating character.
9. Find the first non-repeating character.
10. Remove duplicate characters.
11. Check whether two strings are anagrams.
12. Reverse the words in a sentence.
13. Find the most frequent character.
14. Check whether a string contains only digits.
15. Find the first and last occurrence of a character.

### Intermediate

1. Longest common prefix.
2. Check whether one string is a rotation of another.
3. Longest substring without repeating characters.
4. Longest palindromic substring.
5. Group anagrams.
6. String compression.
7. Isomorphic strings.
8. Find all anagram indices.
9. Minimum window substring.
10. Longest substring with exactly `k` distinct characters.
11. Decode an encoded string.
12. Compare strings containing backspaces.
13. Longest common substring.
14. Rearrange characters so adjacent characters differ.
15. Minimum deletions to make two strings equal.

### Advanced

1. KMP pattern matching.
2. Rabin–Karp pattern matching.
3. Z-algorithm.
4. Manacher's algorithm.
5. Longest common subsequence.
6. Edit distance.
7. Shortest common supersequence.
8. Longest palindromic subsequence.
9. Distinct subsequences.
10. Palindrome partitioning with minimum cuts.
11. Count distinct substrings.
12. Longest duplicate substring.
13. Wildcard matching.
14. Regular expression matching.
15. Word break.
16. Aho–Corasick multiple-pattern matching.
17. Suffix array construction.
18. Suffix automaton.
19. Minimum window subsequence.
20. Longest common substring among multiple strings.

---

## 12. Common Mistakes

1. **Off-by-one errors:** A string of length `n` has final valid index `n - 1`.
2. **Empty strings:** Handle `""` before accessing the first or last character.
3. **One-character strings:** Many pointer loops should stop when `left >= right`.
4. **Case sensitivity:** `"A"` and `"a"` are different in ordinary comparisons.
5. **Spaces and punctuation:** Read the question carefully to determine whether to include or ignore them.
6. **Wrong input function:** `cin >> s` stops at whitespace; `getline()` reads a line.
7. **Invalid frequency array:** `freq[c - 'a']` is valid only for lowercase English letters.
8. **Assuming all characters are ASCII:** Unicode text can require more careful handling.
9. **Repeated string concatenation:** Building a large result inefficiently can lead to unnecessary copying. Consider appending to a mutable string.
10. **Ignoring constraints:** An `O(n^2)` approach may fail when `n` is large.
11. **Hash collisions:** Equal hashes do not always mean equal strings.
12. **Wrong definition:** A subsequence is not necessarily contiguous; a substring is.
13. **Overwriting needed data:** When changing characters in place, make sure future comparisons still use the correct values.
14. **Incorrect duplicate handling:** Decide whether duplicates should be removed entirely or only repeated occurrences.
15. **Incorrect word reversal:** Reversing word order is different from reversing each word.
16. **Signed character issues:** Pass `unsigned char` values to `<cctype>` functions when input bytes may be negative as `char`.
17. **Unclear anagram rules:** Define whether spaces, punctuation, and letter case matter.
18. **Incorrect DP base cases:** Verify empty-prefix and single-character cases.
19. **Not checking overlapping matches:** Pattern matching may need to report overlapping occurrences.
20. **Premature optimization:** First produce a correct solution, then improve its complexity.

---

## 13. How to Approach a String Problem

Use this checklist in coding interviews:

### Step 1: Understand the input and output
- Is there one string or multiple strings?
- Can the string be empty?
- What characters are allowed?
- Is the comparison case-sensitive?
- Should spaces and punctuation count?

### Step 2: Work through examples
Try:
- Empty input
- One character
- Repeated characters
- All unique characters
- A palindrome
- No match
- A match at the beginning or end
- Large input

### Step 3: Start with a simple approach
Explain a brute-force solution first if it helps clarify the problem.

### Step 4: Identify the pattern
Consider two pointers, frequency counting, sliding window, hashing, stack, DP, or a string-matching algorithm.

### Step 5: State the invariant
An invariant is a condition that stays true during the algorithm. For a sliding window, for example, the current window may always satisfy a defined constraint.

### Step 6: Analyze complexity
State time and auxiliary space complexity. Be clear about whether the returned result or copied input is included.

### Step 7: Test edge cases
Do not test only the example given in the question.

### Step 8: Improve if needed
Use constraints to decide whether a faster or more memory-efficient algorithm is necessary.

---

## 14. Interview Questions and Short Answers

### Q1. What is a string?
A string is a sequence of characters.

### Q2. What is the difference between a character and a string?
A character represents one character, while a string contains a sequence of characters.

### Q3. What is a palindrome?
A string that reads the same forward and backward, such as `"level"`.

### Q4. What is an anagram?
Two strings are anagrams if they contain the same characters with the same frequencies, under the problem's character rules.

### Q5. What is the difference between a substring and a subsequence?
A substring is contiguous. A subsequence preserves order but may skip characters.

### Q6. What is a prefix?
A prefix is a substring that begins at the start of the string.

### Q7. What is a suffix?
A suffix is a substring that ends at the end of the string.

### Q8. What is string matching?
String matching means finding occurrences of a pattern in a larger text.

### Q9. What is the sliding-window technique?
It maintains a range of characters and moves its boundaries to solve substring problems efficiently.

### Q10. What is hashing used for in string problems?
Hashing helps compare or identify strings and substrings efficiently, but collisions must be considered.

### Q11. What is KMP?
KMP is a pattern-matching algorithm that uses an LPS array to avoid unnecessary comparisons.

### Q12. What is the LPS array?
LPS means Longest Proper Prefix that is also a Suffix. It helps KMP decide how far to shift the pattern after a mismatch.

### Q13. What is Rabin–Karp?
It is a pattern-matching algorithm that uses rolling hashes to compare a pattern with text windows.

### Q14. What is a trie?
A trie is a tree-based data structure that stores strings by their prefixes.

### Q15. What is the longest common subsequence?
It is the longest sequence shared by two strings in the same relative order, not necessarily contiguously.

### Q16. What is edit distance?
It is the minimum number of allowed edit operations needed to transform one string into another.

### Q17. Why use a frequency array?
It can count characters in linear time with constant extra space when the alphabet is fixed and small.

### Q18. When is a sliding window useful?
It is useful for many problems asking for the longest or shortest substring satisfying a condition.

### Q19. What is a rolling hash?
It is a hash that can be updated efficiently as a window moves across a string.

### Q20. Why can two equal hashes be insufficient?
Different strings can produce the same hash due to collisions, so exact equality may need verification.

### Q21. What is Manacher's algorithm?
It finds the longest palindromic substring in linear time.

### Q22. What is the Aho–Corasick algorithm?
It finds occurrences of multiple patterns in a text using a trie and failure links.

### Q23. What is a suffix array?
It is an array of starting indices of all suffixes, sorted lexicographically.

### Q24. What is dynamic programming in string problems?
It solves a problem by storing results of smaller overlapping subproblems, as in LCS and edit distance.

### Q25. How do you choose a string algorithm?
Use the input constraints, required output, and problem structure to select an approach and justify its correctness.

---

## 15. Practice Roadmap

### Stage 1: Fundamentals
Practice:
- String traversal
- Indexing
- Reversal
- Palindrome checks
- Character counting
- Basic input handling

Goal: Solve simple problems without index errors.

### Stage 2: Frequency and ordering
Practice:
- Anagrams
- Duplicate characters
- First unique character
- Sorting strings
- Character replacement

Goal: Recognize when frequency arrays or maps are appropriate.

### Stage 3: Two pointers and sliding window
Practice:
- Palindrome variations
- Longest substring without repetition
- Anagram indices
- Minimum window substring
- `k` distinct characters

Goal: Learn to maintain a correct window and update its state efficiently.

### Stage 4: Stack and recursion
Practice:
- Decode strings
- Remove adjacent duplicates
- Valid brackets
- Word-break variations
- String partitioning

Goal: Handle nested structure and explore valid choices.

### Stage 5: Dynamic programming
Practice:
- LCS
- Longest palindromic subsequence
- Edit distance
- Distinct subsequences
- Wildcard matching
- Palindrome partitioning

Goal: Define states, transitions, and base cases clearly.

### Stage 6: Pattern matching
Practice:
- Naive matching
- KMP and LPS
- Rabin–Karp
- Z-algorithm
- Multiple-pattern matching

Goal: Understand how to search efficiently without repeatedly comparing the same characters.

### Stage 7: Advanced structures
Practice:
- Tries
- Suffix arrays
- LCP arrays
- Suffix automata
- Manacher's algorithm

Goal: Learn these after the fundamentals and common interview patterns are comfortable.

### Suggested daily routine
1. Review one concept.
2. Solve two easy problems.
3. Solve one medium problem.
4. Explain the approach aloud.
5. Record time and space complexity.
6. Revisit problems you could not solve independently.

Consistency and reviewing mistakes are more valuable than rushing through a long list.

---

## 16. Quick Revision Sheet

| Topic | Remember |
|---|---|
| String | Sequence of characters |
| C++ string | `std::string` from `<string>` |
| Indexing | Starts at `0` |
| Final valid index | `n - 1` for non-empty strings |
| Reverse | Two pointers or `reverse()` |
| Palindrome | Compare characters from both ends |
| Anagram | Compare character frequencies |
| Duplicate detection | Frequency array or set |
| Sliding window | Maintain a valid contiguous range |
| Two pointers | Move two indices according to the condition |
| KMP | LPS array; `O(n + m)` |
| Z-algorithm | Prefix-match lengths; `O(n + m)` |
| Rabin–Karp | Rolling hash; verify collisions |
| Manacher | Longest palindromic substring in `O(n)` |
| LCS | DP; standard time `O(nm)` |
| Edit distance | DP; standard time `O(nm)` |
| Trie | Efficient prefix-based storage and lookup |
| Aho–Corasick | Match multiple patterns |
| Suffix array | Sorted suffix starting positions |
| Unicode | A displayed character may not equal one byte |

### Final advice

Do not try to memorize every algorithm at once. First become comfortable with string traversal, frequency counting, two pointers, and sliding windows. Then study stack-based problems and dynamic programming. Finally, learn specialized algorithms such as KMP, Z, Manacher, and suffix structures.

For every problem, understand **why the approach works**, test edge cases, and explain the time and space complexity.
