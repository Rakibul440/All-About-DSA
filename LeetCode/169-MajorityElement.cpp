#include <iostream>
#include <bits/stdc++.h>

/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

using namespace std;

int majorityElement(vector<int>& nums) {
    int Mn = 0,count = 0,i = 0;

    sort(nums.begin(),nums.end());

    if(nums.size() <= 1) return nums[i];

    while(count < nums.size()/2){
        if(nums[i] != nums[i+1]) {
            Mn = nums[i];
            if(count > nums.size()/2) return Mn;
            count = 0;
            i++;
        };
        Mn = nums[i];
        count++;
        i++;
    }
    return Mn;
}

int main(){
    vector<int> arr = {1,1,5,5,3,3,3,3,3};
    int result = majorityElement(arr);

    cout << result << endl;
    return 0;
}