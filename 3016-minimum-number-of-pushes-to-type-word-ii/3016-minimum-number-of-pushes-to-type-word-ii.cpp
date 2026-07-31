class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> fre(26,0);
        for(int i=0;i<word.size();i++){
            fre[word[i]-'a']++;
        }
        sort(fre.begin(),fre.end(),greater<int>());
        int push = 0;
        for(int i=0;i<26;i++){
            push += (i/8 + 1) * fre[i];
        }
        return push;
    }
};