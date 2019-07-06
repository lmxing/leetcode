
#include "../my_include.h"
#include "../my_util.h"


 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 


class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        deque<TreeNode*> que;
        que.push_back(root);
        bool isx,isy;
        while(!que.empty()) {
            isx = false;
            isy = false;
            int size = que.size();
				std::cout << " \n ";
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = que.front();
				std::cout << tmp->val << "  ";
                if (tmp->val == x) {
                    isx = true;
                }
                if (tmp->val == y) {
                    isy = true;
                }
                if (isx && isy) return true;
                if (tmp->left != NULL) {
                    que.push_back(tmp->left);
                }
                if (tmp->right != NULL) {
                    que.push_back(tmp->right);
                }
				que.pop_front();
            }

        }
				std::cout << " \n ";
        return false;
    }
   
};

int main()
{
	Solution sol;
	TreeNode * root = new TreeNode(1);
	TreeNode * root1 = new TreeNode(2);
	TreeNode * root2 = new TreeNode(3);
	TreeNode * root3 = new TreeNode(4);
	root->left = root1;
	root->right = root2;
	root1->right = root3;
	bool res = sol.isCousins(root, 2,3);
	std::cout << "res " << res << std::endl;
	return 1;
}
