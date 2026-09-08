class Solution {
public:

    bool hascycle ;

    void dfs(unordered_map <int , vector<int>> &adj , int idx , vector<bool> &visited , stack<int> &st , vector<bool> &inrecu) {
            visited[idx] = true;
            inrecu[idx] = true;
            for (auto &it : adj[idx]) {
                if (inrecu[it] == true) {
                    hascycle = true;
                    return;
                }
                if (!visited[it]) {
                    dfs (adj , it , visited , st , inrecu);
                }

            }
            st.push(idx);
            inrecu[idx] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int , vector<int> > adj;
        vector<bool> inrecu(numCourses,false);
        vector<bool> visited(numCourses , false);
        hascycle =  false;
        for (auto &it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }
        stack<int> st;
        for (int i=0 ; i<numCourses ; i++) {
            if(!visited[i]) {
                dfs(adj , i , visited , st , inrecu);
            }
        }
        if(hascycle == true) {
            return {};
        }
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};