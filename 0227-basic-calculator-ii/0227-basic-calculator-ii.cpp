class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.length();
        char sign = '+';
        for (int i=0 ; i<n ; i++) {
            char ch = s[i];
            if (isdigit(s[i])) {
                int value = 0;
                while(i<n&&isdigit(s[i])){
                    value = value * 10 + (s[i] - '0');
                    i++;
                    ch = s[i];
                }
                i--;
                if(sign == '+') {
                    st.push(value);
                } else if (sign == '-') {
                    st.push(-value);
                } else if (sign == '*') {
                    int a = st.top();
                    st.pop();
                    int ans = a*value;
                    st.push(ans);
                } else if (sign == '/') {
                    int a = st.top();
                    st.pop();
                    int ans = a/value;
                    st.push(ans);
                }
            } else if(ch != ' ') {
                sign = ch ;
            }
        }
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
            }
};