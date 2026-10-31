#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindPairwithSumK(vector<int>,int) ;  // find a+b=k
void FindPairwithSumK_Hashable(vector<int>,int);

int main() {

    vector<int> A = {6,3,8,10,16,7,5,2,9,14,5,0};

    FindPairwithSumK(A,10);  // find pair whom addition = 10

    cout << "\nUsing Hash Table : \n";
    FindPairwithSumK_Hashable(A,10);
    return 0;
}

void FindPairwithSumK_Hashable(vector<int> A,int k){
    int max;
    for(int i = 0; i < A.size(); i++){
        if(A[i] > max) {
            max = A[i];
        }
    }

    vector<int> H(max+1,0);

    for(int i = 0; i < A.size();i++){

        if((H[k-A[i]]) == 1){
            cout << A[i] << " + " << k - A[i] << " = " << k << endl;
        }

        H[A[i]]++;
    }
}

void FindPairwithSumK(vector<int> A,int k){
    
    for(int i = 0 ; i < A.size() -1; i++){
        for(int j=i+1; j < A.size() ; j++){
            if(A[i]+A[j]==k){
                cout << A[i] << " + " << A[j] << " = " << k << endl;
            }
        }
    }
}