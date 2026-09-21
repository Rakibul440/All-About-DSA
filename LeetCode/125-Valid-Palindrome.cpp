#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s) {
    string pureS;
    for(int i = 0; i< s.size();i++){
        s[i] = tolower(s[i]);
        if(isalnum(s[i])){
            pureS += s[i];
        }
    }

    int p,k;
    p = 0;
    k = pureS.size()-1;
    string word = pureS;
    
    while(k>=p){
        swap(pureS[p],pureS[k]);
        p++;
        k--;
    }

    if(word == pureS) return true;
    return false;

}

int main(int argc, char const *argv[])
{
    string sentence = "A man, a plan, a canal: Panama";
    // string sentence = "Rakibul";


    if(isPalindrome(sentence)){
        cout << sentence << " -> is 'Palindrom'";
    }else{
        cout << sentence << " -> is not 'Palindrom'";
    }
    
    return 0;
}
