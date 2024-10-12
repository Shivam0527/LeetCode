class Solution {
public:
    bool isUgly(int n) {
        if(n == 1) return true;
        if(n == 0) return false;

        while(n % 2 == 0) n /= 2;
        if(n == 1) return true;
        while(n % 3 == 0) n /= 3;
        if(n == 1) return true;
        while(n % 5 == 0) n /= 5;
        if(n == 1) return true;

        return false;
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
