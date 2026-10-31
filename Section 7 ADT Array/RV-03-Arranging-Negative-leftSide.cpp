#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void ArrangeNegetiveLeftside(vector<int> &);

int main(){
    vector<int> A = {-6,3,-8,10,5,-7,-9,12,-4,2};
    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";
    ArrangeNegetiveLeftside(A);

    for(auto x : A){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}


void ArrangeNegetiveLeftside(vector<int> &A){
    int i = 0; int j = A.size() -1;

    while(i<j){
        while(A[i] < 0) i++;
        while(A[j]>=0)j--;
        
        if(i<j)
            swap(A[i],A[j]);
    }

}