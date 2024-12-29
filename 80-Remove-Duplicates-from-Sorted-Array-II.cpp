class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // No need to process arrays of size 2 or smaller

        int index = 2; // Start placing elements from the 3rd position onward

        for (int i = 2; i < n; i++) {
            // If the current number is not the same as the number two places back
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i]; // Place it in the array
                index++; // Increment the index for placement
            }
        }

        return index; // Return the new length of the array
    }
};
