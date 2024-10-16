class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        int sum = 0;

        for(int i=n-k; i<n; i++) {
            sum += cardPoints[i];
        }

        int maxSum = sum;
        if(n == k) return sum;

        for(int i=0; i<k; i++) {
            sum = sum + cardPoints[i] - cardPoints[n - k + i];
            maxSum = max(maxSum, sum);
        }

        return maxSum;        
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
