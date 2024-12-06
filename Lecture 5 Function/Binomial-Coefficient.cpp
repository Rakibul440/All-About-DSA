#include <iostream>
using namespace std;

/*Q. Calculate nCr = ?*/

int factorial(int number){
    int result = 1,i;
    for(i=1;i<=number;i++){
        result *= i;
    }
    return result;
}

double valu_Of_cofficient(int n, int r){
    int factorial_n = factorial(n);
    int factorial_r = factorial(r);
    int factorial_diff = factorial(n-r);

    double value = factorial_n / (factorial_r * factorial_diff);
    return value;
}

int main(){
    cout << "\n------Calculate nCr-------\n" << endl;
    int n,r;
    cout << "Enter n & r : ";
    cin >> n >> r;
    if(n<r || n<0 || r<0){
        cout << "Hey n & r should be positive integer. And r should be greater than n.\nTry Again!";
    }else{
        double result = valu_Of_cofficient(n,r);
        cout << "Value of " <<n<<"C"<<r <<" = "<<result <<endl;
    }
    return 0;
}