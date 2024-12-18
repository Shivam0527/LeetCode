class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0, r = 0;
        int cnt = 0;

        while(l < g.size() && r < s.size()) {
            if(g[l] <= s[r]) {
                cnt++;
                l++;
                r++;
            }
            else {
                r++;
            }
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
