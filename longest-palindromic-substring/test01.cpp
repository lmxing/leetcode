#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {

public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len <=1) return s;
        int maxL = 1;
        string res;
        int A[1003][1003] = {0};
        for (int i = 0; i <= len; ++i)
            A[i][i] = 1;
        int start = 0;
        int right = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j <= len; ++j) {
                if (s[i] == s[j]) {
                    if (j - i == 1) {
                        A[i][j] = 1;
                        if (j-i +1 > maxL) {
                            start = i;
                            right = j;
                            maxL = j-i +1;
                        }
						std::cout << "start " << start << " end " << right << " len " << maxL << std::endl;
                    } else if (A[i+1][j-1] == 1) {
                        A[i][j] = 1;
                        if (j-i +1 > maxL) {
                            start = i;
                            right = j;
                            maxL = j-i +1;
                        }
						std::cout << "start " << start << " end " << right << " len " << maxL << std::endl;
                    } else {
						std::cout << "i " << i << " j " << j << std::endl;
                        A[i][j] = 0;
                    }
                } else {
                    A[i][j] = 0;
                }
            }
        }
        return s.substr(start, maxL);
    }
};

int main()
{
	string s = "aaaa";
	Solution sol;
	string res = sol.longestPalindrome(s);
	std::cout << res << std::endl;
	return 0;
}
