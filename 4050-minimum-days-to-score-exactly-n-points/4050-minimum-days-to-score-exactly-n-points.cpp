class Solution {
public:
        vector<int> dp;
    int check (int n) {
        if (n==0) {
            return 0;
        }
        if (dp[n]!=-1) {
            return dp[n];
        }
        int ans =  INT_MAX;
        for (int k = 1 ; k*(k+1) / 2 <= n ; k++) {
            int points = k * (k+1) / 2;
            ans = min (ans ,  k + 1 + check(n-points));
        }
        return dp[n] = ans;
    }

    int minDays(int n) {
        dp.assign (n+1 , -1);
        return check(n)-1;
    }
};