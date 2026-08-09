#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int n = nums.size();
        int maxx = INT_MIN;
        int minn = INT_MAX;

        for (int i = 0; i < n; i++) {
            maxx = max(maxx, nums[i]);
            minn = min(minn, nums[i]);
        }

        int diff = maxx - minn;

        return 1LL * diff * k;
    }
};

int main(){
    vector<int> nums;
    int n;
    cin>>n;
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }

    Solution obj;
    cout<<obj.maxTotalValue(nums,1);
}