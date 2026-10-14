#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<pair<char,int>> findDuplicates(char []);

int main(){
    char str[] = "findinkkkkkkkkgss"; 

    vector<pair<char,int>> results = findDuplicates(str);

    cout << "Found " << results.size() << " duplicates.\n";

    for(auto x : results){
        cout << x.first << " : " << x.second << " times\n";
    }

    return 0;
}

vector<pair<char,int>> findDuplicates(char A[]){
    int H[26] = {0};
    vector<pair<char,int>> duplicates;

    for(int i = 0; A[i] != '\0'; i++){

        // make it lowercase
        if(A[i] <= 65 && A[i] >=90) A[i] += 32;

        // As lowercase alphabate starting from ascii 97 so now we'll got 'a' as 0 index not 97;
        H[A[i]-97] += 1;
    }

    for(int i = 0; i < 26; i++){
        if(H[i]>1){
            duplicates.push_back({i+97,H[i]});
        }
    }

    return duplicates;
}