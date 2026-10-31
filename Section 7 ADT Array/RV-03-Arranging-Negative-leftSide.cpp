#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void ArrangeNegetiveLeftside(vector<int> &);
void ArrangeNegetiveLeftside_ByMerge(vector<int> &,int,int);
void Merge(vector<int> &,int,int,int);

int main(){
    vector<int> A = {-6,3,-8,10,5,-7,-9,12,-4,2};
    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";
    // ArrangeNegetiveLeftside(A);
    ArrangeNegetiveLeftside_ByMerge(A,0,A.size()-1);

    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}


void ArrangeNegetiveLeftside(vector<int> &A){
    int i = 0; int j = A.size() -1;

    while(i<j){
        while(A[i] < 0) i++;
        while(A[j]>=0)j--;
        
        if(i<j)
            swap(A[i],A[j]);
    }

}

void ArrangeNegetiveLeftside_ByMerge(vector<int> &A,int low,int high){
    int mid;
    if(low<high){
        mid = low + (high-low)/2;
        ArrangeNegetiveLeftside_ByMerge(A,low,mid);
        ArrangeNegetiveLeftside_ByMerge(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}

void Merge(vector<int> &A,int low,int mid,int high){
    vector<int> C(high+1);

    int i,j,k;
    i = low;
    j=mid+1;
    k=low;

    while(i <= mid && j<= high){
        if(A[i]<A[j]){
            C[k++] = A[i++];
        }else{
            C[k++] = A[j++];
        }
    }

    for(;i<=mid;i++){
        C[k++] = A[i];
    }
    for(;j<=high;j++){
        C[k++] = A[j];
    }

    for(int i = low;i<=high;i++){
        A[i] = C[i];
    }

}