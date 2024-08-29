import java.util.*;

/*
947. Most Stones Removed with Same Row or Column
Leetcode medium
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/?envType=daily-question&envId=2024-08-29
time: 1 hour
notes: I REALLY NEED TO GET BETTER AT GRAPH THEORY and understanding when to apply graphs
also i need better pattern recognition
*/

class Solution {
    public int removeStones(int[][] stones) {
		// split stones into interconnected networks
		// each network can be reduced to a single stone

		ArrayList<HashSet<Integer>[]> networks = new ArrayList<>();
		int foundNetwork;

		for(int[] stone : stones) {
			foundNetwork = -1;

			int networkSize = networks.size();
			for(int i = 0; i < networkSize; i++) {
				if(networks.get(i)[0].contains(stone[0]) || networks.get(i)[1].contains(stone[1])) {
					if(foundNetwork == -1) {
						foundNetwork = i;
						networks.get(i)[0].add(stone[0]);
						networks.get(i)[1].add(stone[1]);
					}
					else {
						// merge the two networks
						networks.get(foundNetwork)[0].addAll(networks.get(i)[0]);
						networks.get(foundNetwork)[1].addAll(networks.get(i)[1]);
						networks.remove(i);
						i--;
						networkSize--;
					}
				}
			}

			if(foundNetwork == -1) {
				HashSet<Integer>[] newNetwork = (HashSet<Integer>[]) new HashSet[2];
				newNetwork[0] = new HashSet<Integer>();
				newNetwork[1] = new HashSet<Integer>();
				newNetwork[0].add(stone[0]);
				newNetwork[1].add(stone[1]);
				networks.add(newNetwork);
			}
		}

		// print the networks
		// for(HashSet<Integer>[] network : networks) {
		// 	System.out.println("NEW NETWORK -------------------");
		// 	Iterator<Integer> it = network[0].iterator();
		// 	Iterator<Integer> it2 = network[1].iterator();

		// 	while(it.hasNext()) {
		// 		System.out.println(it.next() + " " + it2.next());
		// 	}
		// }

		return stones.length - networks.size();
    }
}
