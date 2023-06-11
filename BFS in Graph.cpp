#include <bits/stdc++.h> 
void prepareAdjList(vector<vector<int>>& adjList, vector<pair<int, int>>& edges)
{
    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<vector<int>> adjList(vertex);
    vector<int> ans;
    vector<bool> visited(vertex, false);

    prepareAdjList(adjList, edges);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int frontnode = q.front();
        q.pop();

        ans.push_back(frontnode);

        sort(adjList[frontnode].begin(), adjList[frontnode].end());

        for (auto neighbor : adjList[frontnode])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int frontnode = q.front();
                q.pop();

                ans.push_back(frontnode);

                sort(adjList[frontnode].begin(), adjList[frontnode].end());

                for (auto neighbor : adjList[frontnode])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    return ans;
}