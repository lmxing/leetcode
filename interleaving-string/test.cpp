
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
       // if (l1 + l2 != l3) return false;
        int count[256];
        for (int i = 0; i < l1; ++i) 
            count[s1[i]] ++;
        for (int i = 0; i < l2; ++i) 
            count[s2[i]] ++;
            
        for (int i = 0; i < l3; ++i) {
            count[s3[i]]--;
          //  if (count[s3[i]] < 0) return false;
        }
        int i = 0;
        int j = 0;
        int k = 0;
        while(k < l3) {
			MY_LOG_PAIR("k", k)
            if (i < l1 && s1[i] == s3[k]) {
				i++;
                k++;
            } else if (j < l2 && s2[j] == s3[k]) {
			    j++;
                k++;
            } else {
				MY_LOG_PAIR("sub s1", s1.substr(i, l1 - i))
				MY_LOG_PAIR("sub s2", s2.substr(j, l2 - j))
				MY_LOG_PAIR("sub s3", s3.substr(k, l3 - k))
           
				MY_LOG_PAIR("return i", i)
				MY_LOG_PAIR("return j", j)
				MY_LOG_PAIR("return k", k)
				MY_LOG_PAIR("return s3[k]", s3[k])
                return false;
            }
        }
        return true;
            
    }
};

int main()
{
	Solution sol;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	MY_LOG_PAIR("s1", s1)
	MY_LOG_PAIR("s2", s2)
	MY_LOG_PAIR("s3", s3)
	sol.isInterleave(s1, s2, s3);
	return 1;
}
