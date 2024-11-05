class Solution {
public:
    int trailingZeroes(int n) {

        long long div = 5;
        int cnt = 0;

        while(n >= div) {
            cnt += (n / div);

            div *= 5;
        }

        return cnt;        
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
