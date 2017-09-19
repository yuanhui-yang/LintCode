// Maximum Subtree
// http://www.lintcode.com/en/problem/maximum-subtree/

/*
Given a binary tree, find the subtree with maximum sum. Return the root of the subtree.

 Notice

LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with maximum sum and the given binary tree is not an empty tree.

Example
Given a binary tree:

	 1
   /   \
 -5     2
 / \   /  \
0   3 -4  -5 
return the node with value 3.
*/

class Solution {
public:
	/*
	 * @param root: the root of binary tree
	 * @return: the maximum weight node
	 */
	TreeNode * findSubtree(TreeNode * root) {
		TreeNode * result = NULL;
		int maxVal = INT_MIN;
		helper(root, result, maxVal);
		return result;
	}
private:
	int helper(TreeNode * root, TreeNode * & result, int & maxVal) {
		if (!root) {
			return 0;
		}
		int leftVal = helper(root->left, result, maxVal), rightVal = helper(root->right, result, maxVal), currVal = leftVal + root->val + rightVal;
		if (!result or currVal > maxVal) {
			result = root;
			maxVal = currVal;
		}
		return currVal;
	}
};