/*
Problem: LeetCode 3453 - Separate Squares I
Approach: Binary search on horizontal cut using area balance
Time Complexity: O(n log R)
Space Complexity: O(1)
*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double low = 1e9, high = -1e9;

        for (auto &sq : squares) {
            double y = sq[1];
            double side = sq[2];
            totalArea += side * side;
            low = min(low, y);
            high = max(high, y + side);
        }

        double target = totalArea / 2.0;

        for (int iter = 0; iter < 100; iter++) { // precision control
            double mid = (low + high) / 2.0;
            double areaBelow = 0.0;

            for (auto &sq : squares) {
                double y = sq[1];
                double side = sq[2];

                if (mid <= y) continue;
                else if (mid >= y + side)
                    areaBelow += side * side;
                else
                    areaBelow += side * (mid - y);
            }

            if (areaBelow >= target)
                high = mid;
            else
                low = mid;
        }

        return low;
    }
};
