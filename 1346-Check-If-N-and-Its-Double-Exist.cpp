class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        for(int i=0; i<arr.size(); i++) {
            int doubleVal = 2 * arr[i];

            int left = 0, right = n-1;

            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(mid != i && arr[mid] == doubleVal) return true;
                else if(arr[mid] > doubleVal) right = mid - 1;
                else left = mid + 1;
            }
        }

        return false;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();