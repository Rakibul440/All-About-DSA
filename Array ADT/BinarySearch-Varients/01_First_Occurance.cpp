#include <iostream>
using namespace std;

struct Array {
    int A[20];
    int size;
    int length;
};

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


    return 0;
}

void Display(Array arr) {
    int i;
    for(i=0; i<arr.length; i++){
        cout << arr.A[i] << "\t" ;
    }
    cout << "\n";
}
