#include <iostream>
using namespace std;

int factorial(int n);
int LnCr(int n , int r);

/*Recursion*/
int RnCr(int n, int r){
    if(n == r || r == 0){
        return 1;
    }
    return (RnCr(n-1,r-1) + RnCr(n-1,r));
}

int main(){
    int Rresult = RnCr(4,2);
    cout << Rresult << endl;
    return 0;
}


int factorial(int n){
    if(n==0){
        return 1;
    }
    return factorial(n-1) * n;
}

int LnCr(int n, int r){
    int num , den ;

    num = factorial(n);
    den = factorial(r) * factorial(n-r);

    return num / den;
}