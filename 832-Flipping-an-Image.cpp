class Solution {
public:
    void reverseImage(vector<int>& imageRow) {
        int left = 0;
        int right = imageRow.size() - 1;

        while (left <= right) {
            // Swap and invert in one step
            swap(imageRow[left], imageRow[right]);
            imageRow[left] = 1 - imageRow[left];
            if (left != right) {
                imageRow[right] = 1 - imageRow[right];
            }
            left++;
            right--;
        }
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i = 0; i < image.size(); i++) {
            reverseImage(image[i]);
        }
        return image;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
