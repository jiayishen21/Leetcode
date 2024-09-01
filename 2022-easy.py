"""
2022. Convert 1D Array Into 2D Array
Leetcode easy
https://leetcode.com/problems/convert-1d-array-into-2d-array/description/?envType=daily-question&envId=2024-09-01
time: 
notes:
python tabs v.s. spaces indentation is a little messed up
"""


class Solution(object):
    def construct2DArray(self, original, m, n):
        """
        :type original: List[int]
        :type m: int
        :type n: int
        :rtype: List[List[int]]
        """

        l = len(original)
        if l != m*n:
            return []
        else:
            res = [[0]*n for _ in range(m)]

            for i in range(m):
                for j in range(n):
                    res[i][j] = original[i*n+j]

            return res
