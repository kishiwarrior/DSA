#include <vector>
#include <algorithm>
using namespace std;

/*
 * Given bottom-left and top-right coordinates of axis-aligned rectangles,
 * this function finds the largest possible square area formed by the
 * intersection of any two rectangles.
 *
 * Approach:
 * - For every pair of rectangles, compute overlap along X and Y axes
 * - The largest square side is min(overlapX, overlapY)
 * - Track the maximum square area
 */
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();
        
        for (int i = 0; i < n; ++i) {
            int x1i = bottomLeft[i][0];
            int y1i = bottomLeft[i][1];
            int x2i = topRight[i][0];
            int y2i = topRight[i][1];
            
            for (int j = i + 1; j < n; ++j) {
                int x1j = bottomLeft[j][0];
                int y1j = bottomLeft[j][1];
                int x2j = topRight[j][0];
                int y2j = topRight[j][1];
                
                // Overlap along X and Y axes
                int overlapX = min(x2i, x2j) - max(x1i, x1j);
                int overlapY = min(y2i, y2j) - max(y1i, y1j);
                
                int side = min(overlapX, overlapY);
                if (side > 0) {
                    ans = max(ans, (long long)side * side);
                }
            }
        }
        
        return ans;
    }
};
