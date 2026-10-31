#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isSorted(vector<int>);

int main(){
    // vector<int> A = {2,5,6,7,8,9};
    vector<int> A = {10,9,8,7,6,5};
    // vector<int> A = {2,5,6,7,2,4,8,9};


    if(isSorted(A)) cout << "Sorted" << endl;
    else{
        cout << "Not sorted" << endl;
    }

    return 0;
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