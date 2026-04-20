#include <bits/stdc++.h>
using namespace std;

void swap_(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void arrayRevere( int i, int arr[], int n){
    for(int i = 0; i <=n/2;i++){
        if(i <= n/2) return;
        swap_(&arr[i],&arr[n-i-1]);
        arrayRevere(i+1,arr,n);
    }
}

int main(int argc, char const *argv[])
{
    int arr[5] = {1,2,3,4,5};
    arrayRevere(0,arr,5);
    for(int x : arr){
        cout << x << "\t";
    }
    return 0;
}
