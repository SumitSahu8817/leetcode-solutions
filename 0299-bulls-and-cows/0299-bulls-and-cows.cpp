class Solution {
public:
    string getHint(string secret, string guess) {
        int c  = 0;
         int b = 0;
         unordered_map<char , int> mp1;
         unordered_map<char , int> mp2;
         int n = secret.size();
        for (int i=0 ; i<n ;i++) {
            if (secret[i] == guess[i]) {
                b++;
            } else {
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        for (auto &it : mp1) {
            if (mp2.find(it.first)!=mp2.end()) {
                c += min (it.second , mp2[it.first]);
            }
        }
          return to_string(b) + "A" + to_string(c) + "B";
    }
};