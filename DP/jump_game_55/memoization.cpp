#include<iostream>
#include<vector>
using namespace std;

    bool solve(vector<int>&nums,int index,int n,vector<int>&dp){
        if(index==n-1){
            return true;
        }
        if(index>=n){
            return false;
        }
        if(dp[index]!=-1){
            return dp[index];
        } 

        for(int i=1;i<=nums[index];i++){
            if(solve(nums,index+i,n,dp))
            return dp[index] = true;
        }
        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
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

    cout << canJump(nums);

    return 0;
}