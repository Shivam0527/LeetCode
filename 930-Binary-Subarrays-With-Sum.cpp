class Solution {
public:
    int SubarrayWithSumLessThanK(vector<int>& nums, int goal) {
        if(goal < 0) return 0;

        int left = 0, right=0;
        long long sum = 0, cnt = 0;

        while(right < nums.size()) {
            sum += nums[right];

            while(sum > goal && left < right) {
                sum -= nums[left];
                left++;
            }

            if(sum <= goal)
                cnt += (right - left + 1);

            right++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return SubarrayWithSumLessThanK(nums, goal) - SubarrayWithSumLessThanK(nums, goal-1);
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
