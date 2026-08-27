class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0 , j = 0;
        int  n = nums.size();
        vector<int> prefix(n,0);
        unordered_map<int,int> mp;
        mp[0] = 1;
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
        int ans = 0;
        for(auto it:prefix){
            if(mp.find(it-k)!=mp.end()){
                ans = ans + mp[it-k];
            }
            mp[it]++;
        }
        return ans;
    }
};