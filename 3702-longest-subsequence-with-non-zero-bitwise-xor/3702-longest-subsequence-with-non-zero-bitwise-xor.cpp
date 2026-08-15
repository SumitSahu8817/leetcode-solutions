class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int zor = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            zor = zor^nums[i];
            if(nums[i]==0)cnt++;
        }
        if(zor != 0) return nums.size();
        if(cnt == nums.size()) return 0;
        return nums.size()-1;
    }
};