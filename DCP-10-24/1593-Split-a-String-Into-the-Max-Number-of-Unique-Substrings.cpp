class Solution {
public:

    int findMaxUniSplit(unordered_set<string>& st,string s, int ind) {
        if(ind == s.size()) return st.size();

        int maxLen = 0;

        for(int i=ind; i<s.size(); i++) {

            string temp = s.substr(ind, i - ind + 1);

            if(st.find(temp) == st.end()) {
            
                st.insert(temp);

                maxLen = max(maxLen, findMaxUniSplit(st, s, i+1));

                st.erase(temp);
            }
            
        }

        return maxLen;
    }

    int maxUniqueSplit(string s) {
        
        unordered_set<string> st;

        return findMaxUniSplit(st, s, 0);
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
