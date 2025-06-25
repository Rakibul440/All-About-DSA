#include <iostream>
using namespace std;

void Hanoi(int N, int A, int B, int C){
    static int totalSteps = 1;
    if( N > 0 ){
        Hanoi(N-1,A,C,B);
        cout << totalSteps++ << ". : " << A << " -> " << C << endl;
        Hanoi(N-1,B,A,C); 
    }
}

int main(){
    cout << "-----Tower of Hanoi Problems------\n" << endl;
    cout << "How many disk you have to transfar : " ; 
    int N;
    cin >>  N;

    cout << "The steps are shown below -> " << endl;
    Hanoi(N,1,2,3);
    return 0;
}