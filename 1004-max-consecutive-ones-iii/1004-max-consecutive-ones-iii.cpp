class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0 , j = 0;
        int zero = 0;
        int n = nums.size();
        int maxl = 0;
        while (j<n) {
                if (nums[j]==0){
                    zero++;
                }
                if (zero<=k){
                    maxl = max (maxl , j-i+1);
                } else {
                    while(zero>k){
                        if(nums[i]==0)zero--;
                        i++;
                    }
                }
                j++;
        }
        return maxl;
    }
};