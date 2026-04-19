#include <iostream>

using namespace std;

struct Array {
    int A[20];
    int size;
    int length;
};

void Display(Array arr);
int BinarySearch(Array arr,int target);
int RecursiveBinarySearch(Array arr,int low, int high ,int target);


int main(){

    struct Array arr = {
        {2,4,6,8,10,12,14,16,18,20},
        20,
        10
    };
    cout << "=========Original Array===========\n";
    Display(arr);

    cout << "Which Element You Want To Search : ";
    int target;
    cin >> target;

    // int index = BinarySearch(arr,target);
    int index = RecursiveBinarySearch(arr,0,arr.length-1,target);
    if(index == -1){
        cout << "Not Found!\n";
        return 0;
    }

    cout << "The Number " << target << " is at index " << index << endl;


    return 0;
}

int RecursiveBinarySearch(Array arr ,int low, int high,int target){


    if(low <= high){
        int mid = low + (high - low )/2;
        if(target == arr.A[mid]) return mid;
        else if(target > arr.A[mid]) return RecursiveBinarySearch(arr, mid+1, high, target);
        else return RecursiveBinarySearch(arr,low,mid-1,target);
    }
    else return -1;
}

int BinarySearch(Array arr, int target){
    int low = 0;
    int high = arr.length - 1;
    
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        if(target == arr.A[mid]) return mid;
        else if( target > arr.A[mid]) low = mid + 1;
        else high = mid -1;
    }

    return -1;
    
}

void Display(Array arr) {
    int i;
    for(i=0; i<arr.length; i++){
        cout << arr.A[i] << "\t" ;
    }
    cout << "\n";
}