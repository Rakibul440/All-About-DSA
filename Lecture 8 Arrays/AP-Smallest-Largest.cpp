#include <iostream>
using namespace std;

int find_largest(int numbers[],int n);
int find_smallest(int numbers[],int n);
int find_index(int numbers[],int value,int n);

int main(int argc, char const *argv[])
{
    int numbers[] = {1,15,12,78,0,-12};
    int total_num = sizeof(numbers)/sizeof(int);
    
    int largest = find_largest(numbers,total_num);
    int smallest = find_smallest(numbers,total_num);
    int indexOfLargest = find_index(numbers,largest,total_num);
    int indexOfSmallest = find_index(numbers,smallest,total_num);
    cout << "The largest number among those is " << largest << " at " <<indexOfLargest <<" position" <<endl;
    cout << "The Smallest number among those is " << smallest << " at " <<indexOfSmallest <<" position" <<endl;

    return 0;
}

int find_largest(int numbers[],int n){
    int largest = INT32_MIN,i;
    for(i = 0; i < n; i++){
        if(numbers[i] > largest){
            largest = numbers[i];
        }
    }

    return largest;
}

int find_smallest(int numbers[],int n){
    int smallest = INT32_MAX,i;
    for(i = 0; i < n; i++){
        if(numbers[i] < smallest){
            smallest = numbers[i];
        }
    }

    return smallest;
}

int find_index(int numbers[], int value,int n){
    int index,i;
    for(i = 0; i< n ; i++){
        if(numbers[i] == value){
            index = i;
            break;
        }
    }

    return index;
}