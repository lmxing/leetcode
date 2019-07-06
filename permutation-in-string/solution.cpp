
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1len = s1.length();
        int s2len = s2.length();
        if (s1len > s2len)  return false;
        vector<int> counts1(26,0);
        vector<int> counts2(26,0);
        vector<int> counts1_bk(26,0);
       
        unordered_map<int,int> map;
        for (int i = 0; i < s1len; ++i) {
            counts1[s1[i] - 'a']++;
            map[s1[i] - 'a'] ++;
        }
        for (int i = 0; i < s2len; ++i)
            counts2[s2[i] - 'a']++;
        for (int i = 0; i < 26; ++i) {
            if (counts2[i] < counts1[i]) return false;
        }
        int k = s1len;
        counts1_bk = counts1;
        for (int i = 0; i < s2len; ++i) {
            int j = 0;
            int l = i;
            counts1 = counts1_bk;
            while(j < s1len && l < s2len) {
                auto iter = map.find(s2[l] - 'a');
                if (iter == map.end()) break;
                counts1[iter->first]--;
                if (counts1[iter->first] < 0) break;
                l++;
                j++;
            }
			MY_LOG_PAIR("j", j)
            if (j == s1len) return true;
        }
        return false;
    }
};

int main()
{
	Solution sol;
	string s1 = "ab";
	string s2 = "eeesdbasdf";
	bool result = sol.checkInclusion(s1, s2);
	MY_LOG_PAIR("result: ", result)
	return 1;
}
