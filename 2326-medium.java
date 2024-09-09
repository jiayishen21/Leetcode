import java.util.*;

/*
2326. Spiral Matrix IV
Leetcode medium
https://leetcode.com/problems/spiral-matrix-iv/description/?envType=daily-question&envId=2024-09-09
time: 20 mins. i made a lot of accidental mistakes with negative positive and indexing
*/

// public class ListNode {
// 	int val;
// 	ListNode next;
// 	ListNode() {}
// 	ListNode(int val) { this.val = val; }
// 	ListNode(int val, ListNode next) { this.val = val; this.next = next; }
// }
 
class Solution {
	private boolean failMove(int x, int y, int moveX, int moveY, int m, int n, boolean filled[][]) {
		return x + moveX < 0 || x + moveX >= n || y + moveY < 0 || y + moveY >= m || filled[y + moveY][x + moveX];
	}

    public int[][] spiralMatrix(int m, int n, ListNode head) {
        // The number of nodes in the list is in the range [1, m * n], so we don't have to worry about overflowing
		int matrix[][] = new int[m][n];
		boolean filled[][] = new boolean[m][n];

		// fill matrix with -1
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				matrix[i][j] = -1;
			}
		}

		int x = 0;
		int y = 0;
		int moveX = 1;
		int moveY = 0;

		boolean rotated = false;

		while(head != null) {
			if(!filled[y][x]) {
				matrix[y][x] = head.val;
				filled[y][x] = true;
				head = head.next;
			}

			if(failMove(x, y, moveX, moveY, m, n, filled)) {
				// 2 failed moves in a row => terminate
				if(rotated) {
					break;
				}
				int temp = moveX;
				moveX = -moveY;
				moveY = temp;
				rotated = true;
			}
			else {
				x += moveX;
				y += moveY;
				rotated = false;
			}

		}

		return matrix;
    }
}
