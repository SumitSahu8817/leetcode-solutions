class Solution {
public:

    int beauty(const string& s ) {
            vector<int> cnt(26,0);
            for (auto &it:s) {
                cnt[it-'a']++;
            }
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (auto &it:cnt){
            if (it>0){
            mini = min(mini,it);
            maxi = max(maxi,it);
            }
        }
        return maxi - mini;
    }

    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        for (int i=0;i<n;i++) {
            for (int j=i;j<n;j++) {
                ans += beauty(s.substr(i,j-i+1));
            }
        }
        return ans;
    }
};