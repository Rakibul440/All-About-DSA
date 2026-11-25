#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> nums(n-1);
    for(int i = 0; i < n - 1 ;i++){
        cin >> nums[i];
    }
    
    sort(nums.begin(),nums.end());

    // if first one missing
    if(nums[0] != 1){
        cout << 1;
        return 0;
    }

    for(int i = 1; i< n-1;i++){
        if(nums[i] - nums[i-1] != 1){
            cout << nums[i-1] +1;
            return 0;
        }
    }

    // if last one missing
    cout << n;

    return 0;

}