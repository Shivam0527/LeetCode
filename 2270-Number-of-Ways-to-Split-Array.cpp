class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        vector<long long> forwardSum(n);
        forwardSum[0] = nums[0];

        for(int i=1; i<n; i++) 
            forwardSum[i] = forwardSum[i-1] + nums[i];

        int cnt = 0;

        for(int i=0; i<n-1; i++) {
            long long leftSum = forwardSum[i];
            long long rightSum = forwardSum[n-1] - leftSum;

            if(leftSum >= rightSum)
                cnt++;
        }

        return cnt;       
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
