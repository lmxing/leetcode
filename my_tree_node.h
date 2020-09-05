#pragma once

#include "my_include.h"



struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int> & nums, int start, int end) 
{
	if (start > end) return NULL;
	if (start < 0) return NULL;
	int mid = (end + start) / 2;
	TreeNode * root = new TreeNode(nums[mid]);
	TreeNode * left = buildTree(nums, start, mid - 1);
	TreeNode * right = buildTree(nums, mid + 1, end);
	root->left = left;
	root->right = right;
	return root;
}

TreeNode * buildTreeNode(vector<int> & nums)
{
	TreeNode * root = buildTree(nums, 0 , nums.size() - 1);
	return root;
}
