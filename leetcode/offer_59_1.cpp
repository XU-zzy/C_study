class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k > nums.size() || k <= 0) {
            return {};
        }

        vector<int> res;
        int start = 0, end = k - 1;

        while (end < nums.size()) {
            int temp = INT_MIN;

            for (int i = start; i <= end; ++i) {
                temp = max(temp, nums[i]);
            }

            res.push_back(temp);
            start++; end++;
        }

        return res;
    }
};
