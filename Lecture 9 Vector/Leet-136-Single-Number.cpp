#include <iostream>
// #include <vector>

using namespace std;

int singleNum ( int numbers[],int n);

int main(){
    int numbers[7] = {1,2,3,1,2,3,69};
    int single_Num = singleNum(numbers,7);

    cout << "Single number is : " << single_Num << endl;

    return 0;
}

int singleNum ( int numbers[],int n){
    int singleNum = 0;
    for(int i = 0;i<n;i++){
        singleNum ^= numbers[i];
    }

    return singleNum;
}
