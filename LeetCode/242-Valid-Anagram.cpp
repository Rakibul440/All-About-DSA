#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
        int H[26] = {0},lenS = 0 , lenT = 0;

        for(int i = 0; s[i] != '\0';i++){
            H[s[i]-97] += 1;
            lenS++;
        }
        for(int i = 0; t[i] != '\0';i++){
            H[t[i]-97] -= 1;
            if(H[t[i]-97] < 0){
                return false;
            }
            lenT++;
        }
        if(lenS != lenT) return false;
        return true;
    }