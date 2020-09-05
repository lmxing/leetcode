
#include "../my_include.h"
#include "../my_util.h"
#include "../my_tree_node.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        if (root==NULL) return 0;
        
        dfs(root, 0);
        return sum;
    }
    void dfs(TreeNode * root, int val) {
        if (root==NULL) return;
        int k = val * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum+=k;
			MY_LOG_PAIR("k", k)
			return;
		}
        dfs(root->left, k);
        dfs(root->right, k);
    }
};

int main()
{
	Solution sol;
	vector<int> nums = {2,1,3};
	TreeNode * root = buildTreeNode(nums);
	int result = sol.sumNumbers(root);
	MY_LOG_PAIR("result", result)
	return 1;
}
