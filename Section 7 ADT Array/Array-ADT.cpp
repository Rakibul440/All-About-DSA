#include <iostream>
using namespace std;

//define a structure of an Array

struct Array{
    int *A;
    int size;
    int lenght;
};

void Display(struct Array arr);
void Append(struct Array *arr , int x);

int main(int argc, char const *argv[])
{
    struct Array arr;
    cout << "Set size of the array : ";
    cin >> arr.size;
    
    arr.A = new int[arr.size];
    arr.lenght = 0;

    int i , n;
    cout << "Enter how many numbers : " ;
    cin >> n;

    cout << "Enter all elements : \n";
    for(i = 0;i < n; i++){
        cout << "Element " << i << " : ";
        cin >> arr.A[i]; 
    }

    arr.lenght = n;

    Display(arr);

    return 0;
}

void Display(struct Array arr){
    cout << "\nPrint All elements \n";
    for(int i = 0; i<arr.lenght;i++)
        cout << arr.A[i] << "\t";
}

void Append(struct Array *arr , int x){
    
}
