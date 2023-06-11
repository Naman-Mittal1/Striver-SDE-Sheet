#include <queue>

bool isGraphBirpatite(vector<vector<int>> &edges) {
	
    int N = edges.size();
    vector<int> color(N, -1);

    for (int i = 0; i < N; ++i) {
        if (color[i] == -1) 
        {
            color[i] = 0;
            vector<int> queue;
            queue.push_back(i);

            while (!queue.empty()) 
            {
                int curr = queue.front();
                queue.erase(queue.begin());
                
                for (int neighbor = 0; neighbor < N; ++neighbor) 
                {
                    if (edges[curr][neighbor] == 1) 
                    {
                        if (color[neighbor] == -1) 
                        {
                            color[neighbor] = 1 - color[curr];
                            queue.push_back(neighbor);
                        } else if (color[neighbor] == color[curr]) 
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}