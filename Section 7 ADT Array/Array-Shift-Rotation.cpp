#include <iostream>
using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr);
void swap(int *x, int *y);
void left_shift(struct Array *arr);
void left_rotation(struct Array *arr);


int main(){
    struct Array arr = {{2,3,5,8,9},10,5} ;

    cout << "Original Array \n";
    Display(arr);

    cout << "\nAfter left rotation by 1 Array : \n";
    left_rotation(&arr);
    Display(arr);
    /*
    while(true){
        left_rotation(&arr);
        Display(arr);
    }*/
    cout << "\nAfter left shift by 1 Array : \n";
    left_shift(&arr);
    Display(arr);

    return 0;
}

void left_shift(struct Array *arr){
    int i;
    for(i = 0; i<= arr->length-1 ; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = 0;
}

void left_rotation(struct Array *arr){
    int i, temp = arr->A[0];
    for(i = 0; i <= arr->length-1;i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void Display(struct Array arr){
    cout << endl;
    for(int i = 0; i<arr.length;i++)
        cout << arr.A[i] << "\t";
}
