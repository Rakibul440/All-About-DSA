#include <iostream>
using namespace std;

void fibonacci(int n){
    int first_term = 0;
    int second_term = 1;
    int next_term,i=3;
    if(n==1){
        cout << 0;
    }else if(n==2){
        cout << 0 <<"\t" << 1 << endl;
    }else{
        cout << first_term <<"\t" << second_term << "\t";
        while(i<=n){
            next_term = first_term + second_term;
            cout << next_term << "\t";
            first_term = second_term; 
            second_term = next_term ;
            i++;
        }
    }
}

int main(int argc, char const *argv[])
{
    cout << "\n------Print Fibonacci Number Upto N-------\n" << endl;
    int n;
    cout << "What's n : ";
    cin >> n;

    if(n<=0){
        cout << "Hey Enter a Positive Integer!";
    }else{
        cout << "Fibonacci numbers upto "<< n << " are : \t";
        fibonacci(n);
    }
    return 0;
}
