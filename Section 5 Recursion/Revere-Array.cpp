#include <bits/stdc++.h>
using namespace std;

void swap_(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void arrayReverse (int arr[], int n){

    int p = 0,k = n-1;
    while (k>=p)
    {
        // swap_(&arr[p],&arr[k]);
        swap(arr[p],arr[k]);
        p++;
        k--;
    }

}

void arrayReverseByRecursion(int i,int arr[], int n){
    while (i <= n/2)
    {
        swap(arr[i],arr[n-i-1]);
        i++;
        arrayReverseByRecursion(i+1,arr,n);
    }
    
}

void stringReverse(string &str){
    int p = 0,q = str.size()-1;
    while (q >=p)
    {
       swap(str[p],str[q]);
       p++;
       q--;
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[5] = {1,2,3,4,5};
    string name = "rakibul";

    // arrayReverse(arr,5);
    arrayReverseByRecursion(0,arr,5);

    for(int x : arr){
        cout << x << "\t";
    }

    cout << "\n" ;

    stringReverse(name);
    cout << name;

    return 0;
}
