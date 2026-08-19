class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> rows;
        for (auto &x:reservedSeats) {
            rows[x[0]].insert(x[1]);
        }
        int ans = 2*(n-rows.size());
        for (auto &[row,seats] : rows) {
            bool left = true;   
            bool right = true;  
            bool middle = true; 
            for (int i = 2; i <= 5; i++) {
                if (seats.count(i)) {
                    left = false;
                    break;
                }
            }
            for (int j = 6; j <= 9; j++) {
                if (seats.count(j)) {
                    right = false;
                    break;
                }
            }
            for (int k = 4; k <= 7; k++) {
                if (seats.count(k)) {
                    middle = false;
                    break;
                }
            }
            if(left && right){
                ans += 2;
            }
            else if(left || right || middle)
                ans += 1;
        }
        return ans;
    }
};