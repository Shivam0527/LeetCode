class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return \\;

        unordered_map<char, int> needFreqs;

        for(char c : t) {
            needFreqs[c]++;
        }

        int countReq = t.size();

        int minLen = INT_MAX;
        int startIndex = 0;

        int left = 0, right = 0;

        while(right < s.size()) {

            if(needFreqs[s[right]] > 0) {
                countReq--;
            }

            needFreqs[s[right]]--;

            while(left <= right && countReq == 0) {

                if(minLen > right - left + 1) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                needFreqs[s[left]]++;

                if(needFreqs[s[left]] > 0) countReq++;

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? \\ : s.substr(startIndex, minLen);        
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
