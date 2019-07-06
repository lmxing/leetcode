
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int res = 0;
        if (len == 1) return 1;
        if (len == 0) return 0;
        deque<char> que;
        set<char> set;
        que.push_back(s[0]);
        set.insert(s[0]);
        for (int i = 1; i < len; ++i) {
            auto iter = set.find(s[i]);
            if (iter != set.end()) {
                while (que.front() != s[i]) {
                    int tmp = que.front();
                    que.pop_front();
                    set.erase(tmp);
                }
                    que.pop_front();
                    set.erase(s[i]);
            }
            set.insert(s[i]);
            que.push_back(s[i]);
			print(set);
			MY_LOG(s);
            if (set.size() > res) {
                res = set.size();
        	}
			std::cout << "ret " << res << " len " << len << std::endl;
		}
        return res;
    }
};

int main()
{
	Solution sol;
	//string s = "abcabcbb";
	string s = "aabaab!bb";
	int ret = sol.lengthOfLongestSubstring(s);
	std::cout << "ret: " << ret << std::endl; 
	return 1;
}
