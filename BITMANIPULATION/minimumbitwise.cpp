#include <vector>
using namespace std;

/*
LeetCode 3314. Minimum Bitwise Array   

Approach:
For each number nums[i], we want to find the minimum value ans[i] such that:
(ans[i] | (ans[i] + 1)) == nums[i]

Observations:
- If nums[i] == 2, no such value exists → answer is -1.
- Otherwise, we try to flip the lowest possible bit in nums[i].
- We scan bits from LSB to MSB.
- If bit (b+1) is 0, we flip bit b using XOR.
- The first valid flip gives the minimum possible value.

Time Complexity:
O(n * 31) → effectively O(n)

Space Complexity:
O(n)
*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 2) {
                ans[i] = -1;
            } else {
                for (int b = 0; b < 31; b++) {
                    // Find the first position where next bit is 0
                    if (!((nums[i] >> (b + 1)) & 1)) {
                        ans[i] = nums[i] ^ (1 << b);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
