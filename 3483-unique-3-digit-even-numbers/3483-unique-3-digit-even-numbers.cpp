class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int , int> mp;

        for (auto &it : digits) {
            mp[it]++;
        }
        int i = 100;
        int ans = 0;
        while (i < 1000) {
            if (i % 2 != 0) {
                i++;
                continue;
            }

            int x = i;
            int a = x % 10;
            x /= 10;
            int b = x % 10;
            x /= 10;
            int c = x % 10;

            unordered_map<int, int> mpp;
            mpp[a]++;
            mpp[b]++;
            mpp[c]++;
            bool possible = true;
            for (auto &p : mpp) {
                if (mp[p.first]<p.second) {
                    possible = false;
                    break;
                }
            }
            if (possible == true)
                ans++;
            i++;
        }
        return ans;
    }
};