class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int i = k;
        int n = nums.size();
        int left = 0 , right = 2*k;
        vector<int> ans (n,-1);
        if (n<2*k+1) return ans;
        long long win = 0;
        for (int i=0;i<=2*k;i++) {
            win += nums[i];
        }
        int cnt = 2*k+1;
        ans[i] = win/cnt;

        i++;
        right++;

        while (right < n) {
                int out = nums[left];
                int in = nums[right];
                win = win + in - out;

                ans[i] = win/cnt;

                i++;
                left++;
                right++;
        }
        return ans;
    }
};