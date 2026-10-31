#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void Insertion(int *A,int,int &); // insert into a sorted Array
bool isSorted(vector<int>);

int main(){
    // vector<int> A = {2,5,6,7,8,9};
    vector<int> A = {10,9,8,7,6,5};
    // vector<int> A = {2,5,6,7,2,4,8,9};


    if(isSorted(A)) cout << "Sorted" << endl;
    else{
        cout << "Not sorted" << endl;
    }

    int B[10] = {2,4,6,8,10,12,14};
    int length = 7;

    for(int x : B){
        cout << x << " ";
    }
    cout << "\n";

    Insertion(B,-1,length);

    for(int x : B){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

void Insertion(int *A,int target,int &length){
    int i = length - 1;

    while( i >= 0 && A[i] > target){
        A[i + 1] = A[i]; 
        i--;
    }

    A[i+1] = target;

    length++;
}

bool isSorted(vector<int> A){
    bool ascending =  true;
    bool descending = true;

    for(int i = 0; i < A.size()-1;  i++ ){
        if(A[i] > A[i+1]){
            ascending = false;
        }
        if(A[i] < A[i+1]){
            descending =  false;
        }
    }

    return ascending || descending;
}