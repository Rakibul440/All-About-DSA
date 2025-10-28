/* If the target is not found, 
return the index where it should be inserted to maintain sorted order. */

#include <iostream>
using namespace std;

struct Array {
    int A[20];
    int size;
    int length;
};

void Display(Array arr);
int SearchInsertPosition(Array arr, int target);
void Insert(Array *arr,int key, int index);


int main(){

    Array arr = {{10,20,30,40,50,60,70,80,90,100},20,10};

    cout << "=========Original Array===========\n";
    Display(arr);

    cout << "Which Element You Want To Search : ";
    int target;
    cin >> target;

    int index = SearchInsertPosition(arr,target);

    cout << "Target index is/should be : " << index <<endl;

    return 0;
}

int SearchInsertPosition(Array arr, int target){
    int low = 0;
    int high = arr.length -1;
    int isElementPresent = false;

    while (low <= high) 
    {
        int mid = low + (high-low)/2;

        if(arr.A[mid] == target) {
            
            isElementPresent = true;
            return mid;
        }
        else if(arr.A[mid] > target) high = mid -1;
        else low = mid + 1;
    }
    
    if(!isElementPresent) {
        cout << "Not Found!\n";
        Insert(&arr,target, low);
    };
    return low;
}

void Insert(Array *arr, int key, int index){
    for(int i = arr->length; i > index; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = key;
    arr->length++;

    cout << "======After Insert=======\n";
    Display(*arr);
}

void Display(Array arr) {
    int i;
    for(i=0; i<arr.length; i++){
        cout << arr.A[i] << "\t" ;
    }
    cout << "\n";
}