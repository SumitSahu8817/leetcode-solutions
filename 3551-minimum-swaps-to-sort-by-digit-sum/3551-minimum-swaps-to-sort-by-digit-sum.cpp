class Solution {
public:
     int getdigit(int n) {
        int sum = 0;
        while (n>0) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector <int> newar(nums);
        auto lambda = [&](int n1 , int n2) {
            int s1 = getdigit(n1);
            int s2 = getdigit(n2);
            if (s1 != s2) {
                return s1<s2;
            } else {
                return n1<n2;
            }
        };
        sort (newar.begin() , newar.end() , lambda);
        unordered_map < int , int> mp;
        for (int i=0 ; i<n ; i++) {
            mp[nums[i]] = i;
        }
        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            int ex = newar[i];
            int cur = nums[i];
            if (ex == cur) continue;
            int idx = mp[ex];
            nums[i] = ex;
            nums[idx] = cur;
            mp[ex] = i;
            mp[cur] = idx;
            ans++;
        }
        return ans;
    }
};