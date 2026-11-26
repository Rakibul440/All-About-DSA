#include <iostream>
#include <bits/stdc++.h>

using namespace std;


vector<int> plusOne(vector<int>& digits) {
    vector<int> nums;
    digits[digits.size()-1]++;

    int extra = 0;
    for(int i = digits.size()-1;i>=0;i--){
        if(digits[i]+extra>=10){
            nums.push_back(digits[i]+extra-10);
            extra = 1;
        }else{
            nums.push_back(digits[i]+extra);
            extra = 0;
        }
    }
    if(extra>0) nums.push_back(extra);

    reverse(nums.begin(),nums.end());
    return nums;
}
    
int main(){
    vector <int> arr = {9,9};
    vector<int> result = plusOne(arr);

    return 0;
}