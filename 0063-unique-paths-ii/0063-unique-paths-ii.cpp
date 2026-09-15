class Solution {
public:
    int dp[102][102];
    int solve (int i , int j , vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i>=m||i<0||j>=n||j<0||grid[i][j]==1) {
            return dp[i][j]=0;
        } 

        if (i==m-1&&j==n-1){
            return dp[i][j] = 1;
        }
        int r = solve (i,j+1,grid);
        int l = solve (i+1,j,grid);
        return dp[i][j] = r+l;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset (dp , -1 , sizeof(dp));
        return solve (0,0,obstacleGrid);
    }
};