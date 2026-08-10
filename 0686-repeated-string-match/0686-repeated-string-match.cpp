class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int lena = a.length();
        int lenb = b.length();

        int n = (lenb/lena);
        int cnt = n;
        string str = "";
        while(cnt--){
                str = str + a;
        }
        if(str.find(b)!= std::string::npos){
            return n;
        }
        str = str + a;
         if(str.find(b)!= std::string::npos){
            return n+1;
        }
        str = str + a;
         if(str.find(b)!= std::string::npos){
            return n+2;
        }
        return -1;

    }
};