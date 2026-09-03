class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0 , j = 0;
        int len = 0;
        int n = s.length();
        vector<bool> cnt(256,0);
        while (j<n) {
                while (cnt[s[j]]!=0) {
                    cnt[s[i]]=0;
                    i++;
                }
                cnt[s[j]]=1;
                len = max (len,j-i+1);
                j++;
        }
        return len;
    }
};