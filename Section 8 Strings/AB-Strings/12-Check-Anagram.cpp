#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isAanagram(char [],char []);

int main (){

    char str1[] = "care";
    char str2[] = "race";

    if(isAanagram(str1,str2)){
        cout << "Anagram strings!";
    }else{
        cout << "Not Anagram!";
    }

    return 0;
}

bool isAanagram(char A[],char B[]){
    int H[26] = {0};

    for(int i = 0; A[i] != '\0'; i++){
        H[A[i] - 97] += 1;
    }

    for(int i = 0; B[i] != '\0'; i++){
        H[B[i]-97] -= 1;

        if(H[B[i]-97] < 0){
            return false;
        }
    }

    return true;
}