#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<char> findDuplicates(char str[]);

int main(){

    char str[] = "iloveyouhannah";

    vector<char> duplicates = findDuplicates(str);

    cout << "Found " << duplicates.size() << " duplicates.\n";
    for(auto x : duplicates){
        cout << x << ", ";
    }

    return 0;
}

vector<char> findDuplicates(char str[]){
    long int H = 0;
    long int X = 0; // For masking(checking bit on or not) and merging(setting bit on)

    vector<char> duplicates;

    for (int  i = 0; str[i] != '\0'; i++)
    {
        X = 1;
        int indexPostion = str[i]-97;  // index postion of that alphabate
        
        // checking bit on or not using masking 
        if(H & (X << indexPostion)){
            duplicates.push_back(str[i]);
        }
        // set on the bit according to alphabate positions
        else{
            H = H | (X << indexPostion);  //(Merging)
        }
    }

    return duplicates;
    
}