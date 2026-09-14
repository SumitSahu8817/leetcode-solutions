class Solution {
public:
    int dp[2501][2501];
    int solve (int idx , int pre , vector<int> &nums) {
        int n = nums.size();
        if (idx>=n) {
            return 0;
        }
        if (pre !=-1 && dp[idx][pre] != -1) {
            return dp[idx][pre];
        }
        int take = 0;
        if (pre == -1 || nums[pre]<nums[idx]) {
            take = 1 + solve (idx+1 , idx , nums);
        }
       int skip = solve (idx+1,pre , nums);
       if (pre!=-1)
       dp[idx][pre] = max (skip , take);
        return max (skip , take);

    }

    int lengthOfLIS(vector<int>& nums) {
        memset (dp , -1 , sizeof(dp));
        return solve(0 , -1 , nums);
    }
};