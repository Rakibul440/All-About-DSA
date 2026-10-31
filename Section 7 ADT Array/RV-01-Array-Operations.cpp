#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void ReverseArray(vector<int> &);
void ReverseArray_2(vector<int> &);
void LeftShift(vector<int> &,int);

void LeftShift_optim(vector<int> &,int);
void LeftShift_optim_2(vector<int> &,int);

void RightShift(vector<int> &,int);


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
    LeftShift_optim_2(A,3);  // leftshift by 3 

    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";

    cout << "\nRight SHIFT :=\n";

    vector<int> B = {2,4,6,8,10,12,14};
    cout << "B : \n";
    for(auto x : B){
        cout << x << " ";
    }
    cout << "\n";

    RightShift(B,3);

    for(auto x : B){
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

void LeftShift_optim_2(vector<int> &A,int n){
    int length = A.size();
    n %= length;

    reverse(A.begin(), A.begin()+n); // reverse first n  6,4,2 | 12,8,10,100
    reverse(A.begin()+ n, A.end());  // Reverse left side from n to end  6,4,2 | 100,10,8,12
    reverse(A.begin(),A.end());  // reverse full 12,8,10,100,2,4,6

}   


void RightShift(vector<int> &A,int n){
    int lenght = A.size();
    if(lenght == 0) return;
    
    n %= lenght;

    // 2,4,6,8|10,12,14
    reverse(A.begin(), A.end()); // 14,12,10|8,6,4,2
    reverse(A.begin()+n, A.end()); // 14,12,10|2,4,6,8
    reverse(A.begin(),A.begin()+n);
}