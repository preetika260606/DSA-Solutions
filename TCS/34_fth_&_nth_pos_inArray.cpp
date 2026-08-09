// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

    int first(vector<int>& nums, int target) {

        int i = 0;
        int j = nums.size() - 1;
        int ans = -1;

        while(i <= j) {

            int mid = i + (j - i) / 2;

            if(nums[mid] == target) {
                ans = mid;
                j = mid - 1;       // go left
            }
            else if(nums[mid] < target) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }

        return ans;
    }


    int last(vector<int>& nums, int target) {

        int i = 0;
        int j = nums.size() - 1;
        int ans = -1;

        while(i <= j) {

            int mid = i + (j - i) / 2;

            if(nums[mid] == target) {
                ans = mid;
                i = mid + 1;       // go right
            }
            else if(nums[mid] < target) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }

        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {

        int firstPos = first(nums, target);
        int lastPos = last(nums, target);

        return {firstPos, lastPos};
    }
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;

    vector<int> result = searchRange(nums, target);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;

}