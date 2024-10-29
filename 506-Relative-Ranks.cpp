class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        map<int, int, greater<int>> mpp;
        int n = score.size();

        for(int i=0; i<n; i++) {
            mpp[score[i]] = i;
        }

        vector<string> ans(n);
        int cnt = 1;

        for(auto it : mpp) {
            if(cnt <= 3) {
                if(cnt == 1)
                    ans[it.second] = \Gold Medal\;
                else if(cnt == 2)
                    ans[it.second] = \Silver Medal\;
                else
                    ans[it.second] = \Bronze Medal\;   
                cnt++;                 
            }
            else {
                ans[it.second] = to_string(cnt);        
                cnt++;        
            }
        }

        return ans;        
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
