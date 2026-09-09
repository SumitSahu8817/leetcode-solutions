class Solution {
public:

    void dfs(int idx , unordered_map<int , vector<pair<int,int>> > &adj , vector<bool> &visited , int &result ){
        visited[idx] = true;
        for (auto &it : adj[idx]) {
            int b = it.first;
            int cost = it.second;
            result = min (result , cost);
            if (!visited[b]) {
                dfs (b , adj , visited , result);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int , vector<pair<int,int>> >adj;
        vector<bool> visited(n,false);
        for (auto &it : roads) {
            int a =  it[0];
            int b = it[1];
            int cost = it[2];
            adj[a].push_back({b,cost});
            adj[b].push_back({a,cost});
        }
        int result = INT_MAX;
        dfs(1,adj,visited,result);
        return result;
    }
};