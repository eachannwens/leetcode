#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

// 416. Partition Equal Subset Sum
class Solution {
public:
    bool helper(double x) {
        // Whether a number is an integar or not
        if (trunc(x) == x) {
            return true;
        } else {
            return false;
        }
    }
    bool canPartition(vector<int>& nums) {
        int target;
        int sumOfNums = accumulate(nums.begin(), nums.end(), 0);
        cout << sumOfNums / 2.0 << endl;
        if (helper(sumOfNums / 2.0)) {
            target = sumOfNums / 2.0;
        } else {
            return false;
        }
        // Same as 0/1 knapsack
        vector<bool> dp((nums.size()+1) * (target+1), false);
        // In the first row, the sum of 0 item is 0, that's true.
        dp[0] = true;
        for (int r = 1; r <= nums.size(); r++) {
            for (int c = 0; c <= target; c++) {
                // un-pick -> same as previous row
                bool u = dp[(r-1)*(target+1)+c];
                // pick
                bool p;
                if (c - nums[r-1] >= 0) {
                    p = dp[(r-1)*(target+1)+(c-nums[r-1])];
                } else {
                    p = false;
                }
                // join
                dp[r*(target+1)+c] = u || p;
            }
        }

        for (int r = 0; r <= nums.size(); r++) {
            for (int c = 0; c <= target; c++) {
                cout << dp[r*(target+1)+c] << " ";
            }
            cout << endl;
        }

        // Get result
        bool res = false;
        for (int r = 0; r <= nums.size(); r++) {
            if (dp[r*(target+1)+target]) {
                res = true;
                break;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{3,3,3,4,5};
    Solution s;
    cout << s.canPartition(nums) << endl;
    return 0;
}