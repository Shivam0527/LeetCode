class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int n = words.size();
        vector<int> ans;
        vector<int> ansTillPoint(n, 0);


        for(int i=0; i<n; i++) {
            char firstChar = words[i][0];
            char lastChar = words[i].back();

            if(i != 0)
                ansTillPoint[i] = ansTillPoint[i-1];

            if(vowels.find(firstChar) != vowels.end() && vowels.find(lastChar) != vowels.end()) {
                ansTillPoint[i] += 1;
            }
        }

        for(auto& it : queries) {
            int start = it[0];
            int end = it[1];

            if(start == 0)
                ans.push_back(ansTillPoint[end]);
            else
                ans.push_back(ansTillPoint[end] - ansTillPoint[start - 1]);
        }
        
        return ans;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
