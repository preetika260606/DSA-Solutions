#include<iostream>
#include<vector>
using namespace std;    


//Time Complexity: O(n)
int solve(vector<int>&nums,int index,int n,vector<int>&dp){
    if(index>=n) return 0;

    if(dp[index]!=-1) return dp[index];

    int take=nums[index]+solve(nums,index+2,n,dp);
    int not_take=solve(nums,index+1,n,dp);

    return dp[index] = max(take, not_take);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,n,dp);
    }


int main(){
    
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << rob(nums);

    return 0;
}