class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mini = nums[0];
        stack <pair<int , int>> st;
        for (int k = 1 ; k< nums.size() ; k++) {
            while (!st.empty() && st.top().first <= nums[k]) {
                st.pop();
            }
            while (!st.empty() && st.top().second < nums[k] && nums[k] < st.top().first) {
                return true;
            }
            st.push ({nums[k] , mini});
            mini = min (mini , nums[k]);
        }
        return false;
    }
};