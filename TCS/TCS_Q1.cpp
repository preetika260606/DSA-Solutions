//Problem Description
// A logistics system tracks target order numbers set at every hour of the day. You are given an integer N representing total hours, followed by an array targets of size N, where targets[i] represents the target order set at hour i.Due to database sync issues, target numbers from earlier hours repeat in later hours.For every target number that repeats in the array:Track its occurrence count on the left side as you move left to right (1 for 1st time, 2 for 2nd time, 3 for 3rd time, etc.). 

// Calculate and print the total sum of these occurrence counts for all repeating target numbers.

// Input Format
// Line 1: An integer N representing total hours.Line 2: N space-separated integers representing targets[0], targets[1], ..., targets[N-1].

// Output Format
// Print a single integer representing the sum of occurrence counts.

// Test Case 1.
// 5
// 1 2 2 3 3   ----> for 2     we will calculate as  1(for first occurance of 2+ + 2 (for 2nd Occurance)
// 			    i.e.  1+2 (sum of natural numbers)= 2*(2+1)/2=3

// output 6

// 2 repeated 2 times
// 3 repeated 2 times

// ans 2*(2+1)/2  +  2*(2+1)/2 = 6

// Test Case 2:
// 6
// 4 4 5 5 6 6
// output 9

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;


int solve(vector<int>&nums,int n){

    unordered_map<int,int>mp;
    int ans=0;

    for(int i=0;i<n;i++)
    {
        mp[nums[i]]++;
    }

    for(auto it:mp)
    {
        int count=it.second;
        if(count>1)
        {
            ans+=count*(count+1)/2;
        }   
    }

    return ans;
}
int countOcurrence(vector<int>&nums){
    int n=nums.size();
    return solve(nums,n);
}
int main(){
    int m;
    cin>>m;
    vector<int>nums(m);

    for(int i=0;i<m;i++){
        cin>>nums[i];
    }
    cout<<countOcurrence(nums)<<endl;
}