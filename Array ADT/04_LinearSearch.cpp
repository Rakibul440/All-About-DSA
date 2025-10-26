#include <iostream>
using namespace std;

struct Array {
    int A[10];
    int size ;
    int length;
};

int LinearSearch(Array arr, int key);

int main(){

    Array arr = {
        {12,45,30,5,8},
        10,
        5
    };

    cout << "Which Element you want to search :";
    int key;
    cin >> key;

    LinearSearch(arr,key);

    return 0;
}

int LinearSearch(Array arr, int key){
    int i ;
    for(i = 0; i < arr.length; i++){
        if (key == arr.A[i])
        {   
            cout << "Element is found at index " << i << endl;
            return i;
        }
        
    }
    cout << "Element isn't found!";
    return -1;
}