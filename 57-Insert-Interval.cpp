class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        if(n == 0)
            return {newInterval};
        
        int startIdx = 0;

        vector<vector<int>> ans;

        while(startIdx < n && intervals[startIdx][1] < newInterval[0]) {
            ans.push_back(intervals[startIdx]);
            startIdx++;
        }

        while(startIdx<n && newInterval[1] >= intervals[startIdx][0]) {
            newInterval[0] = min(newInterval[0], intervals[startIdx][0]);
            newInterval[1] = max(newInterval[1], intervals[startIdx][1]);
            startIdx++;
        }

        ans.push_back(newInterval);

        while(startIdx < n) {
            ans.push_back(intervals[startIdx]);
            startIdx++;
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
