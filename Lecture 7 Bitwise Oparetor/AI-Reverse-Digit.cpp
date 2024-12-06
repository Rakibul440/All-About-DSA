#include <iostream>

int reverseNumber(int num) {
    int reverse = 0;
    while (num != 0) {
        int remainder = num % 10;
        reverse = (reverse * 10) + remainder;
        num /= 10;
    }
    return reverse;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Reverse: " << reverseNumber(num) << std::endl;
    return 0;
}