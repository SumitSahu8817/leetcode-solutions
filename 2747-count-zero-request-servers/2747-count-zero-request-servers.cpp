class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        auto lambda = [](vector<int> &num1 , vector<int> &num2) {
            return num1[1] < num2[1];
        };
        sort (logs.begin() , logs.end() , lambda);
        int q = queries.size();
        vector<int> result(q);
        vector<pair<int , int>> timeidx(q);
        for (int i=0 ; i<q ; i++) {
            timeidx[i] = {queries[i] , i};
        }
        sort (timeidx.begin() , timeidx.end());
        unordered_map <int , int> mp;
        int i=0;
        int j=0;
        for (auto [time , indx] : timeidx) {
            int st = time - x;
            int ed = time;
            while (j<m && logs[j][1] <= ed) {
                mp[logs[j][0]]++;
                j++;
            }
            while (i<m && logs[i][1] < st) {
                mp[logs[i][0]]--;
                if (mp[logs[i][0]] == 0) {
                    mp.erase(logs[i][0]);
                }
                i++;
            }
            result[indx] = n - mp.size(); 
        }
        return result;
    }
};