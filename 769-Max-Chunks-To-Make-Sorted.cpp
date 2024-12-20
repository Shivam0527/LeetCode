class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        
        int co = 0, sum1 = 0, ans = 0;

        for(int i=0; i<v.size(); i++) {
            sum1 += i;
            co += v[i];
            if (sum1 == co)
                ans++;
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
