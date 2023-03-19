#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Initialize DP matrix
        int x = text1.size(), y = text2.size();
        vector<int> dpMatrix((x+1) * (y+1), 0);
        // x-axis is text1 with index i
        // y-axis is text2 with index j
        for (int j = 1; j < y+1; j++) {
            for (int i = 1; i < x+1; i++) {
                if (text1[i-1] == text2[j-1]) {
                    // Matching, two pointer both need to move
                    dpMatrix[j*(x+1)+i] = dpMatrix[(j-1)*(x+1)+(i-1)] + 1;
                } else {
                    // Un-matching, move one pointer
                    dpMatrix[j*(x+1)+i] = max(dpMatrix[j*(x+1)+(i-1)], dpMatrix[(j-1)*(x+1)+i]);
                }
            }
        }
        // Output
        return dpMatrix[dpMatrix.size()-1];
    }
};

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    Solution s;
    cout << s.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}