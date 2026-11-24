#include <iostream>
#include <bits/stdc++.h>
#include "includes/list.h"

using namespace std;


void chaining(vector<Node *> &H,vector<int>,int);
int func(int,int);

void chaining(vector<Node *> &H,vector<int> A, int size){
    for(int i = 0; i<A.size();i++){
        int index = func(A[i],size);
        List::push_back(H[index],A[i]);
    }
}

int main(){

    vector<int> A = {12,9,8,10,2,6,9};
    vector<Node *> H(10,nullptr);


    chaining(H,A,10);

    for(int i = 0;i<H.size();i++){
        cout << i << " : ";
        List :: Display(H[i]);
    }
    
    return 0;
}

int func(int x,int size){
    return x % size;
}