import java.util.*;

/*
947. Most Stones Removed with Same Row or Column
Leetcode medium
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/?envType=daily-question&envId=2024-08-29
time: 
*/

class Solution {
    public int removeStones(int[][] stones) {
		// initial thoughts:
		// we want to avoid removing stones that are in the same row or column as multiple other stones
		// order of removal matters, eg.
		// o x x
		// x x o
		// x o o
		// we must work from one of the corners and move upwards, we can't start from the middle stone

		// hypothesis:
		// we can repeat the process of removing the stone with the least "shared" stones until we can't remove any more stones

        int maxX = 0;
		int maxY = 0;
		for(int[] stone : stones) {
			if(stone[0] > maxX) {
				maxX = stone[0];
			}
			if(stone[1] > maxY) {
				maxY = stone[1];
			}
		}

		// we could've probably used a hashmap here, but 2D array is easier to work with and also more predictable
		int[][] grid = new int[maxY + 1][maxX + 1];
		int minNeighbors = Integer.MAX_VALUE;
		int removeIndex = 0;

		for(int[] curStone : stones) {
			for(int[] changeStone : stones) {
				if(curStone[0] == changeStone[0] || curStone[1] == changeStone[1]) {
					grid[curStone[1]][curStone[0]]++;
				}
			}
		}
		for(int i = 0; i < stones.length; i++) {
			if(grid[stones[i][1]][stones[i][0]] < 2) {
				grid[stones[i][1]][stones[i][0]] = Integer.MAX_VALUE;
			}
			else if(grid[stones[i][1]][stones[i][0]] < minNeighbors) {
				minNeighbors = grid[stones[i][1]][stones[i][0]];
				removeIndex = i;
			}
		}

		int removed = 0;
		int oldMinX;
		int oldMinY;

		List<int[]> stonesList = new ArrayList<>(Arrays.asList(stones));

		while(minNeighbors != Integer.MAX_VALUE) {
			minNeighbors = Integer.MAX_VALUE;
			removed++;
			oldMinX = stonesList.get(removeIndex)[0];
			oldMinY = stonesList.get(removeIndex)[1];
			stonesList.remove(removeIndex);
			
			for(int i = 0; i < stonesList.size(); i++) {
				if(stonesList.get(i)[0] == oldMinX || stonesList.get(i)[1] == oldMinY) {
					if(grid[stonesList.get(i)[1]][stonesList.get(i)[0]] == 2) {
						grid[stonesList.get(i)[1]][stonesList.get(i)[0]] = Integer.MAX_VALUE;
					}
					else {
						grid[stonesList.get(i)[1]][stonesList.get(i)[0]]--;
					}
				}
				if(grid[stonesList.get(i)[1]][stonesList.get(i)[0]] < minNeighbors) {
					minNeighbors = grid[stonesList.get(i)[1]][stonesList.get(i)[0]];
					removeIndex = i;
				}
			}
		}

		// print remaining stones
		for(int[] stone : stonesList) {
			System.out.println(stone[0] + " " + stone[1]);
		}

		return removed;
    }
}
