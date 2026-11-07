#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int i ;
    cin>>i;
    while((i--)>0){
        
        string word;
        cin >> word;

        int size = word.size();
    
        if(size>10){
            string iword = "";
    
            iword += word[0];
            iword += to_string(size-2);
            iword += word[size-1];
    
            word = iword;
    
        }
        
        cout << word << endl;
    }
    return 0;
}