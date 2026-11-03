#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int MaxSubArray(vector<int> A);

int main(){
    vector<int> A = {-2,1,-3,4,-1,2,1,-5,4};
    // vector<int> A = {5,4,-1,7,8};
    int max = MaxSubArray(A);

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