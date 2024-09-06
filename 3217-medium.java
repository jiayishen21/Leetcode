import java.util.*;

/*
3217. Delete Nodes From Linked List Present in Array
Leetcode medium
https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06
time: 8 minutes. had a bit of issues getting correct java syntax.
*/

public class ListNode {
	int val;
	ListNode next;
	ListNode() {}
	ListNode(int val) { this.val = val; }
	ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
		HashSet<Integer> numSet = new HashSet<Integer>();
		for(int num : nums) {
			if(num > 0) {
			numSet.add(num);
			}
		}        

		ListNode newHead = new ListNode(0, head);
		ListNode cur = newHead;
		while(cur.next != null) {
			if(numSet.contains(cur.next.val)) {
				cur.next = cur.next.next;
			}
			else {
				cur = cur.next;
			}
		}

		return newHead.next;
    }
}
