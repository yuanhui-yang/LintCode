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
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
	/**
	 * @param head: The head of linked list with a random pointer.
	 * @return: A new head of a deep copy of the list.
	 */
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode * dummy = new RandomListNode(-1);
		for (RandomListNode * it = dummy, * jt = head; jt; it = it->next, jt = jt->next) {
			it->next = helper(jt);
		}
		for (RandomListNode * it = dummy->next, * jt = head; it and jt; it = it->next, jt = jt->next) {
			it->random = helper(jt->random);
		}
		return dummy->next;
	}
private:
	unordered_map<RandomListNode *, RandomListNode *> dict;
	RandomListNode * helper(RandomListNode * node) {
		if (!node) {
			return NULL;
		}
		return dict[node] = new RandomListNode(node->label);
	}
};