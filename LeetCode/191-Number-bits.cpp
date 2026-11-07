#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int hammingWeight(int n) {
    int count = 0;

    while(n>=1){
        cout << n%02 ;
        if(n%2==1)count++;
        n /=2;
    }

    cout << "\n";

    return count;

}

int main(){
    int n = 2147483645;
    int result = hammingWeight(n);
    cout << result << endl;
    return 0;
}