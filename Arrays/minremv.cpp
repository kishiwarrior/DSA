class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0;
        int maxLen = 1;

        for (int r = 0; r < n; r++) {
            while ((long long)nums[r] > (long long)nums[l] * k) {
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }

        return n - maxLen;
    }
};
