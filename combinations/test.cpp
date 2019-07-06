
#include "../my_include.h"
#include "../my_util.h"

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
    	vector<int> temp;
        dfs(temp, n, k, 0);
        return res;
    }
    void dfs(vector<int> & temp, int n, int k, int x) {
        if (temp.size() == k) {
            res.push_back(temp);
			print(temp);
			MY_LOG("OK")
            return;
        }
        for (int i = x + 1; i <= n; ++i) {
            temp.push_back(i);
            dfs(temp, n, k, i);
			MY_LOG("__11___")
			print(temp);
            temp.pop_back();
			print(temp);
			MY_LOG("__22___")
        }
    }
};

int main()
{
	Solution sol;
	int n = 5, k = 3;
	sol.combine(n, k);
	return 1;
}
