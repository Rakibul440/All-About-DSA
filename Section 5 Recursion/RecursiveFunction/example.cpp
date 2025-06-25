#include <iostream>
using namespace std;

void func1(int n);
void func2(int n);

int main(int argc, char const *argv[])
{
    int x = 3;
    func2(x);
    return 0;

}

void func1(int n){
    if(n>0){
        func1(n-1);
        cout << n << " " ;
    }
}

void func2(int n){
    if(n>0){
        cout<< n << " ";
        func2(n-1);
    }
}