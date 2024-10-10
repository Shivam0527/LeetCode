class Solution {
public:
    long long smallSums(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftSmall(n);
        vector<int> rightSmall(n);

        stack<int> st;
 
        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if(st.empty()) {
                leftSmall[i] = -1;
            } else {
                leftSmall[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if(st.empty()) {
                rightSmall[i] = n;
            } else {
                rightSmall[i] = st.top();
            }

            st.push(i);
        }

        long long sum = 0;

        for(int i=0; i<n; i++) {
            long long contri = ((i - leftSmall[i]) * (rightSmall[i] - i));

            sum = sum + contri * nums[i];
        }

        return sum;
    }

    long long largeSums(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftLarge(n);
        vector<int> rightLarge(n);

        stack<int> st;
 
        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if(st.empty()) {
                leftLarge[i] = -1;
            } else {
                leftLarge[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if(st.empty()) {
                rightLarge[i] = n;
            } else {
                rightLarge[i] = st.top();
            }

            st.push(i);
        }

        long long sum = 0;

        for(int i=0; i<n; i++) {
            long long contri = ((i - leftLarge[i]) * (rightLarge[i] - i));

            sum = sum + contri * nums[i];
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {

        long long sumOfSmalls = smallSums(nums);

        long long sumOfLarges = largeSums(nums);

        return sumOfLarges - sumOfSmalls;        
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
