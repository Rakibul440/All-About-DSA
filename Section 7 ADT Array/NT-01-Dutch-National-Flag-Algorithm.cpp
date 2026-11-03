#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// sort three distinct elements without using sorting algorithm with T=O(n) and S=O(1);

void sort_012(vector<int>&);
void sort_Any_3no(vector<int> &); // sort any three distinct using DNFA

void sort_Any_3no(vector<int> &A){
    int low = 0;
    int mid = 0;
    int high = A.size() -1;

    int min = A[0];
    int midEle;
    int max = A[0];

    // find min and max --- treat that as 0's and 2's and 1's as that other third elements
    for(int i = 0;i<A.size()-1;i++){
        if(A[i]<min){
            min = A[i];
        }else if(A[i]>max){
            max = A[i];
        }else{
            midEle = A[i];
        }
    }

    while(mid<=high){
        if(A[mid] == min){
            swap(A[mid],A[low]);
            mid++;
            low++;
        }else if(A[mid]==midEle){
            mid++;
        }else{ // handle max
            swap(A[mid],A[high]);
            high--;
        }
    }
}

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

    cout << "== SORT 17's, 21's and 31's ==" << endl;
    vector<int> B = {21,17,21,17,21,21,31,31,17,21,31,21};

        
    for(auto x : B){
        cout << x << " ";
    }
    cout << "\n";

    sort_Any_3no(B);

        
    for(auto x : B){
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