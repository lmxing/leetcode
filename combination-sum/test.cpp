
#include "../my_include.h"
#include "../my_util.h"


class Solution {
public:
    vector<vector<int>> combination_list;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> comb;
        int n = candidates.size();
       
            dfs(comb, 0, candidates, n,0, target);
        return combination_list;
    }
    void dfs(vector<int> comb, 
            int comb_sum,
            vector<int>& candidates,
            int n,  int index,int target) {
        if (comb_sum == target ) {
            combination_list.emplace_back(comb);
			print(comb);
            return;
        }
        if (comb_sum > target) return;
       
        for (int i = index ;i < n; ++i) {
            // comb_sum += candidates[i];  要写在dfs里面，否则也需要回溯，别忘了
            comb.push_back(candidates[i]);
			// 倒数第二个参数从i开始，表示可以重复取， 如果不从i取，就是不能重复
            dfs(comb, comb_sum +candidates[i] ,candidates, n, i, target);
            comb.pop_back();
        }
    }
};

int main()
{
	Solution sol;
	vector<int> nums={2, 3, 1, 5};
	sol.combinationSum(nums, 8);
	return 1;
}
