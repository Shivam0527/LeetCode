class Solution {
public:
    string countAndSay(int n) {
        
        string ans = \1\;
        int i = 0;

        for(int i=1; i<n; i++) {
            int j = 0;
            string str = \\;

            while(j < ans.size()) {
                int cnt = 0;
                char c = ans[j];

                while(j < ans.size() && ans[j] == c) {
                    cnt++;
                    j++;
                }

                str += (to_string(cnt) + c);
            }

            ans = str; 
        }

        return ans;
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
