/* LeetCode111：二叉树的最小深度 */ 

#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.*/
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
    int minDepth(TreeNode* root) {
		int depth = 0;
		int ldepth = 0;
		int rdepth = 0;
		TreeNode *ptr = root;
		
		if (ptr == NULL) {
			return 0;
		}

		ldepth = minDepth(ptr->left);
		rdepth = minDepth(ptr->right);
		depth = min(ldepth, rdepth) + 1;
		return depth;
    }
};
