#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Time: O(n×amount)
//Space:O(n×amount)+O(amount+n)
    int solve(int amount,vector<int>&coins,int i,vector<vector<int>>&dp){
        if(amount==0) return 1;

        if(i==coins.size()) 
        return 0;

        if(dp[i][amount]!=-1) 
        return dp[i][amount];

        if(coins[i]>amount) 
        return dp[i][amount]=solve(amount,coins,i+1,dp);
        
        int take=solve(amount-coins[i],coins,i,dp);
        int not_take=solve(amount,coins,i+1,dp);
        return dp[i][amount]=take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }

int main(){

    int amount;
    cin>>amount;
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<change(amount,coins);
    return 0;
}