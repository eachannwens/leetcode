#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        
        int m = n1 + 1;
        int n = n2 + 1;

        // Initialize DP matrix
        vector<int> dp(m * n, 0);
        for (int i = 0; i < m; i++) {
            dp[i] = i;
        }
        for (int j = 0; j < n; j++) {
            dp[j*m] = j;
        }

        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (word1[i-1] == word2[j-1]) {
                    // If they are same, it means needn't do anything,
                    // just pick the optimal value of previous one.
                    dp[j*m+i] = dp[(j-1)*m+(i-1)];
                } else {
                    // No matter insert, delete or replace,
                    // for two neighbors, it only need 1 step.
                    dp[j*m+i] = 1 + min(min(dp[(j)*m+(i-1)], dp[(j-1)*m+(i)]), dp[(j-1)*m+(i-1)]);
                }
            }
        }
        
        return dp[dp.size()-1];
    }
};

int main() {
    string word1 = "horse";
    string word2 = "ros";
    Solution s;
    cout << s.minDistance(word1, word2) << endl;
    return 0;
}