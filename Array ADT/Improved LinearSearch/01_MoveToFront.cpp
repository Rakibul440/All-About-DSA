#include <iostream>
using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(Array arr);
void swap(int *x, int *y);
int MoveToFront(Array *arr,int key);

int main(){
    Array arr = {
        {10,2,30,3,40},
        10,
        5
    };

    cout << "=========Original Array===========\n";
    Display(arr);

    cout << "Which Element You Want To Search : ";
    int key;
    cin >> key;

    
    int index = MoveToFront(&arr,key);
    if(index == -1) {
        cout << "Not Found";
        return 0;
    }
    cout << "The Number " << key << " is at " << index << endl;

    cout << "=========Now Array===========\n";
    Display(arr);

    return 0;
}

int MoveToFront(Array *arr,int key){
    int i;
    for ( i = 0; i < arr->length; i++)
    {
        if(arr->A[i] == key){
            swap(arr->A[i],arr->A[0]);
            return 0;
        }
    }
    return -1;
    
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Display(Array arr){
    int i;
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << "\t";
        
    }
    cout << "\n";
}