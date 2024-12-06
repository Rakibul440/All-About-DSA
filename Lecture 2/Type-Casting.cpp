#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    double price = 10.256;
    //Want to store double(8 byte) into int(4 byte) -- convert double to int
    int newPrice = (int)price;
    cout << newPrice;
    return 0;
}
