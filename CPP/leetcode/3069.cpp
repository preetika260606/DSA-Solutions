#include<iostream>
#include<vector>;
#include<algorithm>
#include<array>
using namespace std;


vector<int>resultArray(vector<int>&nums){
    int n=nums.size();
    vector<int>arr1;
    vector<int>arr2;
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);

    for(int i=2;i<n;i++){
        if(arr1.back()>arr2.back()){
            arr1.push_back(nums[i]);
        }
        else(arr2.push_back(nums[i]));
    }
    for(int x:arr2){
        arr1.push_back(x);
    }
    return arr1;

}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>result=resultArray(nums);

    for(int x:result){
        cout<<x<<" ";
    }
}