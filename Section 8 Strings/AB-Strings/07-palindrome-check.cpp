#include <iostream>
using namespace std;


bool isPalindrome(char []);
int length(char []);

int main(){
    char str[] = "level";

    if(isPalindrome(str)){
        cout << "String is Palindrome!";
    }else{
        cout << "String is not Palindrome";
    }
    return 0;
}

bool isPalindrome(char A[]){
    int n = length(A);

    bool isPal = true;
    for (int i = 0; i < n/2 ; i++)
    {
        if(A[i] != A[n-i-1]){
            isPal = false;
            break;
        }
    }
    
    return isPal;
}

int length(char A[]){
    int count=0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        count++;
    }
    
    return count;
}