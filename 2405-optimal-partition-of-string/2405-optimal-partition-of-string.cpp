class Solution {
public:
    int partitionString(string s) {
        vector<int> lastseen(26,-1);
        int cnt = 0;
        int curr = 0;
        for (int i=0 ; i<s.length() ; i++) {
            char ch = s[i];
            if(lastseen[ch-'a']>=curr) {
                cnt++;
                curr = i;
            }
            lastseen[ch-'a'] = i;
        }
        return cnt+1;
    }
};