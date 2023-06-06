#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode* cloneGraph(graphNode* node) {
    if (node == nullptr)
        return nullptr;

    std::queue<graphNode*> q;
    std::unordered_map<graphNode*, graphNode*> visited;

    // Create the clone of the starting node
    graphNode* cloneNode = new graphNode(node->data);
    visited[node] = cloneNode;
    q.push(node);

    while (!q.empty()) {
        graphNode* currNode = q.front();
        q.pop();

        // Iterate through the neighbors of the current node
        for (graphNode* neighbor : currNode->neighbours) {
            // If the neighbor is not visited yet, create a clone and enqueue it
            if (!visited.count(neighbor)) {
                graphNode* cloneNeighbor = new graphNode(neighbor->data);
                visited[neighbor] = cloneNeighbor;
                q.push(neighbor);
            }

            // Add the cloned neighbor to the neighbors vector of the cloned node
            visited[currNode]->neighbours.push_back(visited[neighbor]);
        }
    }

    return cloneNode;
}