#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    return factorial(n-1)*n;
}

int main(int argc, char const *argv[])
{
    int result = factorial(6);
    cout << result << endl;
    return 0;
}
