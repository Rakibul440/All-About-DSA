#include <iostream>
using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr);
bool IsSorted(struct Array arr);


int main(){
    struct Array arr = {{2,3,5,8,9},10,5} ;

    cout << "Original Array \n";
    Display(arr);

    if(IsSorted(arr)){
        cout << "\nArray is sorted : \n";
    }else{
        cout << "\nArray is not sorted : \n";
    }

    return 0;
}

bool IsSorted(struct Array arr){
    int i;
    for(i=0;i<= arr.length-2; i++){ // comparing upto second last element 
        if(arr.A[i]>arr.A[i+1]){
            return false;
        }
    }
    return true;
}

void Display(struct Array arr){
    cout << endl;
    for(int i = 0; i<arr.length;i++)
        cout << arr.A[i] << "\t";
}
