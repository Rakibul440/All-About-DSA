#include <iostream>
using namespace std;

bool isValidString(char []);

int main(){

    // char str[] = "lucifer";
    char str[] = "lucifer004";
    // char str[] = "#lucifer_004";

    if(isValidString(str)){
        cout << "Valid string" << endl;
    }else {
        cout << "Invalid string" << endl ;
    }

    return 0;
}

bool isValidString(char str[]){
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (
            !(str[i] >= 65 && str[i] <= 90) &&
            !(str[i] >= 97 && str[i] <= 122) &&
            !(str[i] >= 48 && str[i] <= 57)
        )
        {
            return false;
        }
        
    }
    return true;
}