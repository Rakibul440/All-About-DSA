/*
===================================================================================
                    COMPREHENSIVE C++ OBJECT-ORIENTED PROGRAMMING GUIDE
===================================================================================

This guide covers all essential OOP concepts in C++ with detailed explanations
and practical examples. Each section builds upon the previous one.

Table of Contents:
1. Classes and Objects - The Foundation
2. Constructors and Destructors - Object Lifecycle
3. Encapsulation - Data Protection and Access Control
4. Inheritance - Code Reusability and Relationships
5. Polymorphism - One Interface, Multiple Forms
6. Virtual Functions - Dynamic Behavior
7. Abstract Classes and Interfaces - Design Contracts
8. Advanced OOP Concepts
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <math.h>

using namespace std;

/*
===================================================================================
                            1. CLASSES AND OBJECTS - THE FOUNDATION
===================================================================================

A class is like a blueprint or template that defines the structure and behavior
of objects. Think of it as a cookie cutter - the class defines the shape,
and objects are the individual cookies made from it.
*/

// Basic class definition - represents a real-world concept (a car)
class Car {
private:
    // Data members (attributes) - what the object "has"
    string brand;
    string model;
    int year;
    double mileage;
    bool isRunning;

public:
    // Member functions (methods) - what the object can "do"
    
    // Function to start the car
    void startEngine() {
        if (!isRunning) {
            isRunning = true;
            cout << brand << " " << model << " engine started!\n";
        } else {
            cout << "Engine is already running.\n";
        }
    }
    
    // Function to stop the car
    void stopEngine() {
        if (isRunning) {
            isRunning = false;
            cout << brand << " " << model << " engine stopped.\n";
        } else {
            cout << "Engine is already off.\n";
        }
    }
    
    // Function to display car information
    void displayInfo() const { // 'const' means this function won't modify object data
        cout << "Car Details:\n";
        cout << "Brand: " << brand << "\n";
        cout << "Model: " << model << "\n";
        cout << "Year: " << year << "\n";
        cout << "Mileage: " << mileage << " miles\n";
        cout << "Status: " << (isRunning ? "Running" : "Stopped") << "\n\n";
    }
    
    // Setter functions - controlled way to modify private data
    void setBrand(const string& b) { brand = b; }
    void setModel(const string& m) { model = m; }
    void setYear(int y) { 
        if (y > 1900 && y <= 2024) { // Data validation
            year = y; 
        }
    }
    
    // Getter functions - safe way to access private data
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getMileage() const { return mileage; }
};

/*
===================================================================================
                        2. CONSTRUCTORS AND DESTRUCTORS - OBJECT LIFECYCLE
===================================================================================

Constructors are special functions that initialize objects when they're created.
Destructors clean up when objects are destroyed. Think of constructors as
"birth certificates" and destructors as "death certificates" for objects.
*/

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;
    static int totalAccounts; // Static member - shared by all objects

public:
    // DEFAULT CONSTRUCTOR - called when no parameters are provided
    BankAccount() {
        accountHolder = "Unknown";
        accountNumber = "0000000000";
        balance = 0.0;
        totalAccounts++;
        cout << "Default constructor called - Account created for " << accountHolder << "\n";
    }
    
    // PARAMETERIZED CONSTRUCTOR - allows custom initialization
    BankAccount(const string& holder, const string& accNum, double initialBalance = 0.0) {
        accountHolder = holder;
        accountNumber = accNum;
        balance = initialBalance;
        totalAccounts++;
        cout << "Parameterized constructor called - Account created for " << holder << "\n";
    }
    
    // COPY CONSTRUCTOR - creates a copy of an existing object
    BankAccount(const BankAccount& other) {
        accountHolder = other.accountHolder + "_COPY";
        accountNumber = other.accountNumber + "_COPY";
        balance = other.balance;
        totalAccounts++;
        cout << "Copy constructor called - Copied account for " << accountHolder << "\n";
    }
    
    // DESTRUCTOR - called when object is destroyed
    ~BankAccount() {
        totalAccounts--;
        cout << "Destructor called - Account for " << accountHolder << " closed.\n";
    }
    
    // Member functions
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << "\n";
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
            return true;
        }
        cout << "Insufficient funds or invalid amount.\n";
        return false;
    }
    
    void displayAccount() const {
        cout << "Account Holder: " << accountHolder << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: $" << balance << "\n\n";
    }
    
    // Static function - belongs to class, not individual objects
    static int getTotalAccounts() {
        return totalAccounts;
    }
};

// Static member definition (must be done outside class)
int BankAccount::totalAccounts = 0;

/*
===================================================================================
                        3. ENCAPSULATION - DATA PROTECTION AND ACCESS CONTROL
===================================================================================

Encapsulation is like a protective shell around your data. It controls who can
access and modify the internal state of your objects. Think of it as the difference
between a safe (private) and a display case (public).
*/

class Student {
private: // PRIVATE - only accessible within this class
    string name;
    int studentID;
    vector<double> grades;
    
    // Private helper function - internal logic not exposed to outside
    double calculateGPA() const {
        if (grades.empty()) return 0.0;
        
        double sum = 0.0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }

protected: // PROTECTED - accessible in this class and its derived classes
    string department;
    int yearOfStudy;

public: // PUBLIC - accessible from anywhere
    // Constructor
    Student(const string& studentName, int id, const string& dept) 
        : name(studentName), studentID(id), department(dept), yearOfStudy(1) {
        // Constructor initialization list - more efficient than assignment
    }
    
    // Public interface for controlled access to private data
    void addGrade(double grade) {
        if (grade >= 0.0 && grade <= 100.0) { // Validation
            grades.push_back(grade);
            cout << "Grade " << grade << " added for " << name << "\n";
        } else {
            cout << "Invalid grade! Must be between 0 and 100.\n";
        }
    }
    
    void displayStudentInfo() const {
        cout << "Student Information:\n";
        cout << "Name: " << name << "\n";
        cout << "ID: " << studentID << "\n";
        cout << "Department: " << department << "\n";
        cout << "Year: " << yearOfStudy << "\n";
        cout << "GPA: " << calculateGPA() << "\n";
        
        cout << "Grades: ";
        for (size_t i = 0; i < grades.size(); ++i) {
            cout << grades[i];
            if (i < grades.size() - 1) cout << ", ";
        }
        cout << "\n\n";
    }
    
    // Controlled access through getters and setters
    string getName() const { return name; }
    int getStudentID() const { return studentID; }
    
    // Setter with validation
    void setYearOfStudy(int year) {
        if (year >= 1 && year <= 4) {
            yearOfStudy = year;
        } else {
            cout << "Invalid year! Must be 1-4.\n";
        }
    }
};

/*
===================================================================================
                    4. INHERITANCE - CODE REUSABILITY AND RELATIONSHIPS
===================================================================================

Inheritance allows us to create new classes based on existing ones. It's like
a family tree - children inherit traits from parents but can also have their
own unique characteristics.
*/

// BASE CLASS (Parent) - represents common characteristics
class Vehicle {
protected: // Protected allows derived classes to access these members
    string make;
    string model;
    int year;
    double speed;

public:
    // Constructor
    Vehicle(const string& vehicleMake, const string& vehicleModel, int vehicleYear)
        : make(vehicleMake), model(vehicleModel), year(vehicleYear), speed(0.0) {
        cout << "Vehicle constructor called for " << make << " " << model << "\n";
    }
    
    // Virtual destructor - important for proper cleanup in inheritance
    virtual ~Vehicle() {
        cout << "Vehicle destructor called for " << make << " " << model << "\n";
    }
    
    // Common functionality for all vehicles
    virtual void start() {
        cout << make << " " << model << " is starting...\n";
    }
    
    virtual void stop() {
        speed = 0.0;
        cout << make << " " << model << " has stopped.\n";
    }
    
    virtual void accelerate(double amount) {
        speed += amount;
        cout << make << " " << model << " accelerated to " << speed << " mph\n";
    }
    
    // Virtual function - can be overridden by derived classes
    virtual void displayInfo() const {
        cout << "Vehicle: " << make << " " << model << " (" << year << ")\n";
        cout << "Current speed: " << speed << " mph\n";
    }
    
    // Getters
    string getMake() const { return make; }
    string getModel() const { return model; }
    double getSpeed() const { return speed; }
};

// SINGLE INHERITANCE - Car inherits from Vehicle
class SportsCar : public Vehicle { // 'public' inheritance maintains access levels
private:
    bool turbocharged;
    int horsepower;

public:
    // Constructor - calls parent constructor
    SportsCar(const string& make, const string& model, int year, int hp, bool turbo = false)
        : Vehicle(make, model, year), horsepower(hp), turbocharged(turbo) {
        cout << "SportsCar constructor called\n";
    }
    
    // Destructor
    ~SportsCar() {
        cout << "SportsCar destructor called\n";
    }
    
    // Override parent function - specialized behavior
    void accelerate(double amount) override {
        if (turbocharged) {
            amount *= 1.5; // Turbo boost!
            cout << "Turbo engaged! ";
        }
        Vehicle::accelerate(amount); // Call parent version
    }
    
    // New functionality specific to sports cars
    void activateNitro() {
        if (turbocharged) {
            speed += 50;
            cout << "NITRO ACTIVATED! Speed boosted to " << speed << " mph!\n";
        } else {
            cout << "No nitro system available.\n";
        }
    }
    
    // Override displayInfo
    void displayInfo() const override {
        cout << "Sports Car: " << make << " " << model << " (" << year << ")\n";
        cout << "Horsepower: " << horsepower << " HP\n";
        cout << "Turbocharged: " << (turbocharged ? "Yes" : "No") << "\n";
        cout << "Current speed: " << speed << " mph\n";
    }
};

// Another derived class demonstrating inheritance
class Truck : public Vehicle {
private:
    double cargoCapacity; // in tons
    double currentLoad;

public:
    Truck(const string& make, const string& model, int year, double capacity)
        : Vehicle(make, model, year), cargoCapacity(capacity), currentLoad(0.0) {
        cout << "Truck constructor called\n";
    }
    
    ~Truck() {
        cout << "Truck destructor called\n";
    }
    
    // Trucks accelerate differently when loaded
    void accelerate(double amount) override {
        double loadFactor = 1.0 - (currentLoad / cargoCapacity) * 0.5;
        amount *= loadFactor;
        Vehicle::accelerate(amount);
        cout << "Load factor: " << loadFactor << " (Current load: " << currentLoad << " tons)\n";
    }
    
    void loadCargo(double weight) {
        if (currentLoad + weight <= cargoCapacity) {
            currentLoad += weight;
            cout << "Loaded " << weight << " tons. Current load: " << currentLoad << " tons\n";
        } else {
            cout << "Cannot load " << weight << " tons. Exceeds capacity!\n";
        }
    }
    
    void displayInfo() const override {
        cout << "Truck: " << make << " " << model << " (" << year << ")\n";
        cout << "Cargo capacity: " << cargoCapacity << " tons\n";
        cout << "Current load: " << currentLoad << " tons\n";
        cout << "Current speed: " << speed << " mph\n";
    }
};

/*
===================================================================================
                        5. MULTIPLE INHERITANCE EXAMPLE
===================================================================================

Multiple inheritance allows a class to inherit from multiple base classes.
It's like having traits from both parents in biology.
*/

// First base class
class Engine {
protected:
    int cylinders;
    double displacement;

public:
    Engine(int cyl, double disp) : cylinders(cyl), displacement(disp) {
        cout << "Engine constructor: " << cylinders << " cylinders, " << displacement << "L\n";
    }
    
    virtual ~Engine() {
        cout << "Engine destructor called\n";
    }
    
    virtual void startEngine() {
        cout << "Engine with " << cylinders << " cylinders started\n";
    }
    
    void getEngineSpecs() const {
        cout << "Engine: " << cylinders << " cylinders, " << displacement << "L displacement\n";
    }
};

// Second base class
class Electronics {
protected:
    bool hasGPS;
    bool hasBluetoothconnect;

public:
    Electronics(bool gps = false, bool bluetooth = false) 
        : hasGPS(gps), hasBluetoothconnect(bluetooth) {
        cout << "Electronics constructor called\n";
    }
    
    virtual ~Electronics() {
        cout << "Electronics destructor called\n";
    }
    
    void enableGPS() {
        hasGPS = true;
        cout << "GPS navigation enabled\n";
    }
    
    void connectBluetooth() {
        hasBluetoothconnect = true;
        cout << "Bluetooth connected\n";
    }
    
    void getElectronicsInfo() const {
        cout << "Electronics: GPS=" << (hasGPS ? "Yes" : "No") 
                  << ", Bluetooth=" << (hasBluetoothconnect ? "Yes" : "No") << "\n";
    }
};

// MULTIPLE INHERITANCE - inherits from both Engine and Electronics
class ModernCar : public Engine, public Electronics {
private:
    string brand;
    string model;

public:
    // Constructor must initialize all base classes
    ModernCar(const string& b, const string& m, int cyl, double disp, bool gps, bool bt)
        : Engine(cyl, disp), Electronics(gps, bt), brand(b), model(m) {
        cout << "ModernCar constructor called for " << brand << " " << model << "\n";
    }
    
    ~ModernCar() {
        cout << "ModernCar destructor called\n";
    }
    
    // Can use functionality from both base classes
    void startCar() {
        cout << "Starting " << brand << " " << model << "...\n";
        startEngine(); // From Engine class
        if (hasGPS) {
            cout << "GPS system initialized\n";
        }
        if (hasBluetoothconnect) {
            cout << "Bluetooth ready for pairing\n";
        }
    }
    
    void displayCarInfo() const {
        cout << "Car: " << brand << " " << model << "\n";
        getEngineSpecs(); // From Engine class
        getElectronicsInfo(); // From Electronics class
    }
};

/*
===================================================================================
                        6. POLYMORPHISM - FUNCTION AND OPERATOR OVERLOADING
===================================================================================

Polymorphism means "many forms." It allows the same interface to be used for
different underlying data types or classes. Like how the '+' operator works
for both integers and strings.
*/

// Class demonstrating operator overloading
class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructors
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}
    
    // Copy constructor
    Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {}
    
    // OPERATOR OVERLOADING - giving new meaning to operators for our class
    
    // Addition operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    
    // Subtraction operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }
    
    // Multiplication operator
    Complex operator*(const Complex& other) const {
        double newReal = real * other.real - imaginary * other.imaginary;
        double newImag = real * other.imaginary + imaginary * other.real;
        return Complex(newReal, newImag);
    }
    
    // Assignment operator
    Complex& operator=(const Complex& other) {
        if (this != &other) { // Avoid self-assignment
            real = other.real;
            imaginary = other.imaginary;
        }
        return *this;
    }
    
    // Comparison operator
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imaginary == other.imaginary);
    }
    
    // Stream insertion operator (for cout)
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imaginary >= 0) os << " + ";
        else os << " - ";
        os << abs(c.imaginary) << "i";
        return os;
    }
    
    // Stream extraction operator (for cin)
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imaginary;
        return is;
    }
    
    // Prefix increment
    Complex& operator++() {
        ++real;
        ++imaginary;
        return *this;
    }
    
    // Postfix increment
    Complex operator++(int) {
        Complex temp(*this);
        ++real;
        ++imaginary;
        return temp;
    }
    
    // Function call operator - makes object callable like a function
    double operator()() const {
        return sqrt(real * real + imaginary * imaginary); // Magnitude
    }
    
    // Getters
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
};

// FUNCTION OVERLOADING - same function name, different parameters
class Calculator {
public:
    // Different versions of add function
    int add(int a, int b) {
        cout << "Adding two integers: ";
        return a + b;
    }
    
    double add(double a, double b) {
        cout << "Adding two doubles: ";
        return a + b;
    }
    
    int add(int a, int b, int c) {
        cout << "Adding three integers: ";
        return a + b + c;
    }
    
    // Function can be overloaded with different parameter types
    string add(const string& a, const string& b) {
        cout << "Concatenating strings: ";
        return a + b;
    }
};

/*
===================================================================================
                        7. VIRTUAL FUNCTIONS AND POLYMORPHISM
===================================================================================

Virtual functions enable runtime polymorphism. They allow a program to decide
which function to call based on the actual object type, not the pointer type.
Think of it as calling the right specialist based on the actual problem, not
the general category.
*/

// Base class for shape hierarchy
class Shape {
protected:
    string color;

public:
    Shape(const string& c) : color(c) {
        cout << "Shape constructor called\n";
    }
    
    // Virtual destructor - crucial for proper cleanup
    virtual ~Shape() {
        cout << "Shape destructor called\n";
    }
    
    // Virtual function - can be overridden by derived classes
    virtual double area() const {
        cout << "Shape::area() - This should be overridden\n";
        return 0.0;
    }
    
    virtual double perimeter() const {
        cout << "Shape::perimeter() - This should be overridden\n";
        return 0.0;
    }
    
    // Virtual function for displaying shape info
    virtual void display() const {
        cout << "Shape with color: " << color << "\n";
    }
    
    // Non-virtual function - cannot be overridden (but can be hidden)
    void setColor(const string& c) {
        color = c;
    }
    
    string getColor() const { return color; }
};

// Derived class - Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r, const string& color) : Shape(color), radius(r) {
        cout << "Circle constructor called\n";
    }
    
    ~Circle() override { // 'override' keyword ensures we're actually overriding
        cout << "Circle destructor called\n";
    }
    
    // Override virtual functions
    double area() const override {
        return 3.14159 * radius * radius;
    }
    
    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
    
    void display() const override {
        cout << "Circle with radius " << radius << " and color " << color << "\n";
        cout << "Area: " << area() << ", Perimeter: " << perimeter() << "\n";
    }
    
    double getRadius() const { return radius; }
};

// Another derived class - Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h, const string& color) 
        : Shape(color), width(w), height(h) {
        cout << "Rectangle constructor called\n";
    }
    
    ~Rectangle() override {
        cout << "Rectangle destructor called\n";
    }
    
    double area() const override {
        return width * height;
    }
    
    double perimeter() const override {
        return 2 * (width + height);
    }
    
    void display() const override {
        cout << "Rectangle " << width << "x" << height << " with color " << color << "\n";
        cout << "Area: " << area() << ", Perimeter: " << perimeter() << "\n";
    }
};

// Triangle class
class Triangle : public Shape {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3, const string& color)
        : Shape(color), side1(s1), side2(s2), side3(s3) {
        cout << "Triangle constructor called\n";
    }
    
    ~Triangle() override {
        cout << "Triangle destructor called\n";
    }
    
    double area() const override {
        // Using Heron's formula
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    
    double perimeter() const override {
        return side1 + side2 + side3;
    }
    
    void display() const override {
        cout << "Triangle with sides " << side1 << ", " << side2 << ", " << side3 
                  << " and color " << color << "\n";
        cout << "Area: " << area() << ", Perimeter: " << perimeter() << "\n";
    }
};

/*
===================================================================================
                        8. ABSTRACT CLASSES AND PURE VIRTUAL FUNCTIONS
===================================================================================

Abstract classes cannot be instantiated directly. They serve as interfaces or
contracts that derived classes must follow. Think of them as job descriptions -
they define what must be done, but not how to do it.
*/

// Abstract base class - contains pure virtual functions
class Animal { // This class CANNOT be instantiated
protected:
    string name;
    int age;

public:
    Animal(const string& n, int a) : name(n), age(a) {
        cout << "Animal constructor called for " << name << "\n";
    }
    
    virtual ~Animal() {
        cout << "Animal destructor called for " << name << "\n";
    }
    
    // PURE VIRTUAL FUNCTIONS - must be implemented by derived classes
    virtual void makeSound() const = 0; // "= 0" makes it pure virtual
    virtual void move() const = 0;
    virtual void eat(const string& food) const = 0;
    
    // Regular virtual function - can be overridden but has default implementation
    virtual void sleep() const {
        cout << name << " is sleeping peacefully...\n";
    }
    
    // Non-virtual function - common to all animals
    void displayBasicInfo() const {
        cout << "Animal: " << name << ", Age: " << age << " years\n";
    }
    
    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
};

// Concrete derived class - must implement all pure virtual functions
class Dog : public Animal {
private:
    string breed;

public:
    Dog(const string& name, int age, const string& b) 
        : Animal(name, age), breed(b) {
        cout << "Dog constructor called\n";
    }
    
    ~Dog() override {
        cout << "Dog destructor called\n";
    }
    
    // MUST implement all pure virtual functions
    void makeSound() const override {
        cout << name << " says: Woof! Woof!\n";
    }
    
    void move() const override {
        cout << name << " runs around happily, tail wagging!\n";
    }
    
    void eat(const string& food) const override {
        cout << name << " eagerly eats " << food << " from the bowl!\n";
    }
    
    // Can override regular virtual functions too
    void sleep() const override {
        cout << name << " curls up in a cozy spot and dreams of chasing squirrels...\n";
    }
    
    // Dog-specific functionality
    void fetch() const {
        cout << name << " fetches the ball and brings it back!\n";
    }
    
    void displayInfo() const {
        displayBasicInfo();
        cout << "Breed: " << breed << "\n";
    }
};

class Cat : public Animal {
private:
    bool isIndoor;

public:
    Cat(const string& name, int age, bool indoor = true) 
        : Animal(name, age), isIndoor(indoor) {
        cout << "Cat constructor called\n";
    }
    
    ~Cat() override {
        cout << "Cat destructor called\n";
    }
    
    void makeSound() const override {
        cout << name << " says: Meow! Purr...\n";
    }
    
    void move() const override {
        if (isIndoor) {
            cout << name << " gracefully prowls around the house\n";
        } else {
            cout << name << " stealthily moves through the garden\n";
        }
    }
    
    void eat(const string& food) const override {
        cout << name << " delicately nibbles on " << food << "\n";
    }
    
    void sleep() const override {
        cout << name << " finds the sunniest spot and naps for 16 hours...\n";
    }
    
    // Cat-specific behavior
    void climb() const {
        cout << name << " climbs up to a high perch and surveys the territory\n";
    }
};

// Another abstract class for demonstration
class Bird : public Animal {
public:
    Bird(const string& name, int age) : Animal(name, age) {}
    
    virtual ~Bird() override = default;
    
    // Implementing some pure virtual functions
    void move() const override {
        cout << name << " spreads wings and flies gracefully\n";
    }
    
    void eat(const string& food) const override {
        cout << name << " pecks at " << food << "\n";
    }
    
    // Still abstract - derived classes must implement makeSound
    virtual void makeSound() const = 0;
    
    // Bird-specific virtual function
    virtual void fly() const {
        cout << name << " soars through the sky\n";
    }
};

class Eagle : public Bird {
public:
    Eagle(const string& name, int age) : Bird(name, age) {
        cout << "Eagle constructor called\n";
    }
    
    ~Eagle() override {
        cout << "Eagle destructor called\n";
    }
    
    void makeSound() const override {
        cout << name << " lets out a powerful screech: SCREEEECH!\n";
    }
    
    void fly() const override {
        cout << name << " soars majestically at great heights, hunting for prey\n";
    }
    
    void hunt() const {
        cout << name << " dives down at incredible speed to catch prey!\n";
    }
};

/*
===================================================================================
                        9. ADVANCED OOP CONCEPTS
===================================================================================
*/

// INTERFACE CLASS - purely abstract class with only pure virtual functions
class Drawable {
public:
    virtual ~Drawable() = default;
    virtual void draw() const = 0;
    virtual void resize(double factor) = 0;
    virtual void move(double x, double y) = 0;
};

class Printable {
public:
    virtual ~Printable() = default;
    virtual void print() const = 0;
    virtual void save(const string& filename) const = 0;
};

// Multiple inheritance from interfaces
class Document : public Drawable, public Printable {
private:
    string content;
    double x, y; // position
    double width, height; // dimensions

public:
    Document(const string& text, double w, double h) 
        : content(text), x(0), y(0), width(w), height(h) {}
    
    // Implement Drawable interface
    void draw() const override {
        cout << "Drawing document at (" << x << ", " << y << ") "
                  << "with size " << width << "x" << height << "\n";
        cout << "Content: " << content.substr(0, 50) << "...\n";
    }
    
    void resize(double factor) override {
        width *= factor;
        height *= factor;
        cout << "Document resized by factor " << factor 
                  << " to " << width << "x" << height << "\n";
    }
    
    void move(double newX, double newY) override {
        x = newX;
        y = newY;
        cout << "Document moved to (" << x << ", " << y << ")\n";
    }
    
    // Implement Printable interface
    void print() const override {
        cout << "Printing document...\n";
        cout << "Content: " << content << "\n";
    }
    
    void save(const string& filename) const override {
        cout << "Saving document to " << filename << "\n";
        // In real implementation, would write to file
    }
};

// TEMPLATE CLASS - generic programming (brief example)
template<typename T>
class Container {
private:
    vector<T> items;

public:
    void add(const T& item) {
        items.push_back(item);
        cout << "Added item to container\n";
    }
    
    T get(int index) const {
        if (index >= 0 && index < items.size()) {
            return items[index];
        }
        throw out_of_range("Index out of range");
    }
    
    int size() const {
        return items.size();
    }
    
    void displayAll() const {
        cout << "Container contents:\n";
        for (size_t i = 0; i < items.size(); ++i) {
            cout << "  [" << i << "]: " << items[i] << "\n";
        }
    }
};

// FRIEND CLASSES AND FUNCTIONS demonstration
class PrivateData {
private:
    int secretValue;
    string confidentialInfo;

public:
    PrivateData(int val, const string& info) 
        : secretValue(val), confidentialInfo(info) {}
    
    // Friend function can access private members
    friend void displayPrivateData(const PrivateData& obj);
    
    // Friend class declaration
    friend class DataAnalyzer;
    
    // Regular public method
    void displayPublic() const {
        cout << "This is public information only\n";
    }
};

// Friend function definition
void displayPrivateData(const PrivateData& obj) {
    cout << "Secret Value: " << obj.secretValue << "\n";
    cout << "Confidential Info: " << obj.confidentialInfo << "\n";
}

// Friend class can access all private members of PrivateData
class DataAnalyzer {
public:
    void analyzeData(const PrivateData& data) {
        cout << "Analyzing private data...\n";
        cout << "Secret value is: " << data.secretValue << "\n";
        cout << "Confidential info length: " << data.confidentialInfo.length() << "\n";
        
        // Can perform operations on private data
        if (data.secretValue > 100) {
            cout << "High value detected!\n";
        }
    }
};

/*
===================================================================================
                        10. DEMONSTRATION FUNCTIONS
===================================================================================
*/

// Function to demonstrate polymorphism with shapes
void demonstratePolymorphism() {
    cout << "\n" << string(60, '=') << "\n";
    cout << "POLYMORPHISM DEMONSTRATION\n";
    cout << string(60, '=') << "\n";
    
    // Create array of Shape pointers pointing to different derived objects
    vector<unique_ptr<Shape>> shapes;
    
    shapes.push_back(make_unique<Circle>(5.0, "Red"));
    shapes.push_back(make_unique<Rectangle>(4.0, 6.0, "Blue"));
    shapes.push_back(make_unique<Triangle>(3.0, 4.0, 5.0, "Green"));
    
    // Polymorphic behavior - same function call, different implementations
    cout << "\nDisplaying all shapes polymorphically:\n";
    for (const auto& shape : shapes) {
        shape->display(); // Calls the appropriate derived class method
        cout << "---\n";
    }
    
    // Calculate total area
    double totalArea = 0.0;
    for (const auto& shape : shapes) {
        totalArea += shape->area(); // Polymorphic call
    }
    cout << "Total area of all shapes: " << totalArea << "\n";
}

// Function to demonstrate abstract classes and interfaces
void demonstrateAbstractClasses() {
    cout << "\n" << string(60, '=') << "\n";
    cout << "ABSTRACT CLASSES DEMONSTRATION\n";
    cout << string(60, '=') << "\n";
    
    // Cannot instantiate abstract class:
    // Animal animal("Generic", 5); // This would cause compilation error!
    
    // Create concrete objects
    vector<unique_ptr<Animal>> animals;
    animals.push_back(make_unique<Dog>("Buddy", 3, "Golden Retriever"));
    animals.push_back(make_unique<Cat>("Whiskers", 2, true));
    animals.push_back(make_unique<Eagle>("Storm", 5));
    
    cout << "\nAnimal behaviors:\n";
    for (const auto& animal : animals) {
        animal->displayBasicInfo();
        animal->makeSound();
        animal->move();
        animal->eat("food");
        animal->sleep();
        cout << "---\n";
    }
    
    // Demonstrate specific behaviors
    cout << "\nSpecific animal behaviors:\n";
    Dog* dog = dynamic_cast<Dog*>(animals[0].get());
    if (dog) {
        dog->fetch();
    }
    
    Cat* cat = dynamic_cast<Cat*>(animals[1].get());
    if (cat) {
        cat->climb();
    }
    
    Eagle* eagle = dynamic_cast<Eagle*>(animals[2].get());
    if (eagle) {
        eagle->hunt();
    }
}

// Function to demonstrate operator overloading
void demonstrateOperatorOverloading() {
    cout << "\n" << string(60, '=') << "\n";
    cout << "OPERATOR OVERLOADING DEMONSTRATION\n";
    cout << string(60, '=') << "\n";
    
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    
    cout << "Complex number 1: " << c1 << "\n";
    cout << "Complex number 2: " << c2 << "\n";
    
    // Using overloaded operators
    Complex c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << "\n";
    
    Complex c4 = c1 - c2;
    cout << "c1 - c2 = " << c4 << "\n";
    
    Complex c5 = c1 * c2;
    cout << "c1 * c2 = " << c5 << "\n";
    
    // Increment operators
    cout << "Original c1: " << c1 << "\n";
    ++c1; // Prefix
    cout << "After ++c1: " << c1 << "\n";
    
    Complex c6 = c2++; // Postfix
    cout << "c2++ returned: " << c6 << ", c2 is now: " << c2 << "\n";
    
    // Function call operator
    cout << "Magnitude of c1: " << c1() << "\n";
    
    // Comparison
    Complex c7(3.0, 4.0);
    cout << "c1 == c7: " << (c1 == c7 ? "true" : "false") << "\n";
}

// Function to demonstrate all concepts
void demonstrateAllConcepts() {
    cout << "\n" << string(80, '=') << "\n";
    cout << "              COMPREHENSIVE C++ OOP DEMONSTRATION\n";
    cout << string(80, '=') << "\n";
    
    // 1. Basic class usage
    cout << "\n1. BASIC CLASSES AND OBJECTS:\n";
    Car myCar;
    myCar.setBrand("Toyota");
    myCar.setModel("Camry");
    myCar.setYear(2022);
    myCar.displayInfo();
    myCar.startEngine();
    myCar.stopEngine();
    
    // 2. Constructors and destructors
    cout << "\n2. CONSTRUCTORS AND DESTRUCTORS:\n";
    {
        BankAccount account1; // Default constructor
        BankAccount account2("John Doe", "1234567890", 1000.0); // Parameterized
        BankAccount account3(account2); // Copy constructor
        
        account2.deposit(500);
        account2.withdraw(200);
        account2.displayAccount();
        
        cout << "Total accounts: " << BankAccount::getTotalAccounts() << "\n";
    } // Destructors called here when objects go out of scope
    
    cout << "Accounts after scope: " << BankAccount::getTotalAccounts() << "\n";
    
    // 3. Encapsulation
    cout << "\n3. ENCAPSULATION:\n";
    Student student("Alice Johnson", 12345, "Computer Science");
    student.addGrade(85.5);
    student.addGrade(92.0);
    student.addGrade(78.5);
    student.displayStudentInfo();
    
    // 4. Inheritance
    cout << "\n4. INHERITANCE:\n";
    SportsCar ferrari("Ferrari", "458 Italia", 2023, 562, true);
    ferrari.displayInfo();
    ferrari.start();
    ferrari.accelerate(30);
    ferrari.activateNitro();
    
    cout << "\n";
    Truck truck("Ford", "F-150", 2023, 2.5);
    truck.loadCargo(1.0);
    truck.accelerate(20);
    
    // 5. Multiple inheritance
    cout << "\n5. MULTIPLE INHERITANCE:\n";
    ModernCar modernCar("BMW", "X5", 6, 3.0, true, true);
    modernCar.startCar();
    modernCar.displayCarInfo();
    
    // 6. Function overloading
    cout << "\n6. FUNCTION OVERLOADING:\n";
    Calculator calc;
    cout << calc.add(5, 3) << "\n";
    cout << calc.add(2.5, 3.7) << "\n";
    cout << calc.add(1, 2, 3) << "\n";
    cout << calc.add(string("Hello"), string(" World")) << "\n";
    
    // 7. Polymorphism demonstration
    demonstratePolymorphism();
    
    // 8. Abstract classes demonstration  
    demonstrateAbstractClasses();
    
    // 9. Operator overloading demonstration
    demonstrateOperatorOverloading();
    
    // 10. Interface demonstration
    cout << "\n" << string(60, '=') << "\n";
    cout << "INTERFACE DEMONSTRATION\n";
    cout << string(60, '=') << "\n";
    
    Document doc("This is a sample document with some content.", 210, 297);
    doc.draw();
    doc.resize(1.5);
    doc.move(100, 150);
    doc.print();
    doc.save("document.txt");
    
    // 11. Template demonstration
    cout << "\n" << string(60, '=') << "\n";
    cout << "TEMPLATE DEMONSTRATION\n";
    cout << string(60, '=') << "\n";
    
    Container<int> intContainer;
    intContainer.add(10);
    intContainer.add(20);
    intContainer.add(30);
    intContainer.displayAll();
    
    Container<string> stringContainer;
    stringContainer.add("Hello");
    stringContainer.add("World");
    stringContainer.displayAll();
    
    // 12. Friend functions and classes
    cout << "\n" << string(60, '=') << "\n";
    cout << "FRIEND FUNCTIONS AND CLASSES DEMONSTRATION\n";
    cout << string(60, '=') << "\n";
    
    PrivateData secretData(42, "Top Secret Information");
    secretData.displayPublic();
    
    displayPrivateData(secretData); // Friend function
    
    DataAnalyzer analyzer;
    analyzer.analyzeData(secretData); // Friend class
    
    cout << "\n" << string(80, '=') << "\n";
    cout << "              DEMONSTRATION COMPLETE!\n";
    cout << string(80, '=') << "\n";
}

/*
===================================================================================
                        11. MAIN FUNCTION - PROGRAM ENTRY POINT
===================================================================================
*/

int main() {
    try {
        cout << "Welcome to the Comprehensive C++ OOP Tutorial!\n";
        cout << "This program demonstrates all major OOP concepts in C++.\n";
        
        // Run all demonstrations
        demonstrateAllConcepts();
        
        return 0;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}

/*
===================================================================================
                        SUMMARY OF KEY OOP CONCEPTS COVERED
===================================================================================

1. CLASSES AND OBJECTS:
   - Blueprint vs instances
   - Member variables and functions
   - Access specifiers (public, private, protected)

2. CONSTRUCTORS AND DESTRUCTORS:
   - Default, parameterized, copy constructors
   - Constructor initialization lists
   - Destructor cleanup
   - Static members

3. ENCAPSULATION:
   - Data hiding with access specifiers
   - Getter and setter functions
   - Data validation and controlled access

4. INHERITANCE:
   - Single inheritance (is-a relationship)
   - Multiple inheritance
   - Protected access specifier
   - Constructor/destructor chaining
   - Method overriding

5. POLYMORPHISM:
   - Function overloading (compile-time)
   - Operator overloading
   - Virtual functions (runtime polymorphism)

6. VIRTUAL FUNCTIONS:
   - Late binding/dynamic dispatch
   - Virtual destructors
   - Override keyword for safety

7. ABSTRACT CLASSES:
   - Pure virtual functions (= 0)
   - Interface design
   - Cannot instantiate abstract classes
   - Contract for derived classes

8. ADVANCED CONCEPTS:
   - Friend functions and classes
   - Template basics
   - Multiple inheritance from interfaces
   - Dynamic casting
   - Smart pointers (unique_ptr)

===================================================================================
                        BEST PRACTICES DEMONSTRATED
===================================================================================

1. Always use virtual destructors in base classes
2. Use 'override' keyword for clarity and safety  
3. Prefer initialization lists in constructors
4. Make member functions const when they don't modify state
5. Use smart pointers for automatic memory management
6. Follow RAII (Resource Acquisition Is Initialization)
7. Keep interfaces minimal and focused
8. Use meaningful names for classes and functions
9. Validate input in setter functions
10. Separate interface from implementation

===================================================================================
                        COMPILATION INSTRUCTIONS
===================================================================================

To compile and run this program:

1. Save as 'oop_tutorial.cpp'
2. Compile: g++ -std=c++14 -Wall -Wextra -o oop_tutorial oop_tutorial.cpp
3. Run: ./oop_tutorial

Requirements:
- C++14 or later
- Standard library support

This program demonstrates practical usage of all major OOP concepts.
Study each section carefully and experiment with modifications!

===================================================================================
*/