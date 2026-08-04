class Solution {
public:
    bool isSubsequence(string s, string t) {
        int first_s = 0;
        int first_t = 0;
        int s_len = s.length();
        int t_len = t.length();
        // loop with 2 ptr
        while(first_s < s_len && first_t < t_len) {
            if(s[first_s] == t[first_t]) {
                first_s++;
            }
            first_t++;
        }
        // if s fully traversed, return true
        if(first_s == s_len) {
            return true;
        }
        return false;
    }
};