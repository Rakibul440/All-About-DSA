#include <iostream>
using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr);
void swap(int *x, int *y);
void Insert(struct Array *arr,int key);


int main(){
    struct Array arr = {{2,4,6,8,10},10,5} ;

    cout << "Original Array \n";
    Display(arr);

    cout << "\nAfter insert 3 , Array : \n";
    Insert(&arr,3);
    Display(arr);

    return 0;
}

void Insert(struct Array *arr,int key){
    int i = arr->length-1 ;
    if(arr->size <= arr->length ){
        return ;
    }else{
        for(i ; key < arr->A[i] && i >=0; i--){
            arr->A[i+1] = arr->A[i];
        }
        cout << "i : " << i <<endl;
        arr->A[i+1] = key;
        arr->length++; // remember to do this as length of array now increase by 1;

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
