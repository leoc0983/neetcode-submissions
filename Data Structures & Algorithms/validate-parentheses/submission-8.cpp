class Solution {
public:
    bool isValid(string s) {
        int s_len = s.size();
        if(s_len == 0) {
            return true;
        }
        vector<char> stk;
        for(int i = 0; i < s_len; ++i) {
            if(s[i] == '(') {
                stk.push_back('(');
            } else if(s[i] == '{') {
                stk.push_back('{');
            } else if(s[i] == '[') {
                stk.push_back('[');
            } else if(stk.empty() == true) {
                return false;
            } else if(s[i] == '}' && stk[stk.size()-1] == '{') {
                stk.pop_back();
            } else if(s[i] == ')' && stk[stk.size()-1] == '(') {
                stk.pop_back();
            } else if(s[i] == ']' && stk[stk.size()-1] == '[') {
                stk.pop_back();
            } else {
                return false;
            }
        }
        if(stk.empty()) {
            return true;
        }
        return false;
    }
};
