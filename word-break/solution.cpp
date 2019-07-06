
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int lens = s.length();
 
        vector<bool> dp(lens+1, false);
        dp[0] = true;
        std::unordered_set<string> set;
        for (int i = 0; i < wordDict.size(); ++i) 
            set.insert(wordDict[i]);

        for (int i = 1; i <= lens; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[j] && set.find(s.substr(j, i-j)) != set.end()) {
					MY_LOG(s.substr(j, i-j))
                    dp[i] = true;
                    break;
                }
            }
        }
		print(dp);
        return dp[lens];
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {1,2,3,4};
	string word = "leetcode";
	vector<string> dict = {"3333", "le", "et", "222", "code"};
	bool result = sol.wordBreak(word, dict);
	MY_LOG_PAIR("result", result)
	return 1;
}
