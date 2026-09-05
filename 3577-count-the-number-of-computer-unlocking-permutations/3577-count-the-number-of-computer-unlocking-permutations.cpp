class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mini = *min_element(complexity.begin() , complexity.end());
        int n = complexity.size();
        for (int i = 1;i<n;i++) {
        if (complexity[i]<=complexity[0]) {
            return 0;
        }
     }
     long long ans = 1;
     int MOD = 1e9 + 7;
     for (int i=1;i<n;i++) {
        ans = (ans*i)%MOD;
     }
     return ans % MOD;

    }
};