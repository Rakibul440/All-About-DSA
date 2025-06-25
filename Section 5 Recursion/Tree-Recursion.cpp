#include <iostream>
using namespace std;

void func(int n){
    if(n>0){
        cout << n << " " ;
        func(n-1);
        func(n-1);
    }
}

int main(int argc, char const *argv[])
{
    func(3);
    return 0;
}
