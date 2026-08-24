class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int a = *min_element (arr.begin() , arr.end());
        int maxi = *max_element (arr.begin() , arr.end());
        int n = arr.size();
        int d = (maxi - a)/(n-1);
        if ((maxi - a) % (n - 1) != 0)
    return false;
        unordered_set<int> st(arr.begin() , arr.end());
        for(int i=0;i<n;i++) {
            if(st.find(a+i*d)==st.end()){
                return false;
            }
        }
        return true;
    }
};