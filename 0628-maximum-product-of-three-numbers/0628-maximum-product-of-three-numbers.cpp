class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long a = nums[0]*nums[1]*nums[2];
        long long b = nums[0]*nums[1]*nums[n-1];
        long long c = nums[n-1]*nums[n-2]*nums[n-3];
        return max(a,max(b,c));
    }
};