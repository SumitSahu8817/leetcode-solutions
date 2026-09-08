class Solution {
public:
    int MOD = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map< int , int > mp;
        for (auto &it : points) {
            mp[it[1]]++;
        } 

        long long prev = 0;
        long long result = 0;
        

        for (auto &it : mp) {
            long long cnt = it.second;
            long long lines =  ( cnt * ( cnt - 1 ) ) / 2;
            result +=  prev * lines%MOD;
            prev += lines%MOD;
        }
        return result % MOD;
    }
};