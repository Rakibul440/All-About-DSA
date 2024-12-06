#include <iostream>
using namespace std;


// check number is prime or not 
//if prime print number 

bool check_Prime(int number){
    int i ;
    bool isPrime = true;
    for(i = 2; i*i <= number;i++){
        if(number % i == 0){
            isPrime = false;
            break;
        }
    }
    if(isPrime) return isPrime;
    else return isPrime;
}

void print_prime(int number){
    int i;
    for(i = 1; i<=number; i++){
        bool checkPrime = check_Prime(i);
        if(checkPrime) {
            cout << i << "\t";
        }
    }

}

int main(int argc, char const *argv[])
{
    cout << "\n------Print Prime Number Upto N-------\n" << endl;
    int n;
    cout << "What's n : ";
    cin >> n;

    if(n<=0){
        cout << "Hey Enter a Positive Integer!";
    }else{
        cout << "Prime numbers upto "<< n << " are : \t";
        print_prime(n);
    }

    return 0;
}
