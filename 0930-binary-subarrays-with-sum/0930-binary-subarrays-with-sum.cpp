class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i = 0 , j = 0;
       vector<int> prefix(n,0);
       prefix[0] = nums[0];
       for (int i=1;i<n;i++) {
            prefix[i] = prefix[i-1]+nums[i];
       }
       int ans = 0;
       unordered_map<int,int> mp;
        mp[0]=1;
       
       for (int i=0 ; i<n ; i++) {
        if(mp.find(prefix[i]-goal)!=mp.end()){
                ans = ans + mp[prefix[i]-goal];
        }
        mp[prefix[i]]++;
       }
       return ans;
    }
};