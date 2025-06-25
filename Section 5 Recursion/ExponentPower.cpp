#include <iostream>
using namespace std;

/*m to the power n*/

int pow(int m , int n){
    if(n==0){
        return 1;
    }
    return pow(m,n-1) * m;
}

/*Improve exponent opp for less opperation*/

int modifiedPow(int m, int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return modifiedPow(m*m,n/2);
    }
    return m*modifiedPow(m*m,(n-1)/2);
}

int main()
{
    int powResult = pow(2,10);
    int modPowResult = modifiedPow(2,10);

    cout << powResult << "\n" << modPowResult << endl;
    return 0;
}
