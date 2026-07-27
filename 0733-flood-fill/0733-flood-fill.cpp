class Solution {
public:
    bool issafe(int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n){
            return false;
        }
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     
        int m = image.size();
        int n = image[0].size();
           vector<vector<int>> ans=image;
        vector<vector<int>> direction = {{0,-1},{1,0},{0,1},{-1,0}};
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m,vector<bool> (n,0));
            int originalColor = image[sr][sc];
        if (originalColor == color)
            return image;
        ans[sr][sc] = color;

        q.push({sr,sc});
        visited[sr][sc]=true;
        while(!q.empty())
        {
           int size = q.size();
           pair<int,int> front = q.front();
           q.pop();
            while(size--){
            for(vector<int> dir : direction){
                int newi = front.first + dir[0];
                int newj =  front.second+ dir[1];
                if(issafe(newi,newj,m,n)&&!visited[newi][newj])
                {if(image[sr][sc]==image[newi][newj]){
                    visited[newi][newj]=1;
                    ans[newi][newj]=color;
                    q.push({newi,newj});}
                }
        }
            }
        }
        return ans;
    }
};