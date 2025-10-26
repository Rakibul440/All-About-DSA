#include <iostream>
using namespace std;

struct Array{
    int size ;
    int A[10];
    int length;
};

void Display(struct Array arr);
void Append(struct Array *arr, int x);
void Insert(struct Array *arr, int index , int num);

int main(){
    struct Array arr = {
        10,
        {5,9,6,3,7},
        5
    };

    cout << "=======Original Array======\n";
    Display(arr);

    
    cout << "Which element you want to append : ";
    int lastEle;
    cin >> lastEle;

    Append(&arr,lastEle);



    int num,index;
    cout << "Which element you want to Insert : ";
    cin >> num;
    cout << "In which position you want to inser : ";
    cin >> index;

    Insert(&arr,index,num);
    
    return 0;
}

void Display(struct Array arr){
    int i;
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << "\t";
    }
    cout << "\n";
    
}

void Append(struct Array *arr, int x){
    if(arr->length == arr->size){
        cout << "There is no place to put value\n";
        return;
    }
    arr->A[arr->length] = x;
    arr->length++;

    cout << "======After Appending=======\n";
    Display(*arr);
}

void Insert(struct Array *arr, int index , int num){
    int i;
    if(arr->length == arr->size){
        cout << "There is no place to put value\n";
        return;
    }
    if(index < 0 || index > arr->length){
        cout << "Invalid position\n";
        return;
    }
    for(i = arr->length; i > index ; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = num;
    arr->length++;

    cout << "======After Inserting=======\n";
    Display(*arr);
}