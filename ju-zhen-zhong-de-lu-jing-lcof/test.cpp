
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    bool vist[202][202] = {0};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.length();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int res = dfs(board, i, j, word, 0, len, m,n);
                if (res) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, 
            string word, int idx, int len,
            int m, int n) {
        if (idx >= len) return false;
        if (i >= m || j >= n) return false ;
        
        if (board[i][j] == word[idx]) {
            vist[i][j] = 1;
            int ret1 = dfs(board, i + 1, j, word, idx + 1, len, m, n);
            if (ret1) return true;
            vist[i+1][j] = 0;
            int ret2 = dfs(board, i - 1, j, word, idx + 1, len, m, n);
            if (ret2) return true;
            vist[i-1][j] = 0;
            int ret3 = dfs(board, i, j + 1, word, idx + 1, len, m, n);
            if (ret2) return true;
            vist[i][j+1] = 0;
            int ret4 = dfs(board, i, j - 1, word, idx + 1, len, m, n);
            if (ret4) return true;
            vist[i][j-1] = 0;
        }
        return false;
    }
};

int main()
{
	vector<vector<char>> vec={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	string word = "ABCCED";
	
	Solution sol;
	int ret = sol.exist(vec, word);
	std::cout << "ret: " << ret << std::endl;
	return 1;
}
