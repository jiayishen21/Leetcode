#include <iostream>
#include <vector>
using namespace std;

/*
3035. Maximum Palindromes After Operations
Leetcode medium
https://leetcode.com/problems/maximum-palindromes-after-operations/description/
time: 15 minutes
notes: i misread the question and i thought that the letters could only be swapped if they
were in the same index of the two words. i should read the question more carefully next time
*/

class Solution
{
public:
	int maxPalindromesAfterOperations(vector<string> &words)
	{
		// initial thoughts
		// there's no limit to the number of swaps
		// thus, we can view the list of words as:
		// 1. the frequency of each word length (max word length 100)
		// 2. the frequency of each character

		vector<int> lenFreq(51, 0);
		vector<int> charFreq(26, 0);

		// 1 letter words are all palindromes
		// odd letter words can have any character in the middle
		// thus, we can convert every odd character word's length to len - 1
		// then, we can divide the lengths by 2 to give the number of pairs of each character

		for (string word : words)
		{
			int len = word.size();
			lenFreq[len / 2]++;
			for (int i = 0; i < len; i++)
			{
				charFreq[word[i] - 'a']++;
			}
		}

		int totalPairs = 0;
		for (int i = 0; i < 26; i++)
		{
			totalPairs += charFreq[i] / 2;
		}

		// we can use the pairs to form palindromes
		int totalPalindromes = lenFreq[0];
		for (int i = 1; totalPairs > 0 && i < 51; i++)
		{
			if (lenFreq[i] > 0)
			{
				int pairsUsed = min(lenFreq[i] * i, totalPairs);
				totalPalindromes += pairsUsed / i;
				totalPairs -= pairsUsed;
			}
		}

		return totalPalindromes;
	}
};