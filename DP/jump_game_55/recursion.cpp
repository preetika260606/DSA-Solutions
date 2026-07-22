#include<iostream>
#include<vector>


using namespace std;
bool solve(vector<int>&nums,int index,int n){
        if(index==n-1){
            return true;
        }
        if(index>=n){
            return false;
        }

        for(int i=1;i<=nums[index];i++){
            if(solve(nums,index+i,n)==true)
            return true;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n);
    }

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << canJump(nums);

    return 0;
}