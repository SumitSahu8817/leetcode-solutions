class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map <int , int> events;
        for (auto &it : logs) {
            int st = it[0];
            int ed = it[1];

            events[st] += 1;
            events[ed] -= 1;

        }
        int cur = 0 , maxi = 0  ;
        int yr;
        for (auto &it : events) {
            cur = cur + it.second;
            if (cur > maxi) {
                maxi = cur;
                yr = it.first;
            }
        }
        return yr;
    }
};