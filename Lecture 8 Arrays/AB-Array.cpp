#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int A[5] = {1,2,3,4,5}; // --- Inside Stack
    //Accessing Array Element
    cout << *(A + 2)<< endl; // using pointer # 3
    cout << A[2] <<endl;
    cout << 2[A] << endl;

    return 0;
}
