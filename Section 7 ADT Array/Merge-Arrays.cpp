#include <iostream>
using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr);
struct Array *Merge(struct Array *arr1, struct Array *arr2);

int main(){
    struct Array arr1 = {{2,6,10,15,25},10,5};  //sorted
    struct Array arr2 = {{3,4,7,18,20},10,5};   //sorted

    struct Array *resultArray;

    resultArray = Merge(&arr1, &arr2); //gives pointer address
    cout << resultArray <<endl;
    Display(*resultArray); //should pass value by pointer
    return 0;
}

struct Array *Merge(struct Array *arr1, struct Array *arr2){
    int i ,j,k;
    struct Array *arr3 = new Array();
    // struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)) //in c lang
    i = j = k =0;

    while(i <arr1->length && j < arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k] = arr1->A[i];
            k++;
            i++;
        }else{
            arr3->A[k] = arr2->A[j];
            k++;
            j++;
        }
        
    }
    for( ; i<arr1->length;i++){
        arr3->A[k++] = arr1->A[i] ;
    }
    for( ; j < arr2->length ; j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length ;
    arr3->size = 10;

    return arr3; //returning the struct address
}


void Display(struct Array arr){
    cout << endl;
    for(int i = 0; i<arr.length;i++)
        cout << arr.A[i] << "\t";
}