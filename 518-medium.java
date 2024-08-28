import java.util.*;

/*
518. Coin Change II
Leetcode medium
https://leetcode.com/problems/coin-change-ii/description/?envType=problem-list-v2&envId=r9zp3ka3
time: 30 mins
notes: had to watch neetcode's video solution to figure out how to deal with no duplicates
*/

class Solution {
	private int solve(int[][] memo, int[] coins, int amount, int i) {
		if(memo[i][amount] != -1) {
			return memo[i][amount];
		}

		memo[i][amount] = 0;
		for(int j = i; j < coins.length; j++) {
			if(coins[j] <= amount) {
				memo[i][amount] += solve(memo, coins, amount - coins[j], j);
			}
		}

		return memo[i][amount];
	}

    public int change(int amount, int[] coins) {
        // initial thoughts:
		// let y = amount, c_i = coins[i]
		// we essentially want to find the number of distinct solutions x to the equation:
		// x_1 c_1 + x_2 c_2 + ... + x_n c_n = y
		// where x_i >= 0 for all i

		if(amount == 0) {
			return 1;
		}

		// intuition: memo
		// memo[i][j] = # of ways to amount j using coins i to n-1
		int[][] memo = new int[coins.length][amount + 1];
		for(int i = 0; i < coins.length; i++) {
			Arrays.fill(memo[i], -1);
			memo[i][0] = 1;
		}

		return solve(memo, coins, amount, 0);
    }
}