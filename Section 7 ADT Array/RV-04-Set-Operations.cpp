#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> Union(vector<int> , vector<int>);  // two sorted Array time complexity o(nlogn) --> for unsorted first sort two array then perform Merge
vector<int> Intersection(vector<int> , vector<int>); // two sorted Array

int main(){

    vector<int> A = {1,1,2,3,4};
    vector<int> B = {3,4,5,6,6,6,7,7,7,8,8,9,9,9};

    vector<int> C = Union(A,B);


    cout << "\nUnion: \n";
    for(auto x : C){
        cout << x << " ";
    }
    cout << "\n";

    vector<int> D = Intersection(A,B);
    cout << "\nIntersection: \n";
    for(auto x : D){
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
            if(C.empty() || C.back() != A[i]){
                C.push_back(A[i]);
            }
            i++;
        }else if(A[i]==B[j]){
            if(C.empty() || C.back() != A[i]){
                C.push_back(A[i]);
            }
            i++;
            j++;
        }else{
            if(C.empty() || C.back() != B[j]){
                C.push_back(B[j]);
            }
            j++;
        }
    }

    for(;i<A.size();i++){
        if(C.empty() || C.back() != A[i]){
            C.push_back(A[i]);
        }
    }
    for(;j<B.size();j++){
        if(C.empty() || C.back() != B[j]){
            C.push_back(B[j]);
        }
    }

    return C;
}

vector<int> Intersection(vector<int> A , vector<int> B){
    vector<int> C;

    int i ,j;
    i=j=0;

    while(i<A.size() && j<B.size()){
        if(A[i] < B[j]){
            i++;
        }else if(A[i] > B[j]){
            j++;
        }else{
            if(C.empty() || C.back() != A[i]){
                C.push_back(A[i]);
            }
            i++;
            j++;
        }
    }

    return C;
}