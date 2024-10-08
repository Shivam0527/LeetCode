class Solution {
public:
    int calculate(string s) {

        stack<int> nums, ops;

        long long total = 0;
        long long sign  = 1;
        long long num  = 0;

        for(int i=0; i<s.size(); i++) {
            char c = s[i];

            if(c >= '0') {
                while(i < s.size() && s[i] >= '0')
                    num = 10 * num + s[i++] - '0';

                i--;
            }

            else  {
                total += sign * num;
                num = 0;

                if(c == '+') sign = 1;

                if(c == '-') sign = -1;

                if(c == '(') {
                    nums.push(total);

                    ops.push(sign);

                    total = 0;
                    sign = 1;
                }

                if(c == ')' && ops.size()) {
                    total = ops.top() * total + nums.top();

                    ops.pop();
                    nums.pop();
                }
            }
        }

        total += sign * num;

        return total;
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
