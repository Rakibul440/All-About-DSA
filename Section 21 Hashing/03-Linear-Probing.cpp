#include <iostream>
#include <bits/stdc++.h>
#include "includes/conditions.h"

using namespace std;

int HashFunc(int,int,int);
int HashTableSize(int);
void insert(vector<int>&H,int x);

int main(){

    // vector<int> A = {5,25,15,20,30,125,9,8,3,35};
    vector<int> A = {3, 26, 49, 72, 95, 118, 141, 164, 187, 210}; // forming cluster

    int m = HashTableSize(A.size());
    vector<int> H(m,0);

    for(int i = 0;i<A.size();i++){
        insert(H,A[i]);
    }

    // will' form another cluster
    insert(H,16);
    insert(H,39);
    insert(H,62);



    for(int i = 0; i<H.size();i++){
        cout << i << " : ";
        if(H[i]==0){
            cout << "EMPTY" << endl;
        }else{
            cout << H[i] << endl;
        }
    }

}

void insert(vector<int>&H,int x){
    int i = 0;
    int index = HashFunc(x,i,H.size());
    while (H[index]!=0)
    {
        i++;
        index = HashFunc(x,i,H.size());
    }
    H[index] = x;
}

// x is key, m hashTable size
int HashFunc(int x,int i,int m){
    return (x + i) % m;
}

int HashTableSize(int totalKeys){
    int m = 2 * totalKeys + 1;

    if(isPrime(m)){
        return m;
    }

    m = nextPrime(m);
    return m;
}