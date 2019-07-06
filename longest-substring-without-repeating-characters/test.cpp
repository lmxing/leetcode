
#include "../my_include.h"
#include "../my_util.h"

class Solution
{
public: 
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        // 记录字符上一次出现的位置
        int last[512] = {-1};
       	for (int i = 0; i < 512; ++i) last[i] = -1; 
        int res = 0;
        int start = 0; // 窗口开始位置
        for (int i = 0; i < n; ++i) {
			std::cout<< s << std::endl;
     	std::cout << " s[i] " << s[i]<< " last[s[i]] " << last[s[i]] << "  i " << i <<  " res " << res << " start " << start << std::endl;      
           start = max(start, last[s[i] - '0'] + 1);
           
           res = max(res, i - start + 1);
           last[s[i] - '0'] = i;
     	std::cout << " s[i] " << s[i]<< " last[s[i]] " << last[s[i]] << "  i " << i <<  " res " << res << " start " << start << std::endl;      
			for (int k = start; k <= i; ++k) std::cout << s[k];
			std::cout<< "\n";
        }
        return res;
    }
};

int main()
{
	Solution sol;
	string str = "abcabcbb";
	int rest = sol.lengthOfLongestSubstring(str);
	std::cout << rest << std::endl;
	return 1;
}
