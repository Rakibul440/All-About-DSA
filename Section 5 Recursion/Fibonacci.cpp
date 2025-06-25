#include <iostream>
using namespace std;

/*Using Loop*/
int Lfib(int n){
    int t0 = 0 , t1 = 1, sum = 0;
    if(n<=1){
        return n;
    }
    for(int i = 2; i<=n ;i++){
        sum = t0 + t1 ;
        t0 = t1;
        t1 = sum;
    }
    return sum;
}

/* Using Recursion*/
int Rfib(int n){
    if(n<=1){
        return n;
    }
    return Rfib(n-2) + Rfib(n-1);
}

int main(){
    int nth_term =Rfib(5);
    cout << nth_term << endl;
    return 0;
}