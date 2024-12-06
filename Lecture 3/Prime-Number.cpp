#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "\n------Check Prime Number------\n" <<endl;
    cout << "Enter a number : \n";
    int number,i=2;
    bool prime = false;
    cin >> number;

/*
    if (number == 1 || number == 2){
        cout << "Prime Number!\n";
    }
    else if(number > 2){
        for(i;i<number;i++){
            if(number % i == 0){
              prime = false;
              break;
            }else {
                prime = true;
            }
        }
        if(!prime) cout << "It's Not Prime Number. Try Again !\n";
        if(prime) cout << "Your Have Enter A Prime Number\n";
    }else{
        cout << "Enter a Positive Number!\n";
    }
*/   
    //--Better Approch
    /*Start from 1 and check divisibility up to the square root of the number.
      After square root ,the factors are repating itself
    */
   
    bool isPrime = true;
    for(i;i*i<=number;i++){   // i*i <= n that's mean loop will end when i is root n
        if(number % i == 0){
            isPrime = false;
            break;
        }
    }
    if(isPrime) cout << "Your Have Enter A Prime Number\n";
    else cout << "It's Not Prime Number. Try Again !\n";
    
    
    return 0;
}
