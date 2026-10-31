#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindDuplicatesUnsortedArray(vector<int>); // [8,3,6,4,6,5,6,8,2,7] 
void FindDuplicatesUnsortedArray_HashTable(vector<int>);

int main(){

    vector<int> A = {1,8,3,6,4,6,5,6,8,2,7,1,1,1};

    FindDuplicatesUnsortedArray(A);

    cout << "\nUsing Hashtable : \n";
    FindDuplicatesUnsortedArray_HashTable(A);

    return 0;
}

void FindDuplicatesUnsortedArray(vector<int> A){

    for(int i = 0; i < A.size()-1; i++){
        int count = 1;

        if(A[i] != -1){

            for(int j = i+1;j <A.size(); j++){
                if(A[i]==A[j]){
                    count++;
    
                    A[j] = -1; // set -1 so that it will not count again
                }
            }
    
            if(count > 1){
                cout << A[i] << " -> " << count << " times\n";
            }
        }
    }
}

void FindDuplicatesUnsortedArray_HashTable(vector<int>A){
    int max;
    for(int i = 0; i < A.size(); i++){
        if(A[i] > max){
            max = A[i];
        }
    }

    vector<int> H(max+1,0);
    for(int i = 0; i < A.size() ; i++){
        H[A[i]]++;
    }

    for(int i = 0; i < H.size();i++){
        if(H[i] > 1){
            cout << i << " -> " << H[i] << " times \n";
        }
    }
}