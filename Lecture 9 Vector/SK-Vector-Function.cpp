#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> vec = {1,2,3};

    //size 
    cout << "size of the vector is : " << vec.size()<<endl;

    //front & back
    cout << vec.front() <<endl; // print first value
    cout << vec.back() <<endl; // print last value

    //push_back and pop_back
    vec.push_back(25); // add 25 last of the vector
    vec.push_back(35);

    vec.pop_back(); //delete last value 

    // at
    cout << "value at index 2 : " << vec.at(2) <<endl;

    for(int value : vec){
        cout << value << "\t";
    }
    cout << "\nsize : " << vec.size() <<endl;
    cout << "Capacity : " << vec.capacity() <<endl;

    return 0;
}