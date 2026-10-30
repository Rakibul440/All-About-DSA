#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>  Merge(vector<int> &A,vector<int> &B,int m,int n);

int main(){

    vector<int> A = {2,10,18,20,23,24};
    vector<int> B = {4,9,19,25,27,30};

    vector<int> C = Merge(A,B,A.size(),B.size());

    for(auto x : C){
        cout << x << " ";
    }

    return 0;
}

vector<int>  Merge(vector<int> &A,vector<int> &B,int m,int n){
    vector<int> C(m+n);
    int i,j,k;
    i=j=k=0;

    while(i<m && j<n){
        if(A[i]<B[j]){
            C[k++] = A[i++];
        }else{
            C[k++] = B[j++];
        }
    }    

    for(;i<m;i++) C[k++] = A[i];
    for(;j<n;j++) C[k++] = B[j];

    return C;
}