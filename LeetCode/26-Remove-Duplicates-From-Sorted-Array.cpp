#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    vector<int> arr;

    for(int i = 0, j = 1; i < nums.size(); i++,j++){
        if(j != nums.size() && nums[i] != nums[j]){
            arr.push_back(nums[i]);
        }
    }

    arr.push_back(nums[nums.size()-1]);

    for(int x : arr){
        cout << x << " ";
    }

    return arr.size();
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int result = removeDuplicates(nums);
    cout << "\nResult : " << result << endl;
    return 0;
}