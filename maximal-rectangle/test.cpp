
#include "../my_include.h"
#include "../my_util.h"


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == '1') dp[i][0] = 1;
            if (i != 0) dp[i][0] += dp[i-1][0];
        }
        for (int j = 0; j < col; ++j) {
            if(matrix[0][j] == '1') dp[0][j] =1;
            if (j != 0) dp[0][j] += dp[0][j-1];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1;j < col; ++j) {
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
                if (matrix[i][j] == '1') {
                    dp[i][j] +=  1;
                }  
            }
        }
        int result = 0;
        int subresult = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                for (int k = i + 1; k < row; ++k) {
                    for (int l = j + 1; l < col; ++l) {
                    //    subresult= dp[l][k] - dp[i][j] - dp[l][j] - dp[i][k];
                        result = max(result, subresult);
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
	Solution sol;
	vector<vector<char>> mat = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	sol.maximalRectangle(mat);
	return 1;
}
