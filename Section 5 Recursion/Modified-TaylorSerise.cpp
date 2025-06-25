/* Modified taylor serise e to the power x*/
#include <iostream>
using namespace std;

/*Using Recursion*/
double e(int x , int n){
    static double S = 1;
    if(n==0) return S;
    S = 1 + (x*S/n);
    return e(x,n-1);
}

/*Using loop*/
double e_loop(int x , int n){
    double S = 1;
    for( ; n > 0 ; n--){
        S = 1 + (x*S/n); 
    }
    return S;
}

int main(int argc, char const *argv[])
{
    double result = e(1,10);
    cout << result << endl;
    return 0;
}
