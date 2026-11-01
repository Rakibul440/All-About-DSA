#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> Union(vector<int> , vector<int>);  // two sorted Array

int main(){

    vector<int> A = {1,2,3,4};
    vector<int> B = {3,4,5,6};

    vector<int> C = Union(A,B);

    for(auto x : C){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

vector<int> Union(vector<int> A, vector<int> B){
    vector<int> C;

    int i , j ,k;
    i=j=k=0;

    while(i<A.size() && j<B.size()){
        if(A[i] < B[j]){
            C.push_back(A[i++]);
        }else if(A[i]==B[j]){
            C.push_back(A[i++]);
            j++;
        }else{
            C.push_back(B[j++]);
        }
    }

    for(;i<A.size();i++){
        C.push_back(A[i]);
    }
    for(;j<B.size();j++){
        C.push_back(B[j]);
    }

    return C;
}