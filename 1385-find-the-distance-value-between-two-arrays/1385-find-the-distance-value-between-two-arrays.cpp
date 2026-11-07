class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        int n = arr1.size();
        int cnt = 0;
        for (int i=0 ; i<n ; i++) {
            bool valid = true;
            for (auto &it : arr2) {
                if (abs(arr1[i] - it) <= d ) {
                    valid = false;
                    break;
                }
            }
            if (valid)
            cnt++;
        }
        return cnt;
    }
};