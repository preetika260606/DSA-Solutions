#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//#include <bits/stdc++.h>

//tc:O(2n)
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int maxx = INT_MIN;

        for (int i = 0; i < n; i++) {

            int sum = 0;

            for (int j = i; j < n; j++) {

                sum += nums[j];
                maxx = max(maxx, sum);
            }
        }
        return maxx;
    }
int main(){
    
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};

    cout<<maxSubArray(nums);
}