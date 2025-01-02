class Solution {
public:
    string reverseWords(string s) {
        if(s.size() <= 1)
            return s;

        int n = s.size();
        int i = 0;

        while(i < n) {
            int startIdx = i;
            int endIdx = -1;

            while(i < n && s[i] != ' ') {
                i++;
            }

            endIdx = i - 1;

            while(endIdx > startIdx) {
                swap(s[startIdx], s[endIdx]);
                startIdx++;
                endIdx--;
            }

            i++;
        }  

        return s;        
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
