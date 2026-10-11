#include <iostream>
using namespace std;

void toLowerCase(char * str);
void toUpperCase(char * str);
void toggleCase(char * str);

int main(){

    char str1[] = "DARLING";
    char str2[] = "beloved";
    char str3[] = "mY lOVE";

    toLowerCase(str1);
    toUpperCase(str2);
    toggleCase(str3);

    cout << str1 << "\n"
        << str2 << "\n" 
        << str3 << "\n" ;


    return 0;
}

void toggleCase(char * str){
    for (int i = 0; str[i] != '\0'; i++)
    {
        if( str[i] >= 65 && str[i] <= 90){
            str[i] += 32;
        }
        else if(str[i] >= 97 && str[i] <= 122){
            str[i] -= 32;
        }
    }
    
}

void toUpperCase(char * str){
    for (int i = 0; str[i] != '\0'; i++)
    {
        if( str[i] >= 97 && str[i] <= 122){
            str[i] -= 32;
        }
    }
    
}

void toLowerCase(char * str){
    for (int i = 0; str[i] != '\0'; i++)
    {
        if( str[i] >= 65 && str[i] <= 90){
            str[i] += 32;
        }
    }
    
}