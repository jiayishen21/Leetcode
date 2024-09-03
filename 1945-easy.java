import java.util.*;

/*
1945. Sum of Digits of String After Convert
Leetcode easy
https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/?envType=daily-question&envId=2024-09-03
time: 5 ,minutes
notes: 
*/

class Solution {
    public int getLucky(String s, int k) {
		// immediate thoughts: brute forcing is basically going to be O(n) in the length of the s
		// we also don't have to actually replace s with the new nums since k >= 1
		int sum = 0;
		for(char c : s.toCharArray()) {
			int val = c - 'a' + 1;
			// sum digits of val, which can potentially be 2 digits
			while(val > 0) {
				sum += val % 10;
				val /= 10;
			}
		}
		k--;

		int oldSum = sum;
		while(k > 0) {
			sum = 0;
			// sum digits of oldSum
			while(oldSum > 0) {
				sum += oldSum % 10;
				oldSum /= 10;
			}
			oldSum = sum;
			k--;
		}

		return sum;
    }
}