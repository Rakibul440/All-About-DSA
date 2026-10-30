#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void MergeSort(vector<int> &,int,int,int);

int main(){
    vector<int> A = {1,1,1,2,5,8,12,3,6,7,10}; // 2 sorted list into a single list [2,5,8,12] and [3,6,7,10]

    MergeSort(A,3,6,A.size()-1);

    for(auto x : A){
        cout << x << " ";
    }

    return 0;
}

void MergeSort(vector<int> &A,int low,int mid,int high){
    vector<int> C(high+1);

    int i,j,k;
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high){
        if(A[i] < A[j]){
            C[k++] = A[i++];
        }else{
            C[k++] = A[j++];
        }
    }

    for(;i<=mid;i++) C[k++] = A[i];
    for(;j<=high;j++) C[k++] = A[j];

    for(int i = low;i<=high;i++) A[i] = C[i];

}