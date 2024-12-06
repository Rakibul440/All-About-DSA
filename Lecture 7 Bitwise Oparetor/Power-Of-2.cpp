#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    
    cout <<"\n------Check Power Of 2 Or Not-------\n" <<endl;
    cout << "Enter an positive integer number : ";
    int number ;
    cin >> number;

    if(number > 0 && (number & (number - 1)) == 0 ){
        cout << number << " is power of 2" << endl;
    }else{
        cout << number << " is not power of 2" << endl;
    }
    return 0;
}
