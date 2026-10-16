#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars);
int main(){
    vector<char> chars  = {'a','a','a','a','a','a','a','a','a','a','a','a','a','b','b','$','$','z','z','a','a'};
    // vector<char> chars  = {'a'};

    int size = compress(chars);

    cout << "\nSIZE : " << size << endl;
    return 0;
}


int compress(vector<char>& chars) {

    vector<char> res;
    int count = 1;

    for(int i = 0 , j = 1; i < chars.size() ; i++, j++){
        if(j < chars.size() && chars[i] == chars[j]){
            count++;
        }else{
            res.push_back(chars[i]);
            if(count >= 10){
                string num = to_string(count);
                for(int i = 0 ; num[i] != '\0'; i++){
                    res.push_back(num[i]);
                }
            }else if(count > 1){
                res.push_back(count + 48);
            }
            count = 1;
            continue;
        }
    }

    chars = res;
    for(char x : res){
        cout << x ;
    }
    
    return res.size();
}
