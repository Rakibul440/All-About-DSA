Below is a detailed explanation of hashing in data structures with a focus on C++, including core concepts, collision resolution techniques, and sample code implementations. I'll first explain the concepts and then provide code examples.

---

## 1. Overview of Hashing

**Hashing** is a technique that transforms keys into an index in a fixed-size table (hash table) using a **hash function**. In C++, hashing is used in many applications—from implementing associative containers like `std::unordered_map` to designing custom data structures.

**Key Points:**

- **Hash Function:** Converts a key (which can be a number, string, etc.) into an integer index. The quality of this function is crucial as it must distribute keys uniformly across the hash table.
- **Hash Table:** A data structure (often an array) where each slot is used to store the data or a reference to it.
- **Collision:** When two different keys hash to the same index, a collision occurs. Resolving collisions efficiently is key to maintaining performance.

*(See details in citeturn0search0)*

---

## 2. Hash Functions in C++

A hash function in C++ takes a key as input and returns an integer (often within the range of the table size). In modern C++ (since C++11), the standard library provides hash function objects (functors) for many built-in types. For example:

```cpp
#include <iostream>
#include <functional>  // For std::hash
#include <string>

int main() {
    std::hash<std::string> hashFunc;
    std::string key = "example";
    size_t hashValue = hashFunc(key);
    std::cout << "Hash value for \"" << key << "\" is: " << hashValue << std::endl;
    return 0;
}
```

This code demonstrates how to use `std::hash` to get a hash value from a string.

*(See details in citeturn0search0)*

---

## 3. Collision Resolution Techniques

Because multiple keys can hash to the same index, we need strategies to handle collisions. Two common techniques are:

### a. Separate Chaining

- **Separate Chaining** uses a data structure (like a linked list or a vector) at each index to hold all items that hash to the same slot.
- **Advantages:** Simple to implement; easy to handle an arbitrary number of collisions.
- **Disadvantages:** Additional memory overhead for storing pointers; worst-case lookup time is linear in the number of elements in one bucket.

#### **C++ Example (Separate Chaining):**

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <string>

// A simple hash table class using separate chaining
class HashTable {
private:
    int tableSize;
    std::vector<std::list<std::pair<std::string, int>>> table;

    // Custom hash function using std::hash
    int hashFunction(const std::string& key) {
        std::hash<std::string> hashFunc;
        return hashFunc(key) % tableSize;
    }

public:
    HashTable(int size) : tableSize(size) {
        table.resize(tableSize);
    }

    // Insert key-value pair
    void insert(const std::string& key, int value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    // Search for a key and return its value (or -1 if not found)
    int search(const std::string& key) {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key)
                return pair.second;
        }
        return -1;  // Not found
    }

    // Display the contents of the hash table
    void display() {
        for (int i = 0; i < tableSize; i++) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i])
                std::cout << "[" << pair.first << " : " << pair.second << "] -> ";
            std::cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(10);
    ht.insert("Alice", 85);
    ht.insert("Bob", 90);
    ht.insert("Charlie", 78);
    ht.insert("David", 92);
    ht.insert("Eve", 88);

    ht.display();

    std::cout << "Search for Bob: " << ht.search("Bob") << std::endl;
    std::cout << "Search for Zoe: " << ht.search("Zoe") << std::endl;  // Should return -1 (not found)

    return 0;
}
```

This implementation shows how to create a hash table using separate chaining with `std::vector` and `std::list`.

*(See details in citeturn0search0)*

---

### b. Open Addressing (Linear Probing)

- **Open Addressing** stores all entries directly in the hash table array. When a collision occurs, the algorithm searches for the next available slot.
- **Linear Probing:** The simplest form of open addressing. When a collision occurs at index `h`, the algorithm checks `h+1`, `h+2`, and so on (wrapping around using modulo arithmetic) until an empty slot is found.
- **Advantages:** No extra memory for pointers; all data stored in one contiguous block.
- **Disadvantages:** Clustering may occur, and performance degrades when the table is nearly full.

#### **C++ Example (Open Addressing with Linear Probing):**

```cpp
#include <iostream>
#include <vector>
#include <string>

class OpenAddressingHashTable {
private:
    struct Entry {
        std::string key;
        int value;
        bool isOccupied;
        Entry() : key(""), value(0), isOccupied(false) {}
    };

    std::vector<Entry> table;
    int tableSize;

    int hashFunction(const std::string& key) {
        std::hash<std::string> hashFunc;
        return hashFunc(key) % tableSize;
    }

public:
    OpenAddressingHashTable(int size) : tableSize(size) {
        table.resize(tableSize);
    }

    void insert(const std::string& key, int value) {
        int index = hashFunction(key);
        int originalIndex = index;
        // Linear probing: look for the next available slot
        while (table[index].isOccupied) {
            index = (index + 1) % tableSize;
            if (index == originalIndex) {  // Table is full
                std::cerr << "Hash table is full!\n";
                return;
            }
        }
        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
    }

    int search(const std::string& key) {
        int index = hashFunction(key);
        int originalIndex = index;
        while (table[index].isOccupied) {
            if (table[index].key == key)
                return table[index].value;
            index = (index + 1) % tableSize;
            if (index == originalIndex)
                break;
        }
        return -1;  // Not found
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i].isOccupied)
                std::cout << i << " : " << "[" << table[i].key << ", " << table[i].value << "]\n";
            else
                std::cout << i << " : " << "Empty\n";
        }
    }
};

int main() {
    OpenAddressingHashTable ht(10);
    ht.insert("Alice", 85);
    ht.insert("Bob", 90);
    ht.insert("Charlie", 78);
    ht.insert("David", 92);
    ht.insert("Eve", 88);

    ht.display();

    std::cout << "Search for Bob: " << ht.search("Bob") << std::endl;
    std::cout << "Search for Zoe: " << ht.search("Zoe") << std::endl;  // Should return -1

    return 0;
}
```

This code demonstrates open addressing using linear probing. Notice how collisions are handled by moving to the next index until an empty slot is found.

*(See details in citeturn0search0)*

---

## 4. Advantages and Disadvantages of Hashing

### Advantages
- **Fast Operations:** In the best-case scenario, insertion, deletion, and search operations can be done in constant time, O(1).
- **Direct Access:** Hashing allows quick retrieval of data without the need to search through every element.

### Disadvantages
- **Collisions:** Even with a good hash function, collisions are inevitable. Poor collision resolution can degrade performance.
- **Memory Overhead:** Especially with separate chaining, extra memory is needed for pointers (or additional containers).
- **Load Factor Sensitivity:** Performance degrades as the table becomes full, so maintaining an optimal load factor is important.

*(See details in citeturn0search0)*

---

## 5. Real-World Applications

- **Associative Containers:** C++ STL’s `std::unordered_map` and `std::unordered_set` rely on hash tables.
- **Databases:** Fast lookup for indexing.
- **Caching:** Quick retrieval of cached data.
- **Cryptography:** Although cryptographic hash functions (e.g., SHA-256) are different in purpose, they are also based on hashing principles.

*(See details in citeturn0search0)*

---

## Conclusion

Hashing is an essential technique in data structures that helps achieve efficient data storage and retrieval. In C++, you can either use standard library containers like `std::unordered_map` for most use cases or implement your own hash table for a deeper understanding and more customized control—choosing between separate chaining and open addressing for collision resolution.

