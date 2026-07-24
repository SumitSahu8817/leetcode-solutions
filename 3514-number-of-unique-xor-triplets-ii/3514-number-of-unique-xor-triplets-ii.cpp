class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        unordered_set<int> pairs;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                pairs.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> ans;
        for(int x : nums){
            ans.insert(x);
        }
        for(int p : pairs){
            for(int x : nums){
                ans.insert(p^x);
            }
        }
        return ans.size();
    }
};