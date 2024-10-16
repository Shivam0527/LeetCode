class Solution {
public:
    int subarrayWithAtMostKDistinct(vector<int>& nums, int k) {
        if(k < 0) return -1;

        unordered_map<int, int> mpp;

        int left = 0, right = 0;
        int cnt = 0;

        while(right < nums.size()) {
            mpp[nums[right]]++;

            while(mpp.size() > k && left < right) {
                mpp[nums[left]]--;

                if(mpp[nums[left]] == 0) mpp.erase(nums[left]);

                left++;
            } 

            if(mpp.size() <= k) 
                cnt += (right - left + 1);

            right++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return subarrayWithAtMostKDistinct(nums, k) - subarrayWithAtMostKDistinct(nums, k-1);
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
