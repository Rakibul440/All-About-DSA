#include <iostream>
using namespace std;

struct Array {
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr);
void swap(int *x, int *y);
void Rearrange(struct Array *arr);


int main(){
    struct Array arr = {{-1,4,-5,5,9,-7,7,-3,-12,6},20,10} ;

    cout << "Original Array \n";
    Display(arr);

    cout << "\nAfter Rearrange Array : \n";
    Rearrange(&arr);
    Display(arr);
    return 0;
}

void Rearrange(struct Array *arr){
    int i = 0,j = arr->length-1; //i looks for negetive and j positive,
    while(i < j){

        if(arr->A[i] < 0)i++; // looks negetive
        if(arr->A[j] >= 0)j--; // looks positive

        if(i<j){
            swap(&arr->A[i],&arr->A[j]);
        }

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
