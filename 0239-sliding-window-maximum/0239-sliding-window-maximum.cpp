class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> result;
        int j = 0;
        while (j<n) {
            while (!deq.empty() && deq.front()<=j-k) {
                deq.pop_front();
            }
            while (!deq.empty() && nums[j]>nums[deq.back()]) {
                deq.pop_back();
            }
            deq.push_back(j);
            if (j>=k-1) {
                result.push_back(nums[deq.front()]);
            }
            j++;
        }
        return result;
    }
};