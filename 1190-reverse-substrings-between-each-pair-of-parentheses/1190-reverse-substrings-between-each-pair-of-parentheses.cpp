class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string result ;
        for (auto &c : s) {
            if (c=='(') {
                st.push(result.size());
            } else if (c==')') {
                int l = st.top();
                st.pop();
                reverse (result.begin()+l , result.end());
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};