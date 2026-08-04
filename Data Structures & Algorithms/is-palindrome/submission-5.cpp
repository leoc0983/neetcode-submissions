class Solution {
public:
    bool isPalindrome(string s) {
        int first = 0;
        int last = s.length() - 1;
        while(first < last) {
            if(!isalnum(s[first])) {
                first++;
            } else if(!isalnum(s[last])) {
                last--;
            } else if(toupper(s[first]) != toupper(s[last])) {
                return false;
            } else {
                first++;
                last--;
            }
        }
        return true;
    }
};
