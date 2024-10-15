class Solution {
public:
    int countNiceSubarrays(vector<int>& nums, int k) {
        if(k < 0) return 0;

        int oddCnt = 0, cnt = 0;
        int left = 0, right = 0;

        while(right < nums.size()) {
            if(nums[right] % 2 == 1) {
                oddCnt++;
            }

            while(oddCnt > k && left < right) {
                if(nums[left] % 2 == 1) oddCnt--;

                left++;
            }

            if(oddCnt <= k) {
                cnt += (right - left + 1);
            }

            right++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return countNiceSubarrays(nums, k) - countNiceSubarrays(nums, k-1);
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
