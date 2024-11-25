class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mpp;

        for(char c : magazine)
            mpp[c]++;

        for(char c : ransomNote) {
            if(mpp[c] <= 0)
                return false;

            mpp[c]--;
        }

        return true;        
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
