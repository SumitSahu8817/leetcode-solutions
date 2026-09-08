class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;
        unordered_map<int, list<int>> m;
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            m[v].push_back(u);
        }
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : m[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (auto it : m[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return count == V;
    }
};
