#include <iostream>
using namespace std;

void SelectionSort(int *,int);
void swap(int &,int &);

int main(){

    int A[] = {5,9,1,5,3,7,2};
    int n = sizeof(A)/sizeof(A[0]);

    for(int x : A){
        cout << x << " ";
    }
    cout << "\n";

    SelectionSort(A,n);

    for(int x : A){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}


void SelectionSort(int *A,int n){
    int j,k;
    for(int i = 0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(A[j]<A[k]){
                k = j;
            }
        }

        swap(A[i],A[k]);
    }
}

void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}