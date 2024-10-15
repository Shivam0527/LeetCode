class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;

        unordered_map<int, int> mpp;
        int left = 0, right = 0;

        while(right < n && left < n) {
            mpp[fruits[right]]++;

            if(mpp.size() <= 2) {
                maxLen = max(maxLen, right-left+1);
            }
            else {
                while(mpp.size() != 2) {

                    mpp[fruits[left]]--;

                    if(mpp[fruits[left]] == 0) {
                        mpp.erase(fruits[left]);
                    }
                        
                    left++;
                }
            }

            right++;
        }

        return maxLen;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
