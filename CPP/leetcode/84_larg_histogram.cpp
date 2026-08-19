#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        stack<int> st;

        // Right smaller element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        // Left smaller element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int width = right[i] - left[i] - 1;

            int area = heights[i] * width;

            ans = max(ans, area);
        }

        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>heights(n);

    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

    Solution s;
    cout<<s.largestRectangleArea(heights)<<endl;

}