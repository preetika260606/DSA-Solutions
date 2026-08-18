#include<iostream>
#include<vector>
using namespace std;

int largestInteger(vector<int>&nums,int k){
    int n=nums.size();
    int ans=-1;

    for(int x=0;x<n;x++){
        int count=0;
        for(int i=0;i<=n-k;i++){
            for(int j=i;j<i+k;j++){
                if(nums[j]==nums[x]){
                    count++;
                    break;
                }
            }
        }
        if(count==1) ans=max(ans,nums[x]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int k;
    cin>>k;
    cout<<largestInteger(nums,k)<<endl;

}