class Solution {
public:
    bool isPrefixAndSuffix(string &s2, string &s1) {
        if(s2.size() > s1.size())
            return false;

        if(s1.find(s2) == 0 && s1.rfind(s2) == s1.size()-s2.size())
            return true;

        return false;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;

        for(int i=0; i<n; i++) 
            for(int j=i+1; j<n; j++) 
                if(isPrefixAndSuffix(words[i], words[j]))
                    cnt++;

        return cnt;
    }
};