#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindDuplicates(vector<int>); // [3,6,8,8,10,12,15,15,15,20]
void FindDuplicatesAndCount(vector<int>);
void FindDuplicatesUsing_HashTable(vector<int>);

int main(){

    vector<int> A = {3,6,8,8,10,12,15,15,15,20,20,20};

    FindDuplicates(A);

    cout << "\n";
    FindDuplicatesAndCount(A);

    cout << "\nUsing HashTable : \n";

    FindDuplicatesUsing_HashTable(A);

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

void FindDuplicatesUsing_HashTable(vector<int> A){
    int max;
    for(int i = 0; i < A.size(); i++ ){
        if(A[i] > max){
            max = A[i];
        }
    }

    vector<int> H(max,0);

    for(int i = 0; i < A.size(); i++){
        H[A[i]]++;
    }

    for(int i = 0; i < H.size(); i++){
        if(H[i] > 1){
            cout << i << " -> " << H[i] << " time\n";
        }
    }
}