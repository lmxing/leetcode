
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int l1 = A.size();
        int l2 = B.size();
        int dp[1001][1001];
        for (int i = 0; i < l1;i++) {
            if(A[i] == B[0]) dp[i][0] = 1;
        }
        for (int j = 0; j < l2; j++) {
            if (A[0] == B[j]) dp[0][j] = 1;
        }
        int max_len = -1;
        for (int i = 1; i < l1; ++i) {
            for (int j = 1; j < l2; j++) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }
        return max_len;
    }
};

int main()
{
	Solution sol;
	vector<int> A = {0,1,1,1,1};
	vector<int> B = {1,0,1,0,1};
	int result = sol.findLength(B, A);
	MY_LOG_PAIR("result", result)
	return 1;
}
