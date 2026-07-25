class Solution {
public:

    void dfs(vector<vector<int>> &adj,vector<bool> &visited,int node){
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                
                dfs(adj,visited,adj[node][i]);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
            if(isConnected[i][j]==1&&i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
            }
        }
    }
    vector<bool> visited(V,0);

    int cnt = 0;
    for(int i=0;i<V;i++){
        
        if(!visited[i]){
            dfs(adj,visited,i);
            cnt++;
        }
    }
    return cnt;
    }
};