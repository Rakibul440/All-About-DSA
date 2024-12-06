#include <iostream>
#include <vector> // vector header file
using namespace std;

int main(){

    //vector syntax
    //method -1

    vector<int> vec;   //0 -- vector declearation
    vec = {1,2,3};    // initialization
    cout << vec[0] << endl; // access value

    //method -2

    vector<int> vec_2 = {45,69,63}; // declearation and Initialization
    cout << vec_2[1] << endl;

    //method -3 
    // vector<data_type> vec(size,value)
    vector<int> vec_3(5,0); 

    for(int value : vec_3){   // for each loop
        cout << value << "\t";
    }


    return 0;
}

//tarminal command : g++ -std=c++11 fileName.cpp && ./a.exe