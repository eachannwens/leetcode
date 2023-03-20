#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    // if nums[i] larger than the maximum value
                    // of the optimal solution (between [0,j] -> as memo or history)
                    // dp[i] can add one base on dp[0] to dp[j]
                    // max(dp[i], dp[j]+1) -> to ensure that the result
                    // is not influenced by the history of other non-optimal solutions.
                    dp[i] = max(dp[i], dp[j] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    std::cout << "C++ version:" << __cplusplus << std::endl;
    vector<int> nums{0,1,0,3,2,3};
    Solution s;
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}