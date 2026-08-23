class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0 ; i<n ; i++) {
            if ((i-k)<0 || (i+k)>(n-1)) {
                    ans.push_back(-1);
                    continue;
                }
            int a = i;
            long long sum = nums[i];
            for (int j=1;j<=k;j++) {
                
                sum += nums[i-j] + nums[i+j];
            }
            ans.push_back(sum/(2*k+1));
        }
        return ans;
    }
};