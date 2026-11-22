#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// find primes upto x;
vector<int> primes(int);

int main(){
    vector<int> allprimes = primes(30);

    for(int x : allprimes){
        cout << x << " ";
    }

    return 0;
}

vector<int> primes(int x){
    vector<bool> primes(x+1,true);
    vector<int> result;

    for(int i = 2; i*i<=x;i++){
        if(primes[i]==true){
            for(int j = i*i;j<=x;j+=i){
                primes[j] = false;
            }
        }
    }

    for(int i = 2;i<=x;i++){
        if(primes[i]==true){
            result.push_back(i);
        }
    }

    return result;
}
