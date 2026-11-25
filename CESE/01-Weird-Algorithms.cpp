#include <iostream>

using namespace std;

int main(){
    long long int input;
    cin >> input;

    cout << input << " ";
    while(input > 1){
        if(input % 2 == 0){
            input = input /2;
        }else{
            input = 3 * input + 1;
        }
        cout << input << " ";

    }
}