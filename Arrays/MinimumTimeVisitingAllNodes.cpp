/*
LeetCode 1266 - Minimum Time Visiting All Points
Approach: Greedy (Chebyshev distance)
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int t=0;
        int x,y;
        for ( int i = 0; i < points.size()-1; i++)
        {
            x=abs(points[i+1][0]-points[i][0]);
            y=abs(points[i+1][1]-points[i][1]);
            t=t+max(x,y);
        }
        return t;
    }
};