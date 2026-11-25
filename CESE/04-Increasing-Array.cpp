#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin >> nums[i];
    }

    int moves = 0;
    for(int i = 1;i<n;i++){
        if(nums[i]<nums[i-1]){

            int j = i;
            while(j>0 && nums[j]<nums[j-1]){
                int temp = nums[j-1];
                nums[j-1] = nums[j];
                nums[j] = temp;
                j--;
                moves++;
            }
        }
    }

    cout << "Total Moves " << moves << endl;

    for(int x : nums){
        cout << x << " ";
    }


    return 0;
}