#include <iostream>
// #include "list.h"

using namespace std;


bool isPrime(int x){
    if(x<=1) return false;
    for(int i = 2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }

    return true;
}

int prevPrime(int x){
    
    if(x<=2) return -1;

    int prime = x-1;
    while(!isPrime(prime)){
        prime--;
    }

    return prime;
}

int main(){

    cout << prevPrime(90);

    return 0;
}