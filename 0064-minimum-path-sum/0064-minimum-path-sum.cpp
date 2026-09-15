class Solution {
public:
    int dp[201][201];
    int solve (int i , int j , vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m-1 && j == n-1) {
            return grid[i][j];
        } 
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
         if (i==m-1) {
            return dp[i][j] = grid[i][j] + solve ( i , j+1 , grid);
        }  if (j==n-1) {
            return dp[i][j] =  grid[i][j] + solve (i+1,j,grid);
        } else {
            return dp[i][j] =  grid[i][j] + min(solve(i+1,j,grid) , solve(i,j+1,grid));
        }
        return 0;
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp));
        return solve ( 0 , 0 , grid);
    }
};