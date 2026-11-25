#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n ;
    cin >> n;

    vector<int> nums;
    for(int i = 0;i<n;i++){
       nums.push_back(i+1);
    }

    if(n>=2 && n<4){
        cout << "NO SOLUTION" << endl;
        return 0;
    }else{

        for(int i = 0; i<n;i+=2){
            int j = i+3;
    
            if(j==n){j--;};
            if(j==n+1){j-=2;}
            if(j<n){
               int temp = nums[i];
               nums[i] = nums[j];
               nums[j] = temp;
            }
        }
    }

    if(n==4){swap(nums[1],nums[0]);};

    for(auto x : nums){
        cout << x << " ";
    }

    return 0;
}