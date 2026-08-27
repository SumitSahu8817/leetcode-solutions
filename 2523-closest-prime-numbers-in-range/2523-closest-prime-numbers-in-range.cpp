class Solution {
public:

    vector<bool> seive(int n) {
        vector<bool > isprime(n+1,true);
        isprime[0] = false;
        isprime[1] = false;
        for (int i=2 ; i*i <= n ; i++) {
            if(isprime[i]==true) {
                for (int j=2 ; i*j<=n ; j++) {
                    isprime[i*j] = false;
                }
            }
        }
        return isprime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isprime = seive(right);
        vector<int> prime;
        for (int i=left ; i<=right ; i++) {
            if (isprime[i]==true) {
                prime.push_back(i);
            }
        }
        int mind = INT_MAX;
        vector<int> ans = {-1,-1};

        for (int i=1 ; i<prime.size() ; i++) {
            if ((prime[i]-prime[i-1])<mind) {
                mind = prime[i]-prime[i-1];
                ans = {prime[i-1],prime[i]};
                
            }
        }
        return ans;
    }
};