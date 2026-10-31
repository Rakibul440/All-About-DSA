#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindDuplicates(vector<int>); // [3,6,8,8,10,12,15,15,15,20]

void FindDuplicatesAndCount(vector<int>);

int main(){

    vector<int> A = {3,6,8,8,10,12,15,15,15,20,20,20};

    FindDuplicates(A);

    cout << "\n";
    FindDuplicatesAndCount(A);

    return 0;
}

void FindDuplicatesAndCount(vector<int> A){

    for(int i = 0; i < A.size()-1;i++){

        if(A[i] == A[i+1]){
            int j = i+1;
            while(A[j] == A[i]) {
                j++;
            };

            cout << A[i] << " -> " << j-i << " times\n"; 
            i=j-1;
        }
        
    }
}

void FindDuplicates(vector<int> A){
    int last_Duplicate = -1;

    for(int i = 0; i < A.size()-1 ; i++){
        if(A[i]==A[i+1]){
            if(A[i] != last_Duplicate){
                cout << A[i] << " ";
                last_Duplicate=A[i];
            }
        }
    }
}