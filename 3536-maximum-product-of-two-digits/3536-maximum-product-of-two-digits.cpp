class Solution {
public:
    int maxProduct(int n) {
        

        string s = (to_string)(n);
        int size = s.length();
        

        sort(s.begin(),s.end());
        
        return (int)(s[size-1]-'0')*(int)(s[size-2]-'0');
    }
};