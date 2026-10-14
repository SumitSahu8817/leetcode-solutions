class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort (arr.begin(),arr.end());
        int dif = INT_MAX;
        int n = arr.size();
        for (int i=0;i<n-1;i++) {
            if (arr[i+1]-arr[i]<dif){
                dif = arr[i+1]-arr[i];
            }
        }
        vector<vector<int>> ans;
        for (int i=1 ; i<n ;i++) {
            if (arr[i]-arr[i-1]==dif)ans.push_back({arr[i-1],arr[i]});
        }
        return ans;
    }
};