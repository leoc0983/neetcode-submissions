class Solution {
public:
    int maxArea(vector<int>& heights) {
        int first = 0;
        int last = heights.size() - 1;
        int max_area = 0;
        while(first < last) {
            // find shorter bar
            int shorter = first;
            if(heights[first] - heights[last] > 0) {
                shorter = last;
            }
            int cur_area = heights[shorter] * (last - first);
            if(cur_area > max_area) {
                max_area = cur_area;
            }
            if(shorter == first) {
                first++;
            } else {
                last--;
            }
        }
        return max_area;
    }
};