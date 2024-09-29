class Solution {
public:
    int arrangeCoins(int n) {

        if(n == 1) return n;

        int left = 1, right = n;

        while(left <= right) {
            long long mid = left + (right - left) / 2;

            long long temp = mid * (mid + 1) / 2;

            if(temp == n) return mid;
            else if(temp > n) right = mid - 1;
            else left = mid + 1;
        }

        return right;        
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
