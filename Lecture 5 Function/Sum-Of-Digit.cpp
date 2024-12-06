#include <iostream>
using namespace std;

/* Tips int number % 10 = last digit , Ex: 169 % 10 = 9 
    And int number / 10 = number without last digit , Ex : 169/10 = 16(int)
*/
int sum_of_digit(int number) {
    int sumOfDigit = 0;
    while(number > 0){
        int last_digit = number % 10;
        int left_digit = number / 10;
        number = left_digit;
        sumOfDigit += last_digit;
    }
    return sumOfDigit;
}

int main(int argc, char const *argv[])
{
    int number ;
    cout << "Enter a number : ";
    cin >> number ;

    int result = sum_of_digit(number);
    cout << "Sum of the digit of " << number << " is : " << result ;
    return 0;
}
