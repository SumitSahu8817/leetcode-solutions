class Solution {
public:
    vector<vector<int>> direction= {{0,-1},{1,0},{0,1},{-1,0}};
    bool issafe(int i , int j , int m , int n){
        if(i<0||j<0||i>=m||j>=n){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int V = grid.size();
        vector<bool> visited(V,0);
        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

            if(grid[i][j]==2){
                q.push({i,j});
            }else if(grid[i][j]==1){
                cnt++;
            }
            }
        }
        int ans = 0;
        if(cnt==0)return 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                for(vector<int> dir : direction){
                    int newi = i + dir[0];
                    int newj = j + dir[1];
                    if(issafe(newi,newj, m, n)){
                        if(grid[newi][newj]==1)
                        {
                            grid[newi][newj] = 2;
                            cnt--;
                            q.push({newi,newj});
                            }
                    }
                }
            }
            ans++;
        }
        if(cnt!=0){
            return -1;
        }else 
        {return ans-1;}
    }
};