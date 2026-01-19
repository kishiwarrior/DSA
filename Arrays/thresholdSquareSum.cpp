#include <vector>
#include <algorithm>

using namespace std;

/*
Problem Description (LeetCode 1292):

You are given a 2D matrix `mat` of positive integers and an integer `threshold`.

Return the maximum side length of a square submatrix such that the sum of all
elements inside the square is less than or equal to `threshold`.

If no such square exists, return 0.

Approach Summary:
- Build a 2D prefix sum array to allow O(1) submatrix sum queries.
- Binary search on the side length of the square.
- For each candidate side length k, check whether there exists at least one
  k x k square whose sum is <= threshold.
- Use the monotonic property: if size k is valid, all sizes < k are also valid.
*/

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        // 2D prefix sum: ps[i][j] = sum of submatrix (0,0) to (i-1,j-1)
        vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                ps[i][j] = mat[i - 1][j - 1]
                         + ps[i - 1][j]
                         + ps[i][j - 1]
                         - ps[i - 1][j - 1];
            }
        }

        // Checks if any k x k square has sum <= threshold
        auto valid = [&](int k) {
            for (int i = 0; i + k <= n; ++i) {
                for (int j = 0; j + k <= m; ++j) {
                    int sum = ps[i + k][j + k]
                            - ps[i][j + k]
                            - ps[i + k][j]
                            + ps[i][j];
                    if (sum <= threshold) return true;
                }
            }
            return false;
        };

        int lo = 0, hi = min(n, m), ans = 0;

        // Binary search on square side length
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (valid(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
