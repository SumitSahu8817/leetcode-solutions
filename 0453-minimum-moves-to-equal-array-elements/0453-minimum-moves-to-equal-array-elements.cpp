class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = *min_element (nums.begin() , nums.end());
        int opr = 0;
        for (auto it : nums) {
            opr += it-min;
        }
        return opr;
      
        
    }
};