#include <iostream>
using namespace std;

int decimal(int binary_num);

int main(int argc, char const *argv[])
{
    cout << "\n------Convert Binary To Decimal-------\n" << endl;
    int binary_num;
    cout << "Enter a decimal number : ";
    cin >> binary_num;

    int decimal_num = decimal(binary_num);
    cout << "Decimal of "<< binary_num << " is : "<< decimal_num ;
    return 0;
}

int decimal(int binary_num){
    int pow = 1,last_digit,decimal_num = 0;

    while(binary_num > 0){
        last_digit = binary_num % 10;
        decimal_num += (last_digit * pow);

        binary_num = binary_num / 10;
        pow *= 2;
    }

    return decimal_num;
}