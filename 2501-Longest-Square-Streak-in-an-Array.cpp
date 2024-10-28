class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        unordered_set<double> st;

        for(int it : nums) {
            st.insert(it);
        }

        int maxCnt = 0;

        for(int it : nums) {
            int cnt = 0;

            double root = pow(it, 1.0/2.0);

            while(st.find(root) != st.end()) {
                cnt++;

                root = pow(root, 1.0/2.0);
            }

            long long sq = static_cast<long long>(it) * it;

            while(st.find(sq) != st.end()) {
                cnt++;

                sq = sq * sq;
            }

            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt == 0 ? -1 : maxCnt + 1;        
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
