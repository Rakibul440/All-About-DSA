#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindPairwithSumK_SortedArray(vector<int>,int k) ; // [1,4,6,8,10,11,12,13,14] -> a+b = 14;

int main(){

    vector<int> A = {0,1,2,4,6,8,10,11,12,13,14};

    FindPairwithSumK_SortedArray(A,14);

    return 0;
}

void FindPairwithSumK_SortedArray(vector<int> A,int k){
    int i ,j ;
    i = 0;
    j = A.size()-1;

    while(i<j){
        if(A[i]+A[j] > k){j--;}
        else if(A[i]+A[j]<k){i++;}
        else{
            cout << A[i] << " + " << A[j] << " = " << k << endl;
            i++;
            j--;
        }
    }
}