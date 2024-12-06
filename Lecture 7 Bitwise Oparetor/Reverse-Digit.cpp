#include <iostream>
using namespace std;

int reverse_digit(int number);
int find_total_digit(int number);

int main(int argc, char const *argv[])
{
    cout <<"\n------Print Reverse Of A Digit-------\n" <<endl;
    cout << "Enter an positive integer number : ";
    int number ;
    cin >> number;
 
    int reverse_number = reverse_digit (number);
    cout << "Reverse of " << number << " is : " << reverse_number<<endl;
    return 0;
}

int reverse_digit(int number) {
    int last_digit,reverse_number = 0;
    int total_digit = find_total_digit(number);
    int power = 1,i;

    for(i = 1;i<total_digit; i ++){
        power *= 10;
    }

    while (number > 0){
        last_digit = number % 10;
        reverse_number += (last_digit * power);
        number /= 10;
        power /= 10;
    }


    return reverse_number;
}

int find_total_digit(int number){
    int last_digit, total_digit = 0;
    while(number > 0){
        last_digit = number  % 10;
        total_digit ++;
        number /= 10;
    }

    return total_digit;
}