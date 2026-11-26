#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reverseString(vector<char>& s){
    int n = s.size();
    for(int i = 0; i < n/2; i++){
        char ch = s[i];
        s[i] = s[n - i -1];
        s[n - i - 1] = ch;
    }
}

int main(){
    vector<char> name = {'r','a','k','i','b','u','l'}; 

    reverseString(name);

    for(char x : name){
        cout << x;
    }

    return 0;
}