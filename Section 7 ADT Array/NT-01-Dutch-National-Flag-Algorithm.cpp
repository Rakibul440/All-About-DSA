#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// sort three distinct elements without using sorting algorithm with T=O(n) and S=O(1);

void sort_012(vector<int>&);


int main(){

    vector<int> A = {1,2,0,1,1,0,0,0,2,2,1,0};

    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";

    sort_012(A);
    
    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

void sort_012(vector<int>& A){
    int low = 0;
    int mid = 0;
    int high = A.size()-1;

    while(mid<=high){
        if(A[mid]==0){
            swap(A[mid],A[low]);
            mid++;
            low++;
        }else if(A[mid]==1){
            mid++;
        }else{  // handle 2
            swap(A[mid],A[high]);
            high--;
        }
    }
}