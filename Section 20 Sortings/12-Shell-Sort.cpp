#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void ShellSort(vector<int> &A);

void ShellSort(vector<int> &A){
    int n = A.size();
    int gap;
    
    for(gap = n/2; gap > 0; gap /= 2){
        for(int i = gap ;  i < n ; i++){
            int temp = A[i];

            int j = i - gap;

            while(j>=0 && A[j] > temp){
                A[j+gap] = A[j];
                j = j - gap;
            }
            A[j+gap] = temp;
        }
    }
}

int main(){
    vector<int> A = {2,4,6,3,7,9,1,0,14,11,2,4,3,9};

    for(int x : A){
        cout << x << " ";
    }
    cout << "\n";

    ShellSort(A);

    for(int x : A){
        cout << x << " ";
    }
    cout << "\n";


    return 0;
}