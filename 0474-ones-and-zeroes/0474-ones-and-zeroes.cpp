class Solution {
public:
    int t[101][101][601];
    int solve(vector<pair<int,int>> &arr,int m,int n,int i){
        if(i>=arr.size()||(m==0&&n==0)){
            return 0;
        }
        if(t[m][n][i]!=-1){
            return t[m][n][i];
        }
        int take = 0;
        if(arr[i].first<=m&&arr[i].second<=n){
         take = 1 + solve(arr,m-arr[i].first,n-arr[i].second,i+1);
        }
        int skip = solve(arr,m,n,i+1);
        return t[m][n][i]=max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> arr;
        for(int i=0;i<strs.size();i++){

            int a=0;
            int b = 0;

            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0')a++;
                else b++;
            }
            arr.push_back({a,b});
            
        }
        memset(t,-1,sizeof(t));
    return solve(arr,m,n,0);
    }
};