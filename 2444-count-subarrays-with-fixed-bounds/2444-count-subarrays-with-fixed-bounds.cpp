class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minp = -1;
        int maxp = -1;
        int cul = -1;
        int i = 0;
        long long ans = 0; 
        int n = nums.size();

        while (i<n) {
                if (nums[i] < minK || nums[i] > maxK) {
                    cul = i;
                }
                if (nums[i] == minK) {
                    minp = i;
                }
                if (nums[i] == maxK) {
                    maxp = i;
                }
                long long smal = min (minp , maxp);
                long long temp = smal - cul;

                if (temp <= 0) {
                    ans = ans + 0;
                } else {
                    ans = ans + temp;
                }

                i++;
        }
        return ans;
    }
};