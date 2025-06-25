#include <iostream>
using namespace std ;

// Recursive function

int RecursiveSum(int n){
    if(n==0) return 0;
    return RecursiveSum(n-1) + n;
}

// Itaretive function

int sum(int n){
    int i,sum = 0;
    for(i=1;i<=n;i++){
        sum += i;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int recursiveSum = RecursiveSum(10);
    int result = sum(10);

    cout << recursiveSum << endl;
    cout << result << endl;
    return 0;
}
