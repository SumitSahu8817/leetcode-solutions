class Solution {
public:

        static const long long MOD = 1e9+7;

        long long modPow(long long a, long long e) {
            if (e == 0) return 1;
            long long half = modPow(a,e / 2);
            half = half * half % MOD;
            if(e % 2)
            half = half * a % MOD;
            return half;
        }
        
        long long c(int n , int r , vector<long long>& fact , vector<long long>& inv){
            if(r>n||n<0||r<0){
                return 0;
            }
            return fact[n]*inv[n-r]%MOD*inv[r]%MOD;
        }

    int countValidSequences(int n, int k) {
        
        vector<long long> fact(n+1);
        vector<long long> inv(n+1);

        fact[0]=1;
        for(int i=1;i<=n;i++){
            fact[i]=fact[i-1] * i % MOD;
        }

        inv[n] = modPow(fact[n],MOD-2);
        for(int i=n;i>=1;i--){
            inv[i-1] = inv[i]*i%MOD;
        }

        

        long long total = c(n-1,k-1,fact,inv);
        long long odd = 0;

        if((n-k)%2==0){
            long long m = (n-k)/2;
             odd = c(m+k-1,k-1,fact,inv);
        }
        return (total-odd+MOD)%MOD;
    }
};