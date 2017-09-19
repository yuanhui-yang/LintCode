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

public class Solution {
	/*
	 * @param root: the root of binary tree
	 * @return: the maximum weight node
	 */
	public TreeNode findSubtree(TreeNode root) {
		helper(root);
		return result;
	}
	private TreeNode result = null;
	private int maxVal = Integer.MIN_VALUE;
	private int helper(TreeNode root) {
		if (root == null) {
			return 0;
		}
		int leftVal = helper(root.left), rightVal = helper(root.right), currVal = leftVal + root.val + rightVal;
		if (result == null || currVal > maxVal) {
			result = root;
			maxVal = currVal;
		}
		return currVal;
	}
}