class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mpp;

        for(char ch : s)
            mpp[ch]++;

        for(int i=0; i<s.size(); i++) 
            if(mpp[s[i]] == 1)
                return i;
        
        return -1;
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();

