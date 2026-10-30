#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void MergeSort_R(vector<int> &,int ,int);
void Merge(vector<int> &,int,int,int);

int main(){
    vector <int> A = {8,3,7,4,9,2,6,5};
    MergeSort_R(A,0,A.size()-1);

    for(auto x : A){
        cout << x << " ";
    }

    return 0;
}

void MergeSort_R(vector<int> &A,int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        // int mid = low+(high - low)/2;

        MergeSort_R(A,low,mid);
        MergeSort_R(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}

void Merge(vector<int> &A,int low,int mid,int high){
    vector<int> C(high+1);
    int i , j ,k;

    i = low;
    j = mid + 1;
    k = low;

    while(i<=mid && j <= high){
        if(A[i]<A[j]){
            C[k++] = A[i++];
        }else{
            C[k++] = A[j++];
        }
    }

    for(; i<= mid; i++) C[k++] = A[i];
    for(; j<= high; j++) C[k++] = A[j];

    for(int i = low; i <= high; i++){
        A[i] = C[i];
    }
}