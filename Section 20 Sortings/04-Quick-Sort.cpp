#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int &x , int &y);
int Partition(vector<int> &A, int low,int high);
void QuickSort(vector<int> &A, int low,int high);

int main(){

    vector<int> A = {5,3,9,11,7,2,1,4};
    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";

    QuickSort(A,0,A.size()-1);

    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

void QuickSort(vector<int> &A, int low,int high){
    if(low<high){
        int partitionIndex = Partition(A,low,high);
        QuickSort(A,low,partitionIndex-1);
        QuickSort(A,partitionIndex+1,high);
    }
}

int Partition(vector<int> &A, int low,int high){
    int i , j , pivot;
    pivot = A[low];
    i = low;
    j = high;

    while(i<j){
        while(A[i] <= pivot && i < high) i++;  // i moves right, looking for an element GREATER than pivot (Stop when we got greter elemnet)

        while(A[j] > pivot && j > low) j--;

        if(i<j){
            swap(A[i],A[j]);
        }
    }

    swap(A[low],A[j]);

    return j;
    
}

void swap(int &x , int &y){
    int temp = x;
    x = y;
    y = temp;
}