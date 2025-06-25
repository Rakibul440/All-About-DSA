#include <iostream>
using namespace std;

/*Taylor serise of e to the power x*/
double e(int x, int n){
    static double P = 1, F = 1;
    double result;

    if(n==0) return 1;
    else{
        result = e(x,n-1);
        P = P*x;
        F = F*n;
        return result + (P/F);
    }
}

int main(){
    double result = e(3,10);
    cout << result ;
    return 0;
}