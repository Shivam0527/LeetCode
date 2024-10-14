class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int maxi = 0;
        int cnt = 0;

        unordered_set<char> st;

        for(int i=0; i<s.size(); i++) {
            if(st.find(s[i]) == st.end()) {
                cnt++;
                st.insert(s[i]);
            }
            else {
                maxi = max(maxi, cnt);

                while(i-cnt <= i && s[i-cnt] != s[i]) {
                    st.erase(s[i-cnt]);
                    cnt--;
                }
            }
        }

        maxi = max(maxi, cnt);
        
        return maxi;
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
