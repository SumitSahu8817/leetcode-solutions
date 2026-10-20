class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector< int> dif(n+2,0);
        int m = bookings.size();
        for (auto &it : bookings) {
            int st = it[0];
            int ed = it[1];
            int seats = it[2];
            dif[st] += seats;
            dif[ed+1]-= seats;

        }
        vector <int> ans ;
        int cursum = 0;
        for (int i=1 ; i<=n ; i++) {
            cursum += dif[i];
            ans.push_back(cursum);
        }
        return ans;
    }
};