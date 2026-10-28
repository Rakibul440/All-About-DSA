#include <iostream>
using namespace std;

void InsertionSort(int *,int);

int main(){
    int A[] = {5,9,1,5,3,7,2};
    int n = sizeof(A)/sizeof(A[0]);

    for(int x : A){
        cout << x << " ";
    }
    cout << "\n";

    InsertionSort(A,n);

    for(int x : A){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

void InsertionSort(int *A,int n){
    int x;
    for(int i = 1; i < n; i++){
        int j = i-1;
        x = A[i];
        while(j>-1 && A[j]>x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}