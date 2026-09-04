class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0;
        int ans = 0;int cntz = 0;
        while (j<n) {
            if (nums[j]==0)cntz++;
            while (cntz>1){
                if(nums[i]==0)cntz--;
                i++;
            }
            ans = max (ans,j-i);

            j++;
        }
        return ans;
    }
};