#include <iostream>
using namespace std;

void print_unique(int arr[],int n);

int main(int argc, char const *argv[])
{
    int arr[7] = {1,2,3,1,3,6,1};
    print_unique(arr,7);
    return 0;
}

void print_unique(int arr[],int n){
    int i,j;

    for(i = 0; i<n ; i++){
        bool isUnique = true;
        for(j = 0; j<i; j++){
            if(arr[i]==arr[j]){
                isUnique = false;
                break;
            }
            
        }

        if(isUnique){
            cout << arr[i] <<"\t";
        }
    }

}