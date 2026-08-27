class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int oddcnt = 0;
      
        unordered_map<int,int> mp;
          mp[0]=1;
        int n  =nums.size();
        for (int i=0;i<n;i++) 
        {
            if (nums[i]%2!=0){
                oddcnt++;
            }
            if (mp.find(oddcnt-k)!=mp.end()){
                ans += mp[oddcnt-k];
            }
            mp[oddcnt]++;
        }
        return ans;

    }
};