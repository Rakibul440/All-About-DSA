#include <iostream>
using namespace std;

//define a structure of an Array

struct Array{
    int A[10];
    int size;
    int lenght;
};

void Display(struct Array arr);
void Append(struct Array *arr , int x);
void Insert(struct Array *arr,int index,int x);
void Delete(struct Array *arr, int index);

int main(int argc, char const *argv[])
{
    struct Array arr = {{2,4,6,8,10},10,5};

    cout << "Original Array : \n";
    Display(arr);

    Append(&arr,69);
    cout << "\nArray after append 69 : \n";
    Display(arr);

    Insert(&arr,2,07);
    cout << "\nArray after insert 07 after 4(index 2) : \n";
    Display(arr);

    Delete(&arr,2);
    cout << "\nArray after Delete 07 after 4(index 2) : \n";
    Display(arr);

    return 0;
}

void Display(struct Array arr){
    // cout << "\nPrint All elements \n";
    cout << endl;
    for(int i = 0; i<arr.lenght;i++)
        cout << arr.A[i] << "\t";
}

void Append(struct Array *arr , int x){
    if(arr->size > arr->lenght)
        arr->A[arr->lenght++] = x; 

        /*
        arr->A[arr->lenght] = x;
        arr->lenght++;
        */
}

void Insert(struct Array *arr,int index,int x){
    int i;
    if(index >= 0 && index <= arr->lenght )
        for(i = arr->lenght ; i > index;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->lenght++;
}

void Delete(struct Array *arr, int index){
    int i, x = 0;
    if(index >=0 && index < arr->lenght){
        arr->A[index] = x;
        for(i = index; i < arr->lenght-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->lenght--;
    }
}