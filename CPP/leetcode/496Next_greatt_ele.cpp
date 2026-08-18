#include <iostream>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;

    for (int i = 0; i < nums1.size(); i++) {

        // Find nums1[i] in nums2
        int j = 0;
        while (j < nums2.size() && nums2[j] != nums1[i]) {
            j++;
        }

        // If element is not found
        if (j == nums2.size()) {
            ans.push_back(-1);
            continue;
        }

        // Find the next greater element
        int greater = -1;
        for (int k = j + 1; k < nums2.size(); k++) {
            if (nums2[k] > nums1[i]) {
                greater = nums2[k];
                break;
            }
        }

        ans.push_back(greater);
    }

    return ans;
}
                          OR
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums2.size(); i++) {

            while(!st.empty() && nums2[i] > nums2[st.top()]) {

                mp[nums2[st.top()]] = nums2[i];

                st.pop();
            }

            st.push(i);
        }
        while(!st.empty()) {
            mp[nums2[st.top()]] = -1;
            st.pop();
        }

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }

    
int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> nums1(n1);
    vector<int> nums2(n2);

    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    vector<int> result = nextGreaterElement(nums1, nums2);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}