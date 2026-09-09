class Solution {
public:
    unordered_set<string> st;
    int dp[301];
    bool solve(int idx , string &s) {
        int n = s.length();
        if (idx == n) {
            return true;
        }
        if (dp[idx]!=-1) {
            return dp[idx];
        }
        if (st.find(s)!=st.end()) {
            return true;
        }
        for (int i=1 ; i<n ; i++) {
            if (st.find(s.substr(idx,i))!=st.end() && solve (idx+i , s)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        memset (dp,-1,sizeof(dp));
        for (auto &it : wordDict ) {
            st.insert(it);
        }
       return solve (0,s);
    
    }
};