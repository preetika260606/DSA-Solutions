#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>&nums,int target){
    unordered_map<int,int>mp;

    for(int i=0;i<nums.size();i++){
        int digit=target-nums[i];

        if(mp.find(digit)!=mp.end()){
            return {mp[digit],i};
        }

        mp[nums[i]]=i;
    }
    
    return {};
}
int main(){
    vector<int>nums={2,7,11,15};
    int target=9;

    vector<int>result=twoSum(nums,target);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    } 

}