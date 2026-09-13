class Solution {
public:

    int check (vector<vector<int>>& img1, vector<vector<int>>& img2 , int idx1 , int idx2) {
        int n = img1.size();
        int cnt = 0;
        for (int i=0 ; i<n ;i++) {
            for (int j=0 ;j<n ; j++) {
                int newi = i + idx1;
                int newj = j + idx2;
                if (newi < 0 || newi >= n || newj < 0 || newj >= n){
                    continue;
                }
                if (img1[i][j] ==1 && img2[newi][newj] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for (int i=-n+1 ; i<n ; i++) {
            for (int j=-n+1 ; j<n ; j++) {
                int cnt = check(img1 , img2 , i , j);
                ans = max (ans , cnt);
            }
        }
        return ans;
    }
};