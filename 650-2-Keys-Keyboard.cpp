// Iterative Solution with O(N)

class Solution {
public:
    int minSteps(int n) {
        int steps = 0;

        for(int i=2; i<=n; i++) {
            while(n%i == 0) {
                steps += i;
                n /= i;
            }
        }

        return steps;
    }
};



// Recursive Solution with memo, TC = O(N^2);

// class Solution {
// public:
//     int calMinSteps(int n,int cnt, int lastCopied, int strLength, vector<vector<int>>& dp) {
//         if(n == strLength) return dp[strLength][lastCopied] = cnt;
//         else if(strLength > n) return INT_MAX;

//         if(dp[strLength][lastCopied] != -1) return dp[strLength][lastCopied];

//         return dp[strLength][lastCopied] = min(calMinSteps(n, cnt+2, strLength, strLength*2, dp), calMinSteps(n, cnt+1, lastCopied, strLength + lastCopied, dp));
//     }

//     int minSteps(int n) {
//         if(n == 1) return 0;

//         vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

//         return calMinSteps(n, 2, 1, 2, dp);
//     }
// };
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();