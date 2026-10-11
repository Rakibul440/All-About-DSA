#include <iostream>
using namespace std;

int length(char []);
char* reverseString(char []);
void reverseStringOptim(char * str);
void swap(char *,char *);

int main(){

    char str[] = "HELLO WORLD 123";

    cout << str  << " --> " << reverseString(str) << endl;

    reverseStringOptim(str);
    cout << str << endl;
    return 0;
}

void reverseStringOptim(char * str){
    int n = length(str);

    for(int i = 0; i < n/2 ; i++){
        // char temp;
        // temp = str[i];
        // str[i] = str[n-i-1];
        // str[n-i-1] = temp;
        swap(&str[i],&str[n-i-1]);
    }
}

char* reverseString(char str[]){
    static char temp[100];

    int i = length(str) - 1;
    int j;
    for (j = 0; i >= 0; i--, j++)
    {
       temp[j] = str[i];
    }
    
    temp[j] = '\0';

    // cout << temp << endl;
    // printf("%s\n",temp);
    return temp;
}

int length(char str[]){
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    
    return count ;
}

void swap(char * x,char * y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}