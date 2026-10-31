#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindMultipleMissingElements(vector<int>); //[6,7,8,9,11,12,15,16,17,18,19]

int main(){

    vector<int> A = {6,7,8,9,11,12,15,16,17,18,19,20,25,26};

    cout << "Missing Elements Are : ";
    FindMultipleMissingElements(A);

    return 0;
}

void FindMultipleMissingElements(vector<int> A){
    int diff = A[0] - 0;

    for(int i = 1;i<A.size();i++){
        if(A[i]-i != diff){
            int currentDiff = A[i] - i;
            while(diff < currentDiff){
                cout << diff + i << " "; 
                diff++;
            }
        }
    }
}