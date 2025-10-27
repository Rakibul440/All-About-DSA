#include <iostream>
using namespace std;


struct Array {
    int A[20];
    int size ;
    int length;
};

void Display (Array arr);
int LastOccurance(Array arr, int target);


int main (){
    struct Array arr = {
        {2,4,6,8,8,8,10,12,14,20},
        20,
        10
    };

    cout << "=========Original Array===========\n";
    Display(arr);

    cout << "Which Element You Want To Search : ";
    int target;
    cin >> target;

    int index = LastOccurance(arr,target);

    if(index == -1){
        cout << "Not Found!\n";
        return 0;
    }

    cout << "The Number " << target << " is at index (Last occurance) : " << index << endl;


    return 0;
}

int LastOccurance(Array arr, int target){
    int low = 0;
    int high = arr.length -1 ;
    int index = -1;

    while (low<=high)
    {   
        int mid = low + (high-low)/2;
        if(arr.A[mid] == target){
            index = mid;
            low = mid + 1; // continue searching right
        }
        else if(arr.A[mid] > target) high = mid -1;
        else low = mid + 1;
    }
    return index;
    
}

void Display(Array arr) {
    int i;
    for(i=0; i<arr.length; i++){
        cout << arr.A[i] << "\t" ;
    }
    cout << "\n";
}
