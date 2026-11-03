#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int MaxSubArray(vector<int> A); // T = O(n^2)
int MaxSubArray_Kadane(vector<int> A); // T=O(n)

int MaxSubArray_Kadane(vector<int> A){
    int currentSum = A[0];
    int maxSum = A[0];

    for(int i = 1; i < A.size();i++){
        currentSum = max(A[i],currentSum+A[i]);
        maxSum = max(currentSum,maxSum);
    }

    return maxSum;
}

int main(){
    // vector<int> A = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> A = {5,4,-1,7,8};
    // int max = MaxSubArray(A);
    int max = MaxSubArray_Kadane(A);


    cout << "MAX SUB ARRAY SUM : " << max << endl;
    return 0;
}

int MaxSubArray(vector<int> A){
    int maxSum = INT_MIN;
    int curSum;

    for(int i = 0;i<A.size();i++){
        curSum = 0;
        for(int j = i;j<A.size();j++){
            curSum += A[j];
            if(curSum>maxSum){
                maxSum = curSum;
            }
        }
    }

    return maxSum;
}