#include <iostream>
using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr);
void swap(int *x, int *y);
void reverse(struct Array *arr);
void reverse_2(struct Array *arr);

int main(){
    struct Array arr = {{2,3,5,8,9},10,5} ;

    cout << "Original Array \n";
    Display(arr);

    reverse_2(&arr);
    cout << "\nReverse Array : \n";
    Display(arr);

    return 0;
}

void reverse_2(struct Array *arr){
    int start,end;
    for(start = 0,end = arr->length-1;start<end;start++,end--){
        swap(&arr->A[start],&arr->A[end]);
    }
}

//reverse array element with help of another array
void reverse(struct Array *arr){
    int *B;
    int i,j;
    B = new int[arr->length];
    for(i=arr->length-1,j=0;i>=0;j++,i--){
        B[j] = arr->A[i];
    }
    // now assign all the value into A to change A
    for(i = 0; i< arr->length; i++){
        arr->A[i] = B[i];
    }

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
