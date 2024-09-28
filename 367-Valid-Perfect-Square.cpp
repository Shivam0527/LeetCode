class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(mid == num/mid) {
                if(mid*mid == num) return true;
                else left = mid + 1;
            }

            else if(mid > num/mid) right = mid - 1;

            else left = mid + 1;
        }

        return false;
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();