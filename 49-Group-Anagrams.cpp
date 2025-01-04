class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mpp;

        for(int i=0; i<strs.size(); i++) {
            string word = strs[i];

            sort(word.begin(), word.end());

            mpp[word].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto it : mpp)
            ans.push_back(it.second);

        return ans;        
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
