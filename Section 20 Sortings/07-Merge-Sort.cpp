#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 2-way Merging
void Merge(vector<int> &,int,int,int);

// M-Way Merging
void MergeSort(vector<int> &,int);

int main(){
    vector<int> A = {8,3,7,4,9,2,6,5};

    MergeSort(A,A.size());

    for(auto x : A){
        cout << x << " ";
    }

    return 0;
}

void MergeSort(vector<int> &A,int n){
    int p,i,low,mid,high;

    for(p=2;p<=n;p=p*2){
        for(i=0; i+p-1 < n ; i = i+p){
            low = i;
            high = i+p-1;
            mid = low + (high - low) /2;
            // mid = (high+low)/2;

            Merge(A,low,mid,high);
        }
    }

    if(p/2<n)Merge(A,0,p/2,n-1);
}

void Merge(vector<int> &A,int low,int mid,int high){
    vector<int> C(high + 1);

    int i , j , k;
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            C[k++] = A[i++];
        }else{
            C[k++] = A[j++];
        }
    }

    for(;i<=mid;i++)C[k++] = A[i];
    for(;j<=high;j++)C[k++] = A[j];

    for(int i = low; i <= high ; i++){
        A[i] = C[i];
    }

}