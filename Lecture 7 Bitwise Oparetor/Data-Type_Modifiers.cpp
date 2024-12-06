#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* 
    1. long
    2. short
    3. long long
    4. signed (+/-)
    5. unsigned (+ only)
    
    */
    cout << (sizeof(int)) << " Byte" << endl;
    cout << (sizeof(long int)) << " Byte" << endl;
    cout << (sizeof(long long int)) << " Byte" << endl;
    cout << (sizeof(short int)) << " Byte" << endl;


    return 0;
}
