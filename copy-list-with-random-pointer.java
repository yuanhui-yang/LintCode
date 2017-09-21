// Copy List with Random Pointer
// http://www.lintcode.com/en/problem/copy-list-with-random-pointer/

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Example
Challenge 
Could you solve it with O(1) space?
*/

/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
	/**
	 * @param head: The head of linked list with a random pointer.
	 * @return: A new head of a deep copy of the list.
	 */
	public RandomListNode copyRandomList(RandomListNode head) {
		this.dict = new HashMap<RandomListNode, RandomListNode>();
		RandomListNode dummy = new RandomListNode(-1), it = head, jt = dummy;
		while (it != null) {
			jt.next = f(it);
			it = it.next;
			jt = jt.next;
		}
		it = head;
		jt = dummy.next;
		while (it != null && jt != null) {
			jt.random = f(it.random);
			it = it.next;
			jt = jt.next;
		}
		return dummy.next;
	}
	private HashMap<RandomListNode, RandomListNode> dict = null;
	private RandomListNode f(RandomListNode node) {
		if (node == null) {
			return node;
		}
		if (dict.containsKey(node)) {
			return dict.get(node);
		}
		RandomListNode result = new RandomListNode(node.label);
		dict.put(node, result);
		return result;
	}
}