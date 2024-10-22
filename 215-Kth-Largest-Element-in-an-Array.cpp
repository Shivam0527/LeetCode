class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> min_pq;

        for(int it : nums) {

            min_pq.push(it);

            if(min_pq.size() > k) {
                min_pq.pop();
            }
        }

        return min_pq.top();
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();