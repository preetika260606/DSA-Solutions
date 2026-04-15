// leetcode-07 Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Example 1:
// Input: x = 123
// Output: 321
// Example 2:
// Input: x = -123
// Output: -321
// Example 3:
// Input: x = 120
// Output: 21
// Constraints:
// -231 <= x <= 231 - 1

#include <iostream>
#include <limits>

// Problem: Reverse Integer
// Platform: LeetCode
// Approach: Digit Extraction + Overflow Check
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check overflow
            if (result > (std::numeric_limits<int>::max() - digit) / 10)
                return 0;

            if (result < (std::numeric_limits<int>::min() - digit) / 10)
                return 0;

            result = result * 10 + digit;
        }

        return result;
    }
};