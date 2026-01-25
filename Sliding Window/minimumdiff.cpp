 /*Approach
1. Sort the array.
2. Use a sliding window of size `k`.
3. For each window, calculate the difference between the maximum and minimum element.
4. Keep track of the minimum difference.
 Complexity
- Time Complexity: **O(n log n)** due to sorting.
- Space Complexity: **O(1)** (excluding input storage).
*/
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=k-1,m=nums[r]-nums[l];
        while(r<nums.size())
        {
            m=min(m,nums[r]-nums[l]);
            l++;
            r++;
        }
        return m;
    }
};