#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>> result;
    void twoSum(vector<int>& nums, int target, int i, int j) {

        while(i < j) {

            int sum = nums[i] + nums[j];

            if(sum > target) {
                j--;
            }
            else if(sum < target) {
                i++;
            }
            else {

                result.push_back({
                    -target,
                    nums[i],
                    nums[j]
                });

                i++;
                j--;

                // Skip duplicate left values
                while(i < j && nums[i] == nums[i - 1])
                    i++;

                // Skip duplicate right values
                while(i < j && nums[j] == nums[j + 1])
                    j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        if(n < 3)
            return {};

        result.clear();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++) {

            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i];

            twoSum(nums, target, i + 1, n - 1);
        }

        return result;
    }
int main(){
    int n;
    cin>>n;
    vector<int>nums;
    nums.resize(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<vector<int>> result = threeSum(nums);

    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

}