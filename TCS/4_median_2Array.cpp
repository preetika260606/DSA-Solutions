#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for(int i : nums1) {
            ans.push_back(i);
        }

        for(int i : nums2) {
            ans.push_back(i);
        }

        sort(ans.begin(), ans.end());

        int n = ans.size();

        // Odd
        if(n % 2 != 0) {
            return ans[n / 2];
        }

        // Even
        return (ans[n / 2] + ans[n / 2 - 1]) / 2.0;
    }
int main(){
    int n;
    cin>>n;
    vector<int>num1(n);
    for(int i=0;i<n;i++){
        cin>>num1[i];
    }

    int m;
    cin>>m;
    vector<int>num2(m);
    for(int i=0;i<m;i++){
        cin>>num2[i];
    }

    cout<<findMedianSortedArrays(num1,num2);
    return 0;

}