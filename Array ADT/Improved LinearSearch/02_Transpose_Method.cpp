#include <iostream>
#include <stdio.h>

using namespace std;


struct Array {
    int *A;
    int size;
    int length;
};

void Display(Array arr);
void Swap(int *x , int *y);
int Transpose(Array *arr, int key);

int main(){

    struct Array arr;
    arr.size = 10;
    arr.A = new int[arr.size];
    arr.length = 0;

    arr.A[0] = 10;
    arr.A[1] = 5;
    arr.A[2] = 12;
    arr.A[3] = 15;
    arr.A[4] = 8;

    arr.length = 5;


    cout << "=========Original Array===========\n";
    Display(arr);

    cout << "Which Element You Want To Search : ";
    int key;
    cin >> key;

    int index = Transpose(&arr, key);
    if(index == -1) {
        cout << "Not Found!\n";
        return 0;
    }

    cout << "The Number " << key << " is at " << index << endl;

    cout << "=========Now Array===========\n";
    Display(arr);


    return 0;
}

int Transpose(Array *arr, int key){
    int i ;
    for(i=0; i< arr->length; i++){
        if(arr->A[i] == key){
            if(i>0){
                Swap(&arr->A[i],&arr->A[i-1]);
                return i-1;
            }

            return 0;
        }
    }
    return -1;
}

void Swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}

void Display(Array arr) {
    int i;
    for(i=0; i<arr.length; i++){
        cout << arr.A[i] << "\t" ;
    }
    cout << "\n";
}
