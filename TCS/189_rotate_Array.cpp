#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateArray(vector<int>& nums, int k) {

    int n = nums.size();

    if(n == 0)
        return;

    k = k % n;

    reverse(nums.begin(), nums.end());

    reverse(nums.begin(), nums.begin() + k);

    reverse(nums.begin() + k, nums.end());
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    rotateArray(nums, k);

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}