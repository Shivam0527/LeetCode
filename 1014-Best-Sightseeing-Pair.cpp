const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;
        for(int i=0; i<points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            double dist = sqrt(x*x+y*y);
            pq.push({dist, i});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};