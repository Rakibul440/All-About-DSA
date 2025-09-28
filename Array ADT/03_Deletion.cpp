#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr);
void DeleteLastEement(struct Array *arr);
void Delete(struct Array *arr, int index);

int main(){
    struct Array arr;
    arr.size = 10;
    arr.length = 0;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    // arr.A = new int[arr.size];

    int A[5] = {10,15,30,21,9};
    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
    {
        arr.A[i] = A[i];
    }
    arr.length = sizeof(A)/sizeof(int);

    //===========================
    cout << "=========Original Array===========\n";
    Display(arr);

    DeleteLastEement(&arr);

    cout << "In which position element you want to delete : ";
    int index;
    cin >> index;

    Delete(&arr,index);
    
    return 0;
}

void Delete(struct Array *arr, int index){
    int i;
    if(index < 0 || index > arr->length){
        cout << "Invalid position\n";
        return;
    }
    for (int i = index; i < arr->length - 1; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;

    cout << "======After Deleting=======\n";
    Display(*arr);
    
}


void DeleteLastEement(struct Array *arr){
    arr->length--;

    cout << "======After Deleting=======\n";
    Display(*arr);
}

void Display(struct Array arr){
    int i;
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << "\t";
        
    }
    cout << "\n";
}