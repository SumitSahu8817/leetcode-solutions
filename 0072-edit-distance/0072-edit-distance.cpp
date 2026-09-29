class Solution {
public:
        int dp[501][501];
    int solve ( string &word1, string &word2 , int i , int j ) {
        int m = word1.length();
        int n = word2.length();
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i==word1.length()) {
            return dp[i][j]=n-j;
        } else if (j==word2.length()) {
            return dp[i][j]=m-i;
        } 
        if (word1[i] == word2[j]) {
            return dp[i][j]=solve ( word1 , word2 , i+1 , j+1);
        } 
        int insert = 1 + solve (word1 , word2 , i , j+1);
        int delet = 1 + solve (word1 , word2 , i+1 , j );
        int replace = 1 + solve (word1 , word2 , i+1 , j+1);

        return dp[i][j] =  min (min(insert , delet) , replace);

    }

    int minDistance(string word1, string word2) {
        memset (dp,-1,sizeof(dp));
        return solve ( word1 , word2 , 0 , 0 );
    }
};