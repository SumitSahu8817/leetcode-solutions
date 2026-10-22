class Solution {
public:
    int makeStringSorted(string s) {
        long long MOD = 1000000007;
        int n = s.size();
        vector<int> fact(n+1 , 1);
        vector<int> invfact(n+1,1);
        for (int i=1 ;i<=n ; i++) {
            fact[i] = 1LL*fact[i-1]*i%MOD;
        }
        long long x = 1 ;
        long long p = MOD - 2;
        x = fact[n];
        long long a = x , power = p;
        long long res = 1;
        while (power>0) {
            if (power%2==1) {
                res = res*a%MOD;
            }
            a = a*a%MOD;
            power = power/2;
        }
        invfact[n] = res;
        for (int i=n ; i>=1 ; i--) {
            invfact[i-1] = 1LL*invfact[i]*i%MOD;
        }
        vector<int> cnt (26,0);
        for (char ch : s) {
            cnt[ch-'a']++;
        }
        long long ans = 0;
        for (int i=0; i<n ;i++) {
            int smaller  = 0;
            for (int j=0 ; j<s[i]-'a';j++) {
    smaller += cnt[j];
}        
long long ways = fact[n-i-1];
ways = ways*smaller%MOD;
for (int j=0;j<26;j++){
    ways = ways*invfact[cnt[j]] % MOD;
}
ans = (ans+ways) % MOD;
cnt[s[i]-'a']--;
    }
    return ans;
}
};