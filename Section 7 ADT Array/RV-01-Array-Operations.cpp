#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void ReverseArray(vector<int> &);
void ReverseArray_2(vector<int> &);
void LeftShift(vector<int> &,int);

void LeftShift_optim(vector<int> &,int);



int main(){

    vector<int> A = {2,4,6,12,8,10,100};

    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";

    cout << "\nREVERSE :=\n";

    ReverseArray(A);

    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";

    ReverseArray_2(A);

    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";

    cout << "\nLEFT SHIFT :=\n";
    LeftShift_optim(A,11);  // leftshift by 3 

    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

void ReverseArray(vector<int> &A){
    for(int i = 0,j= A.size()-1; i<j;i++,j--){
        swap(A[i],A[j]);
    }
}

void ReverseArray_2(vector<int> &A){
    for(int i = 0; i < A.size()/2;i++){
        swap(A[i],A[A.size()-i-1]);
    }
}

void LeftShift(vector<int> &A,int n){
    for(int i = 0; i < n; i++){
        int temp = A[0]; int k = 0;
        for( k ; k < A.size()-1; k++){
            A[k] = A[k+1];
        }

        A[k] = temp;
    }
}

void LeftShift_optim(vector<int> &A,int n){
    int length = A.size();

    if (length == 0) return;

    n %= length;

    // reverse full array
    for(int i = 0, j = length-1; i<j ; i++,j--){
        swap(A[i],A[j]);
    }

    // reverse till A.size() - n - 1
    for(int i = 0, j = length - n - 1; i<j ; i++,j--){
        swap(A[i],A[j]);
    }

    // reverse A.size() - n to end
    for(int i = length - n , j = length - 1; i<j ; i++,j--){
        swap(A[i],A[j]);
    }
}