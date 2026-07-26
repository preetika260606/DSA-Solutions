#include<iostream>
#include<vector>
using namespace std;

//tabulation approach
bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>dp(n,false);

        //dp[i]=true; means we can reach to thee ith position
        //dp[i]=false;  means we cannot reach to the ith position

        dp[0]=true;

        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if (dp[j] && j + nums[j] >= i){
                    dp[i]=true;
                    break;
                }

            }
        }
        return dp[n-1];
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