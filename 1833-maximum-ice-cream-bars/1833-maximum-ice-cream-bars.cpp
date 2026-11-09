class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = *max_element (costs.begin() , costs.end());
        int cnt = 0;
        vector <int> fre(maxi + 1 , 0);
        for (auto &it : costs) {
            fre[it]++;
        }
        for (int i=1 ; i<=maxi ; i++) {
            while (fre[i] > 0 && coins >= i ) {
                coins -= i;
               
                cnt++;
                 fre[i]--;
            }
            if (coins < i )
            break;
        }
        return cnt;
    }
};