#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr);
void Swap(int *x, int *y);
int LinearSearch(struct Array arr, int key);
//Improving Liner Search 
int TranspositionMethod(struct Array *arr,int key); // Every time search same element , element will swap by one index ;
int MoveToFront(struct Array *arr, int key); // searched element will swap to front of the array, so that next time ,same element takes less time to search


int main(){
    struct Array arr = {{2,4,3,6,7,9,12},10,7}; // should be all unique element

    cout << "Original Array : " <<endl;
    Display(arr);
    
    cout << "\nElement 6 is in index : " << LinearSearch(arr,6) << endl;

    cout << "\nElement 9 is in index : " << TranspositionMethod(&arr,9) << endl;
    Display(arr);

    cout << "\nElement 7 is in index : " << MoveToFront(&arr,7) << endl;
    Display(arr);


    return 0;
}


void Display(struct Array arr){
    cout << endl;
    for(int i = 0; i<arr.length;i++)
        cout << arr.A[i] << "\t";
}

void Swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array arr, int key){
    int i;
    for(i = 0; i<arr.length ; i++){
        if(key == arr.A[i])
            return i; // successful
    }

    return -1; //unsuccessfull
}

int TranspositionMethod(struct Array *arr,int key){
    int i;
    for(i = 0;i < arr->length;i++){
        if(key ==  arr->A[i]){
            Swap(&arr->A[i],&arr->A[i-1]);
            return i;
        }
    }

    return -1;
}

int MoveToFront(struct Array *arr,int key){
    int i;
    for(i = 0;i<arr->length;i++){
        if(key ==  arr->A[i]){
            Swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }

    return -1;
}