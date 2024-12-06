#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /*Increase Array Size*/
    //step 1
    int *p = new int[5];  // -first array
    p[0] = 15;
    p[1] = 19;
    p[2] = 14;
    p[3] = 12;
    p[4] = 15;

    // step 2 -- for  Increase need another array 
    int *q = new int[10];

    //step 3 -- copying all element p to q
    int i;
    for(i = 0; i<5; i++){
        q[i] = p[i];
    }
    //step 4 
    delete []p;
    p = q;
    q = NULL;

    // Assign other element 
    for(i=5;i<10;i++){
        cout << "p[" << i << "] : " ;
        cin >> p[i];
    }
    // Printing The New Array
    cout<< "\nNew Array is : \n";
    for(i=0;i<10;i++){
        cout <<  "p[" << i << "] : "<< p[i] << endl;
    }


    return 0;
}
