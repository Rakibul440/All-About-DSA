/*To avoid excessive recursion*/

#include <iostream>
using namespace std;

int F[10];

int fib(int n){
    if(n <= 1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2]==0){
            F[n-2] = fib(n-2);
        }
        if(F[n-1]==0){
            F[n-1] = fib(n-1);
        }
        return F[n-2] + F[n-1];
    }

}

int main(){
    int nth_term = fib(11);
    cout << nth_term << endl;

    /*Printing all the terms of serise*/
    F[11] = nth_term;
    for (int i = 0; i < 12; i++)
    {
        cout << F[i] << "\t";
    }
    
    return 0;
}