#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

/*
1514. Path with Maximum Probability
Leetcode medium
https://leetcode.com/problems/path-with-maximum-probability/description/?envType=daily-question&envId=2024-08-31
time: 30 mns
notes:
had to learn dijkstra's
*/

class Node
{
public:
	int value;
	vector<int> neighbors;
	vector<double> probs;

	Node(int value)
	{
		this->value = value;
		neighbors = vector<int>();
		probs = vector<double>();
	}
};

typedef pair<int, double> Edge;

class Solution
{
public:
	vector<double> dijkstra(int n, vector<vector<Edge>> &graph, int start)
	{
		vector<double> dist = vector<double>(n, numeric_limits<double>::max());
		priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
		dist[start] = 0; // start node at 1 so that the first edge goes through
		pq.push(Edge(start, 0));

		while (!pq.empty())
		{
			int curNode = pq.top().first;
			double curDist = pq.top().second;
			pq.pop();

			// skip if we're on a suboptimal path
			if (curDist > dist[curNode])
			{
				continue;
			}

			// traverse all neighbors
			for (auto &edge : graph[curNode])
			{
				int neighbor = edge.first;
				double weight = edge.second;
				double newDist = dist[curNode] + weight;

				if (newDist < dist[neighbor])
				{
					dist[neighbor] = newDist;
					pq.push(Edge(neighbor, newDist));
				}
			}
		}

		return dist;
	}

	double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
	{
		// this is a copy and paste of dijkstra's algorithm
		vector<vector<Edge>> graph(n);
		// initialize graph
		for (int i = 0; i < edges.size(); i++)
		{
			// log for precision, negative to make probabilities positive
			double weight = -log(succProb[i]);
			graph[edges[i][0]].push_back(Edge(edges[i][1], weight));
			graph[edges[i][1]].push_back(Edge(edges[i][0], weight));
		}

		// now that the graph is initialized, we can run dijkstra's algorithm
		vector<double> dist = dijkstra(n, graph, start_node);

		// return the probability of reaching the end node
		return exp(-dist[end_node]);
	}
};
