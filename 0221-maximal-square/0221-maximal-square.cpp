class Solution {
public:
    int dp[301][301];
    int solve (vector<vector<char>>& matrix , int i , int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (dp[i][j]!=-1) {
            return dp[i][j];
        }
        if ( i>=m || j>=n ) {
            return dp[i][j]=0;
        } 
        if (matrix[i][j]=='0') {
            return dp[i][j]=0;
        }
        int r = solve (matrix , i , j+1);
        int d = solve (matrix , i+1 , j+1);
        int l = solve (matrix , i+1 , j );

        return dp[i][j]=1 + min ({r , d , l});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        memset(dp , -1 , sizeof(dp));
        int result = 0;
        for (int i=0 ; i<m ; i++) {
            for (int j=0 ; j<n ;j++){
                if (matrix[i][j]=='1') {
                   result = max (result , solve (matrix , i , j)); 
                }
            }
        }
        return result*result;
    }
};