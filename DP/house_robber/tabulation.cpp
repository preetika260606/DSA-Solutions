#include<iostream>
#include<vector>
using namespace std;


//Time Complexity=O(n)​
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int>t(n+1,0);

        //t[i]=max stolen money till ith house

        t[0]=0;
        t[1]=nums[0];

        for(int i=2;i<=n;i++){
            int take=nums[i-1]+t[i-2];
            int not_take=t[i-1];

            t[i]=max(take,not_take);
        }

        return t[n];
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