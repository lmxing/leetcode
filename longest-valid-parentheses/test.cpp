
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int len = s.length();
        if (len <= 1) return 0;
        int sublen = 0;
        int max_len = -1;
        stack<int> stk;
        vector<int> mark(s.length());
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (stk.empty()) mark[i] = 1;
                else stk.pop();
            }
        }
        while (!stk.empty()) {
            mark[stk.top()] = 1;
            stk.pop();
        }
		print(mark);
        for (int i = 0; i < len; ++i) {
            if (mark[i] == 1) {
                sublen = 0;
                continue;
            } 
            sublen++;
            max_len = max(max_len, sublen);
        }
        return max_len;
    }
};

int main()
{
	Solution sol;
	string s = "()()())";
	std::cin>>s;
	int ret = sol.longestValidParentheses(s);
	MY_LOG(ret)
	return 1;
}
