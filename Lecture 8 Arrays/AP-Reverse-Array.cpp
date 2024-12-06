#include <iostream>
using namespace std;

void reverse_arr(int arr[],int n);
void swap(int *x, int *y);

int main(int argc, char const *argv[])
{
    int arr[7] = {2,4,6,8,10,12,14};

    cout << "Original Array : " <<endl;
    for(int i = 0; i < 7 ; i++){
        cout << arr[i] << '\t';
    }

    cout << "\nReverse Array : " <<endl;
    reverse_arr(arr,7);
    for(int i = 0; i < 7 ; i++){
        cout << arr[i] << '\t';
    }
    return 0;
}

void reverse_arr(int arr[],int n){
    int start = 0,end = n-1;
    while(start < end){
        swap(&arr[start],&arr[end]);
        start++;
        end--;
    }

}

void swap(int *x, int *y){
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;

}
