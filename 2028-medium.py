"""
2028. Find Missing Observations
Leetcode medium
https://leetcode.com/problems/find-missing-observations/description/?envType=daily-question&envId=2024-09-05
time: 5 mins
notes:
"""


class Solution(object):
    def missingRolls(self, rolls, mean, n):
        """
        :type rolls: List[int]
        :type mean: int
        :type n: int
        :rtype: List[int]
        """

        # initial thoughts: this question is super easy so not much planning needs to be done
        missing = mean * (len(rolls) + n) - sum(rolls)

        if missing < n or missing > 6 * n:
            return []

        res = [1] * n
        missing -= n
        i = 0
        while (missing > 0):
            res[i] += min(5, missing)
            missing -= 5
            i += 1
        return res
