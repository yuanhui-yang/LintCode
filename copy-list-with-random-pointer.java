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
		if(head == null) return null;

		Map<RandomListNode, RandomListNode> map = new HashMap<>();
		RandomListNode dummy = new RandomListNode(0);
		RandomListNode cur = dummy;

		while(head != null){
			if(!map.containsKey(head)){
				map.put(head, new RandomListNode(head.label));
			}

			if(head.random != null){
				if(!map.containsKey(head.random)){
					map.put(head.random, new RandomListNode(head.random.label));                 
				}
				map.get(head).random = map.get(head.random);
			}            
			
			cur.next = map.get(head);
			cur = cur.next;
			head = head.next;
		}
		return dummy.next;
	}
}