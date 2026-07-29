class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(),s.end());
        map<char,int> mp;
        string ans = "";
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto &x : mp){
            if(x.second!=1){
                if(x.second%2==0){
                int size = x.second/2;
                while(size--){
                    ans.push_back(x.first);
                }
                x.second = 0;
                }else{
                    int size = x.second/2;
                    while(size--){
                        ans.push_back(x.first);
                    }
                    x.second = 1;
                }
            }
        }
        char middle ='\0';
        for(auto &x : mp){
            if(x.second == 1){
            
            middle =  x.first;
        }
        }
     string reversed = ans;
     reverse(reversed.begin(),reversed.end());

        if(middle!='\0'){
            return ans + middle + reversed;
        }else{
            return ans+reversed;
        }
    }
};