#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = 4 , b = 8;
    cout << (a & b) << endl; // & oparetor
    cout << (a | b) <<endl ; // | oparetor
    cout << (a ^ b) <<endl ; // ^ (XOR) oparetor

    cout << (10 << 2) <<endl ; // << left shift oparetor
    /*
    a << b == [a * (2 ^ b)]
    */
    cout << (10 >> 1) <<endl ; // >> Right shift oparetor
    /*
    a >> b == [a / (2 ^ b)]
    */

    return 0;
}
