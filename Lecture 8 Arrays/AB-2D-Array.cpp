#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /*Static 2D Arrays --- we all know*/

    //Method 1.
    /*Dynamic 2D Array -- partial Stack partial Heap*/

        // creating a 3x3 matrix

    int *A[3]; //--Pointers of array in stack -- A has 3 rows

    A[0] = new int[3]; // A[0] has three column
    A[1] = new int[3]; // A[1] has three column
    A[2] = new int[3]; // A[2] has three column

    /*------------------------------------------------------------*/

    //Method 2 (using Double pointer).
    /*Dynamic 2D Array -- All in Heap*/

        // creating a 3x3 matrix

    int **B; // into stack
    B = new int*[3]; //into heap B has three rows

    B[0] = new int[3]; // B[0] has three column
    B[1] = new int[3]; // B[1] has three column
    B[2] = new int[3]; // B[2] has three column

    //Accessing ELements -- it'll gives garbage value bcz none of value has assigned yet;
     
    for(int i =0;i<3;i++){
        for(int j = 0; j<3;j++){
            cout<< B[i][j] << "\t";
        }
        cout << "\n";
    }
 

    return 0;
}
