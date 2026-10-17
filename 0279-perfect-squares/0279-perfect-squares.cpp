class Solution {
public:
    //  int static mincnt = INT_MAX;
    int dp[10001];
    int solve (int n) {
                if (n == 0) {
                    return 0;
                }
                if (dp[n] != -1) {
                    return dp[n];
                }
                int mincnt = INT_MAX;
                for (int i=1 ; i*i <= n ;i++) {
                    
                        int result = 1 + solve (n-i*i);
                        mincnt = min (mincnt , result);
                }
                return dp[n] = mincnt;
    }

    int numSquares(int n) {
        memset (dp , -1 , sizeof(dp));
       return solve (n);

    }
};