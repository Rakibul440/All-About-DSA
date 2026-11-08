#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void CountSort(vector<int> &A);

int main(){

    vector<int> A = {2,4,6,2,8,10,2,4,6,9,4,3,7};

    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";

    CountSort(A);

    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

void CountSort(vector<int> &A){
    int max = A[0];

    // find max
    for(int i = 1; i < A.size();i++){
        if(A[i]>max) max = A[i];
    }

    vector<int> C(max+1,0);

    for(int i = 0; i < A.size();i++){
        C[A[i]]++;
    }

    int i = 0,j=0;
    while(i<max+1){
        if(C[i]>0){
            A[j] = i;
            j++;
            C[i]--; 
        }else{
            i++;
        }
    }
}