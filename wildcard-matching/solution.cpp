
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        //return isMatch(s, 0, p, 0);
        int l1 = s.size();
        int l2 = p.size();
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l2+1, false));
        dp[0][0] = true;
        for (int j = 1; j <= l2; j++) {
            if (p[j-1] == '*') dp[0][j] = true;
            else break;
        }
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[l1][l2];
    }
    bool isMatch(string & s,int s1, string & p, int s2) {
        int l1 = s.size() - s1;
        int l2 = p.size() - s2;
        if (l1 == l2 && l1==0) return true;
        if (l1 >0 && l2 == 0) return false;
        if (l1 ==0 && l2 > 0) {
            while(s2 < p.size() && p[s2] == '*') s2++;
            return s2 == p.size();
        }
        if (s[s1] == p[s2]) {
            return isMatch(s, s1+1, p, s2+1);
        }
        if (p[s2] == '?') {
            return isMatch(s, s1+1, p, s2+1);
        }
        if (p[s2] == '*') {
            while(s2< p.size() && p[s2] == '*') s2++;
            s2--;
            for (int i = 0; i <= l1;i++) {
                if (isMatch(s, s1+i, p, s2+1)) return true;
            }
        }
        return false;
    }
};

int main()
{
	Solution sol;
	string s = "aa";
	string p = "*";
	int result = sol.isMatch(s, p);
	MY_LOG_PAIR("result", result)
	return 1;
}
