#include<iostream>
#include<vector>

using namespace std;

int solve(int amount,vector<int>&coins,int i){
        if(amount==0) return 1;
        if(i==coins.size()) return 0;
        if(coins[i]>amount) return solve(amount,coins,i+1);
        
        int take=solve(amount-coins[i],coins,i);
        int not_take=solve(amount,coins,i+1);
        return take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        return solve(amount,coins,0);
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