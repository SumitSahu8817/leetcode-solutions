class Solution {
public:
    bool check(vector<int> &nums) {
        for (auto &it : nums) {
            if(it!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int i = 0 , j = 0;
        vector<int> counter(26,0);
        for (auto &it : p) {
            counter[it-'a']++;
        }
        int n = s.length();
        vector<int> ans;
        int k = p.size();
        while (j<n) {
            counter[s[j]-'a']--;
            if((j-i+1)==k) {
               if(check(counter)) {
                ans.push_back(i);
               }
               counter[s[i]-'a']++;
               i++;
            }
            j++;
        }
        return ans;
    }
};