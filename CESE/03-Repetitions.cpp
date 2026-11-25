#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    string dna;
    cin >> dna;

    int maxLength = 1;
    int currLength = 1;

    int i = 1 , j = 0;

    
    while(dna[i] != '\0'){
        if(dna[i]==dna[j]){
            currLength++;
            if(currLength>maxLength) maxLength = currLength;
        }
        else{
            j=i;
            currLength = 1;
        }
        i++;
    }
    
    cout << maxLength ;

    return 0;
}