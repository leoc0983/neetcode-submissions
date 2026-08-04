class Solution {
public:
    unordered_set<int> visited;
    bool isHappy(int n) {
        if (visited.contains(n)) {
            return false;
        }
        visited.insert(n);
        int sum_squares = 0;
        while(n > 0) {
            int last_digit = n % 10;
            sum_squares += last_digit * last_digit;
            n = n/10;
        }
        if(sum_squares == 1) {
            return true;
        } else {
            return isHappy(sum_squares);
        }

    }
};
