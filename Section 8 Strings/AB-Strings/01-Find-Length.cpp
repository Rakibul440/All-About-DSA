#include <iostream>
#include <stdio.h>

using namespace std;

int length(char []);

int main(){

    char word[20];

    printf("Enter a word : ");
    scanf("%s",word);

    printf("%s\n",word);

    int len = length(word);

    printf("Length of the word : %d\n", len);

    return 0;
}

int length(char str[]){
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++){
        count++;
    }

    return count;
}