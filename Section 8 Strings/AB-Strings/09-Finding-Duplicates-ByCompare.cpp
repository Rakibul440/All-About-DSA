#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<char> findDuplicate(char str[]);
int length(char A[]);

int main(){

    char str[] = "level";

    vector<char> duplicates = findDuplicate(str);

    cout << "Found " << duplicates.size() << " duplicates.\n";
    for(auto x : duplicates){
        cout << x << ", ";
    }

    return 0;
}

vector<char> findDuplicate(char str[]){
    vector<char> duplicates;

    int n = length(str);

    for (int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n ; j++){
            if(str[i] == str[j]){
                duplicates.push_back(str[i]);
            }
        }
    }

    return duplicates;
    
}

int length(char A[]){
    int count=0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        count++;
    }
    
    return count;
}