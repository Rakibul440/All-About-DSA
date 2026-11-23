#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void Display(vector<int> H);
int remove(vector<int> &H,int);
void search(vector<int>H,int);
int insert(vector<int> &H,int);


int main(){
    /*If duplicate keys then collision will be happned*/
    vector<int> A = {9,7,3,8,6,1,4,2};

    int max = A[0];
    for(int i = 1;i<A.size();i++){
        if(A[i]>max) max = A[i];
    }

    vector<int> H(max+1,0);
    // insert into hash
    for(int i = 0; i < A.size();i++){
        insert(H,A[i]);
    }

    Display(H);
    remove(H,2);
    Display(H);

    search(H,9);
    
}

int insert(vector<int> &H,int x){
    H[x] = x;
}

int remove(vector<int> &H,int x){
    H[x] = 0;
}

void Display(vector<int> H){
    for(int i = 0; i<H.size();i++){
        cout << H[i] << " ";
    }
    cout << "\n";
}

void search(vector<int>H,int x){
    if(H[x] == x){
        cout << "Present\n";
    }else{
        cout << "Not Present\n";
    }
}