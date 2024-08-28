import java.util.*;

/*
322. Coin Change
Leetcode medium
https://leetcode.com/problems/coin-change/
time: 10 minutes
*/

class Solution {
    public int coinChange(int[] coins, int amount) {
		// initial thoughts:
		// the solution isn't always just pick the largest coin that fits.
		// eg. if amount = 12, coins = [1, 6, 8], we should pick 6, 6 instead of 8, 1, 1, 1, 1

		if(amount == 0) return 0;

		// intuition: dp. record the min # of coins needed to make every amount from 0 to y
		int[] dp = new int[amount + 1];

		for(int i = 1; i <= amount; i++) {
			dp[i] = -1;
			for(int j = 0; j < coins.length; j++) {
				if(i == coins[j]) {
					// you can't better than 1
					dp[i] = 1;
					break;
				}
				else if(coins[j] < i) {
					if(dp[i - coins[j]] != -1) {
						if(dp[i] == -1) {
							dp[i] = dp[i - coins[j]] + 1;
						}
						else {
							dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
						}
					}
				}
			}
		}

		return dp[amount];
    }
}