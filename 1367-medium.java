import java.util.*;

/*
1367. Linked List in Binary Tree
Leetcode medium
https://leetcode.com/problems/linked-list-in-binary-tree/description/?envType=daily-question&envId=2024-09-07
time: 12 minutes
notes: had to figure out stack and pair syntax
*/

public class ListNode {
	int val;
	ListNode next;
	ListNode() {}
	ListNode(int val) { this.val = val; }
	ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode() {}
	TreeNode(int val) { this.val = val; }
	TreeNode(int val, TreeNode left, TreeNode right) {
		this.val = val;
		this.left = left;
		this.right = right;
	}
}

class Solution {
	private boolean dfs(ListNode head, TreeNode root) {
		Stack<Pair<TreeNode, ListNode>> toVisit = new Stack<Pair<TreeNode, ListNode>>();
		toVisit.push(new Pair<TreeNode, ListNode>(root, head));

		while(!toVisit.isEmpty()) {
			Pair<TreeNode, ListNode> cur = toVisit.pop();

			if(cur.getValue() == null) {
				return true;
			}
			if(cur.getKey() == null) {
				continue;
			}
			if(cur.getKey().val != cur.getValue().val) {
				continue;
			}
			toVisit.push(new Pair<TreeNode, ListNode>(cur.getKey().left, cur.getValue().next));
			toVisit.push(new Pair<TreeNode, ListNode>(cur.getKey().right, cur.getValue().next));
		}
		return false;
	}

    public boolean isSubPath(ListNode head, TreeNode root) {
		// i'm going to to first mark down all possible starting points
		// then do a sweep through the tree to see if any of them are valid
		// a slightly faster algorithm could be to do a sweep through the tree on the step that we mark it down
		// but this would be more complicated

		// we'll use a stack instead of recursion to avoid stack overflow
		Stack<TreeNode> toVisit = new Stack<TreeNode>();
		Stack<TreeNode> starting = new Stack<TreeNode>();

		toVisit.push(root);
		while(!toVisit.isEmpty()) {
			TreeNode cur = toVisit.pop();
			if(cur == null) {
				continue;
			}

			if(cur.val == head.val) {
				starting.push(cur);
			}

			toVisit.push(cur.left);
			toVisit.push(cur.right);
		}

		// iterate through possible starting points and dfs
		while(!starting.isEmpty()) {
			TreeNode cur = starting.pop();
			if(dfs(head, cur)) {
				return true;
			}
		}
		return false;
    }
}