#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindPairwithSumK(vector<int>,int) ;  // find a+b=k

int main() {

    vector<int> A = {6,3,8,10,16,7,5,2,9,14};

    FindPairwithSumK(A,10);  // find pair whom addition = 10

    return 0;
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