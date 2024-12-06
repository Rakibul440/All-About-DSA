#include <iostream>
using namespace std;

struct Array{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr);
int BinarySearch(struct Array arr,int key);
int RecursiveBinary(int A[],int low,int high,int key); 

int main(){
    struct Array arr = {{1,2,3,4,6,7,8,9,12,13,23,25,26,27,30},20,15};
    cout << "Original Array : " <<endl;
    Display(arr);

    cout << "\nElement 7 is in index : " << BinarySearch(arr,7) << endl;

    cout << "\nElement 23 is in index : " << RecursiveBinary(arr.A,0,arr.length-1,25) << endl;

    return 0;
}

void Display(struct Array arr){
    cout << endl;
    for(int i = 0; i<arr.length;i++)
        cout << arr.A[i] << "\t";
}

int BinarySearch(struct Array arr,int key){

    int low = 0;
    int high = arr.length-1;

    while(low <= high){
        int mid = (low + high)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if(key < arr.A[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return -1;

}

int RecursiveBinary(int A[],int low,int high,int key){
    int mid;
    if(low <= high){
        mid = (low + high)/2;
        if(key ==  A[mid]){
            return mid;
        }
        else if(key < A[mid]){
            RecursiveBinary(A,low,mid-1,key);
        }else if(key > A[mid]){
            RecursiveBinary(A,mid+1,high,key);
        }
    }
    else{
        
        return -1;
    }
}