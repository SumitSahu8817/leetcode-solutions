class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        long long result = 0;
        int n = s.length();
        int sign = 1;
        stack<int> st;
        for (int i=0;i<n;i++) {
            if(isdigit(s[i])){
                    num = num*10 + (s[i]-'0');
            } else if (s[i]=='+') {
                    result += (num*sign);
                    num = 0;
                    sign = 1;
            } else if (s[i]=='-') {
                    result = result + num*sign;
                    num = 0;
                    sign = -1;
            } else if (s[i]=='('){
                    st.push(result);
                    st.push(sign);
                    result = 0;
                    sign = 1;
            } else if(s[i]==')'){
                    result += num*sign;
                    num = 0;
                    // sign = 1;
                   int presign = st.top(); st.pop();
                   long long preresult = st.top(); st.pop();
                   result = result*presign + preresult;
                   sign = 1;
            }
        }
        result += num*sign;
        return result;
    }
};