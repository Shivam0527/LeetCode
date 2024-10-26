class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();

        // Sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());

        int cnt = 1;  // Start with 1 to count the first maximum element
        int i = 0;

        // Iterate through sorted elements to find the third distinct max
        while (i < n - 1 && cnt < 3) {
            if (nums[i] != nums[i + 1]) 
                cnt++;  // Found a new unique maximum element
            i++;
        }

        // If fewer than 3 unique elements exist, return the largest element
        if (cnt < 3) return nums[0];
        
        // Otherwise, return the third maximum element
        return nums[i];        
    }
};
const int ZERO = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
