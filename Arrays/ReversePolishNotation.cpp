/*
Problem: LeetCode Q.2. of stack in Quest
Platform: LeetCode
Data Structures: stack
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int val=0;
        for(string c: tokens){
            if(c!="+" && c!="-" && c!="*" && c!="/")
            {
                s.push(stoi(c));
            }
            else
            {
                int a=s.top(); s.pop();
                int b=s.top(); s.pop();
                if(c=="/")
                {
                    s.push(b/a);
                }
                if(c=="*")
                {
                    s.push(b*a);
                }
                if(c=="+")
                {
                    s.push(b+a);
                }
                if(c=="-")
                {
                    s.push(b-a);
                }
            }
        }
        return s.top();
    }
};