class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node){
        if(visited[node]) return;

        visited[node] = true;

        for(int &v : adj[node]){
            dfs(adj, visited, v);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int>&vec : edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(adj, visited, i);
            }
        }

        return count;
    }
};
