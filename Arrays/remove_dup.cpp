#include <iostream>
#include <vector>
using namespace std;

/*
------------------------------------------------------
🔹 Problem: Remove Duplicates from Sorted Array
🔹 LeetCode: 26
🔹 Difficulty: Easy
------------------------------------------------------

🧠 Approach: Two Pointer Technique

- Since the array is sorted, duplicates are adjacent.
- Use pointer 'i' to track position of last unique element.
- Traverse array using pointer 'j'.
- If nums[j] != nums[i], increment 'i' and update nums[i].

------------------------------------------------------

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)
------------------------------------------------------
*/

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int i = 0; // index of last unique element

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}

// Driver code (for testing)
int main() {
    vector<int> nums;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int k = removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}