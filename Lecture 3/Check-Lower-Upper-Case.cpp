#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char letter ;
    cout << "Enter an alphabate : ";
    cin >> letter;
    
    if(letter >= (int)'a' && letter <= (int)'z'){
        cout << "You have enter a lowercase alphabate !\n";
    }
    else if(letter >= (int)'A' && letter <= (int)'Z'){
        cout << "You have enter a Uppercase alphabate !\n" ;
    }else{
        cout << "Enter an Alphabate ! It's not an alphabate!";
    }
    return 0;
}
