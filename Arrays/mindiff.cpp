#include <vector>
#include <algorithm>

using namespace std;

/*
Approach:
- Sort the array to bring closest elements together.
- Traverse once to find the minimum absolute difference.
- Traverse again to collect all pairs with that minimum difference.

Time Complexity:
- O(n log n) due to sorting.

Space Complexity:
- O(1) extra space (excluding the output vector).
*/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int m=abs(arr[0]-arr[1]);
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            m=min(m,abs(arr[i+1]-arr[i]));
        }
        for(int i=0;i<arr.size()-1;i++){
            if(abs(arr[i+1]-arr[i])==m)
                ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};