#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindMultipleMissingElements(vector<int>); //[6,7,8,9,11,12,15,16,17,18,19]
void FindMultipleMissingUsing_HashTable(vector<int>);

int main(){

    vector<int> A = {6,7,8,9,11,12,15,16,17,18,19,20,25,26};

    cout << "Missing Elements Are : ";
    FindMultipleMissingElements(A); 

    
    cout << "\nFinding Missing (Using HashTable) : ";
    FindMultipleMissingUsing_HashTable(A);

    return 0;
}

void FindMultipleMissingUsing_HashTable(vector<int> A){
    int min , max;
    min = A[0];
    max = A[0]; 

    for(auto x : A){
        if(x<min){
            min = x;
        }else if(x > max){
            max = x;
        }
    }

    vector<int> H(max+1,0);
    
    for(int i = 0; i< A.size(); i++){
        H[A[i]]++;
    }

    for(int i =  min; i <= max;i++){
        if(H[i]==0){
            cout << i << " ";
        }
    }


}

void FindMultipleMissingElements(vector<int> A){
    int diff = A[0] - 0;

    for(int i = 1;i<A.size();i++){
        if(A[i]-i != diff){
            int currentDiff = A[i] - i;
            while(diff < currentDiff){
                cout << diff + i << " "; 
                diff++;
            }
        }
    }
}