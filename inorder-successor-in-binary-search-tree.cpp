// Inorder Successor in Binary Search Tree
// http://www.lintcode.com/en/problem/inorder-successor-in-binary-search-tree/

/*
Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.

If the given node has no in-order successor in the tree, return null.

 Notice

It's guaranteed p is one node in the given tree. (You can directly compare the memory address to find p)

Example
Given tree = [2,1] and node = 1:

  2
 /
1
return node 2.

Given tree = [2,1,3] and node = 2:

  2
 / \
1   3
return node 3.
*/

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
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (!root or !p) {
			return NULL;
		}
		bool flag = false;
		while (root) {
			if (!root->left) {
				if (flag) {
					return root;
				}
				if (root == p) {
					flag = true;
				}
				root = root->right;
			}
			else {
				TreeNode * pred = root->left;
				while (pred->right and pred->right != root) {
					pred = pred->right;
				}
				if (pred->right == root) {
					if (flag) {
						return root;
					}
					if (root == p) {
						flag = true;
					}
					pred->right = NULL;
					root = root->right;
				}
				else {
					pred->right = root;
					root = root->left;
				}
			}
		}
		return NULL;
	}
};