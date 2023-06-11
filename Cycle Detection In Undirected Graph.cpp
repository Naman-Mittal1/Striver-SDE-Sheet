#include<bits/stdc++.h>

bool dfs(vector<int>& vis,vector<vector<int>>& adj,int parent,int i){
    vis[i]=1;
    for(auto child:adj[i]){
        if(!vis[child]){
            if(dfs(vis,adj,i,child)) return true;
        }
        else{
           if(child!=parent) return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adjList(n+1);

    for(int i=0; i<m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    string ans="Yes";
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(vis,adjList,-1,i)) return ans;
        }
    }
    ans="No";
    return ans;


}
