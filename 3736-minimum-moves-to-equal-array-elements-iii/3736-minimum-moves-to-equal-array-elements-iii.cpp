class Solution {
public:
    int minMoves(vector<int>& nums) {
        int opr = 0;
        int maxi = *max_element (nums.begin() , nums.end());
        for (auto it : nums) {
            opr += maxi - it;
        }
        return opr;
    }
};