#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
 * Problem: 2943. Maximize Square Hole Area
 * Approach:
 * 1. Sort horizontal and vertical bars.
 * 2. Find the longest consecutive sequence in both.
 * 3. The side of the square is min(maxH + 1, maxV + 1).
 * 4. Return side².
 */

 class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
           std::sort(hBars.begin(),hBars.end());
           std::sort(vBars.begin(),vBars.end());
           int gaph=1,maxh=1,maxv=1;
           for ( int i = 1; i < hBars.size(); i++)
           {
            if(hBars[i]==hBars[i-1]+1)
                gaph=gaph+1;
            else
                gaph=1;
            if(gaph>maxh)
                maxh=gaph;
           }
           gaph=1;
           for ( int i = 1; i < vBars.size(); i++)
           {
            if(vBars[i]==vBars[i-1]+1)
                gaph=gaph+1;
            else
                gaph=1;
            if(gaph>maxv)
                maxv=gaph;
           }
           return pow(std::min(maxh+1,maxv+1),2);
    }
};