#include <iostream>
using namespace std;

void swap(int *x , int *y);
void swap_max_min(int numbers[], int n);

int main(){
    int numbers[] = {1,15,12,78,0,-12};

    cout << "Original Array : " <<endl;
    for(int i = 0; i < 6 ; i++){
        cout << numbers[i] << '\t';
    }

    cout << "\nAfter SwapingMaximum and Minimum Numbers : " <<endl;
    swap_max_min(numbers,6);
    for(int i = 0; i < 6 ; i++){
        cout << numbers[i] << '\t';
    }
    return 0; 
}

void swap_max_min(int numbers[],int n){
    int i,indexOfSmallest,indexOfLargest;
    int smallest = 0, largest = 0;
    for(i = 0;i<n;i++){
        if(numbers[i]<smallest){
            indexOfSmallest = i;
        }
    }
    for(i = 0;i<n;i++){
        if(numbers[i]>largest){
            indexOfLargest = i;
        }
    }

    swap(&numbers[indexOfSmallest],&numbers[indexOfLargest]);

}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}
