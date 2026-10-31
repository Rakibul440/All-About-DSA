#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindMissingForFirst_N(vector<int>,int);
void FindMissingForConcurrentNatural(vector<int>,int n); // [6,7,8,9,11,12,13,14]; missing 10

int main(){
    
    vector<int> A = {1,2,3,4,6,7,8,9};

    FindMissingForFirst_N(A,A[A.size()-1]);

    vector<int> B = {6,7,8,9,11,12,13,14};

    FindMissingForConcurrentNatural(B,B.size());

    return 0;
}

void FindMissingForFirst_N(vector<int> A,int N){
    int currentSum = 0;
    for(auto x : A){
        currentSum += x;
    }

    int SumOfN = N * (N + 1)/2;

    cout << "Missing Element : " << SumOfN - currentSum << endl;
}

void FindMissingForConcurrentNatural(vector<int> A,int n){
    int diff = A[0] - 0;
    int missing = -1;
    for(int i = 1; i <n;i++){
        if(A[i] - i != diff){
            missing = diff + i;
            break;
        }
    }

    cout << "Missing Element : " << missing << endl;
}