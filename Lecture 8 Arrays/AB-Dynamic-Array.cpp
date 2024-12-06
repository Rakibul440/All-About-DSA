#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /*  Array inside heap memory*/

    int *ptr; //created into stack
    ptr = new int[5]; // created into heap - Array with size 5 int;

    for (int i = 0; i < 5; i++)
    {
        cout << "ptr[" << i << "] : " ;
        cin >> ptr[i];
    }

    cout << "\nAll the elements of this array are : \n";
    for (int i = 0; i < 5; i++)
    {
        cout << "ptr[" << i << "] : " << ptr[i] << endl ;

    }
    
    cout << "Array size before delete : " << sizeof(ptr) <<endl;

    delete []ptr ; // deleting  memory  after work complete 

    cout << "Array size After delete : " << sizeof(ptr);
    return 0;
}
