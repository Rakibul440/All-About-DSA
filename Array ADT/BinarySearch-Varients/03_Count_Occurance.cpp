#include <iostream>
using namespace std;

struct Array {
    int A[20];
    int size;
    int length;
};

void Display(Array arr);
int FirstOccurance(Array arr, int target);
int LastOccurance(Array arr , int target);

int Occurance(Array arr , int target);

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

    int count = LastOccurance(arr,target) - FirstOccurance(arr,target) + 1;

    int count_2 = Occurance(arr, target);

    if(count_2 == 0) {
        cout << "Element Not Found!\n";
        // return 0;
    }

    if(LastOccurance(arr,target) == -1 || FirstOccurance(arr,target) == -1){
        cout << "Element Not Found!\n";
        return 0;
    }

    cout << "The Number " << target << " is repeated by  : " << count << " times" << endl;
    cout << "The Number " << target << " is repeated by  : " << count_2 << " times" << endl;


    return 0;
}

int Occurance(Array arr , int target){
    int count = 0;
    for(int i = 0; i < arr.length -1 ; i++){
        if(arr.A[i] == target) count++;
    }
    return count;
}

int LastOccurance(Array arr , int target){
    int low = 0,
    high = arr.length - 1,

    index = -1;
    while (low<=high)
    {
        int mid = low + (high - low)/2;

        if(arr.A[mid] == target){
            index = mid;
            low = mid + 1;
        }
        else if(arr.A[mid] > target) high = mid -1;
        else low = mid + 1;
    }
    return index;
    
}

int FirstOccurance(Array arr, int target){
    int low = 0,
    high = arr.length -1,

    index = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(arr.A[mid] == target){
            index = mid;
            high = mid -1;
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

