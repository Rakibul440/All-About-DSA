# Vector

Here are some examples of vector functions in C++:

## Constructors

**1. vector(): Default constructor**

```c++ 
std::vector<int> v; // Empty vector
```


**1. vector(size_type n): Constructor with size**

```c++
std::vector<int> v(5); // Vector with 5 elements, all initialized to 0
```

**1. vector(size_type n, const T& value): Constructor with size and value**
```c++
std::vector<int> v(5, 10); // Vector with 5 elements, all initialized to 10
```

## Iterators

**1. begin(): Returns iterator to beginning**
```c++
std::vector<int> v = {1, 2, 3};
auto it = v.begin(); // it points to the first element (1)
```

**1. end(): Returns iterator to end**
```c++
std::vector<int> v = {1, 2, 3};
auto it = v.end(); // it points to the end of the vector
```

## Capacity

**1. size(): Returns number of elements**
```c++
std::vector<int> v = {1, 2, 3};
std::cout << v.size() << std::endl; // Output: 3
```

**1. resize(size_type n): Resizes vector**
```c++
std::vector<int> v = {1, 2, 3};
v.resize(5); // Vector now has 5 elements, last two initialized to 0
```

## Modifiers

**1. push_back(const T& value): Adds element to end**
```c++
std::vector<int> v = {1, 2, 3};
v.push_back(4); // Vector now has 4 elements: {1, 2, 3, 4}
```
**1. insert(iterator pos, const T& value): Inserts element at position**
```c++
std::vector<int> v = {1, 2, 3};
v.insert(v.begin() + 1, 10); // Vector now has 4 elements: {1, 10, 2, 3}
```


## Element Access

**1. operator[](size_type n): Accesses element at index**
```c++
std::vector<int> v = {1, 2, 3};
std::cout << v[1] << std::endl; // Output: 2
```
  
**1. at(size_type n): Accesses element at index with bounds checking**
```c++
std::vector<int> v = {1, 2, 3};
std::cout << v.at(1) << std::endl; // Output: 2
```