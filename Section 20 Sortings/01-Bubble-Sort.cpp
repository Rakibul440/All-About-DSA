#include <iostream>
using namespace std;

void BubbleSort(int *,int);
void swap(int &,int &);

int main(){
    int A[] = {5,9,1,5,3,7,2};
    int n = sizeof(A)/sizeof(A[0]);

    for(int x : A){
        cout << x << " ";
    }
    cout << "\n";

    BubbleSort(A,n);

    for(int x : A){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

void BubbleSort(int *A ,int n){
    for(int i = 0; i < n-1; i++){
        bool swapped = false;
        for(int j = 0; j < n-1-i;j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}