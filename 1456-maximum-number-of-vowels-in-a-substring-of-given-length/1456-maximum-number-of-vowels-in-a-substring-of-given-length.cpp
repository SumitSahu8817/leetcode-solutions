class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0 , j = 0;
        int ans = 0;
        int n = s.length();
        int cnt = 0;
        while (j<n) {
            if (s[j]=='a' || s[j]=='e' || s[j]=='i'||s[j]=='o'||s[j]=='u') {
                cnt++;
            }
            if (j-i+1==k) {
                ans = max (ans , cnt);
                if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                    cnt--;
                   
                }
                 i++;
            }
            j++;
        }
        return ans;
    }
};