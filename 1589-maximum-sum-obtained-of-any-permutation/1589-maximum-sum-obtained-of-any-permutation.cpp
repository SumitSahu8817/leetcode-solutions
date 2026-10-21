class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        int m = requests.size();
        vector <long long> events(n+1 , 0);
        for (auto &it : requests) {
            int st = it[0];
            int ed = it[1];
            events[st] += 1;
            events[ed+1] -= 1;
        }
        int MOD = 1000000007;
        long long cursum = 0;
        vector<long long> summ;
        for (int i=0 ; i<n ;i++) {
            cursum = cursum + events[i];
            summ.push_back(cursum);
        }
        sort (summ.rbegin() , summ.rend());
        sort (nums.rbegin() , nums.rend());
        long long ans = 0;
        
        for (int i=0 ; i<n ; i++) {
            ans = ans + (summ[i]*nums[i])%MOD;
        }
        
        return ans%MOD;;

    }
};