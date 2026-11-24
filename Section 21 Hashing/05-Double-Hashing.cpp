#include <iostream>
#include <bits/stdc++.h>
#include "includes/conditions.h"

using namespace std;

int HashFunc1(int,int);
int HashFunc2(int,int);

int Hashed(int,int,int,int);
int HashTableSize(int);
void insert(vector<int>&H,int x);
int search(vector<int> &,int);
int remove(vector<int> &,int);


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


    cout << "\n HASH TABLE \n";
    for(int i = 0; i<H.size();i++){
        cout << i << " : ";
        if(H[i]==0){
            cout << "EMPTY" << endl;
        }else{
            cout << H[i] << endl;
        }
    }

    int index = search(H,95);
    if(index == -1){
        cout << "Not Found!\n";
    }else{
        cout << "Found at : " << index << endl;
    }

    int r = remove(H,95);
    if(r == -1){
        cout << "Element not found to delete!\n";
    }

    cout << "\n HASH TABLE \n";
    for(int i = 0; i<H.size();i++){
        cout << i << " : ";
        if(H[i]==0){
            cout << "EMPTY" << endl;
        }else{
            cout << H[i] << endl;
        }
    }
}

int search(vector<int> &H,int key){
    int i = 0;
    int m = H.size();
    int R = prevPrime(m);

    while(i<m){
        int index = Hashed(key,i,m,R);
        if(H[index] == 0){
            return -1;
        }else if(H[index] ==  key){
            return index;
        }
        i++;
    }

    return -1;
}

void insert(vector<int>&H,int x){
    int i = 0;
    int m = H.size();
    int R = prevPrime(m);

    while (i<m)
    {
        int index = Hashed(x,i,m,R);
        if(H[index] == 0){
            H[index] = x;
            return;
        }
        i++;
    }

    cout << "Hash Table is Full!" << endl;
    
}

int remove(vector<int> &H,int key){
    int index = search(H,key);
    if(index == -1) return -1;
    H[index] = -1;

    return index;
}

// x is key, m hashTable size
int Hashed(int x,int i,int m,int R){
    int p = HashFunc1(x,m) ;
    int q = i * HashFunc2(x,R);
    return (p + q) % m;
}

int HashFunc1(int x,int m){
    return x  % m;
}

int HashFunc2(int x,int R){
    return R-(x%R);
}

int HashTableSize(int totalKeys){
    int m = 2 * totalKeys + 1;

    if(isPrime(m)){
        return m;
    }

    m = nextPrime(m);
    return m;
}