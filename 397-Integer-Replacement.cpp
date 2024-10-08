// Recusrive Approach

class Solution {
public:
    int calSteps(long long n, int cnt) {
        if(n == 1) return cnt;

        if(n%2 == 1) {
            return min(calSteps(n-1, cnt+1), calSteps(n+1, cnt+1));
        }

        return calSteps(n/2, cnt+1);
    }
    int integerReplacement(int n) {
        
        return calSteps(n, 0);
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
