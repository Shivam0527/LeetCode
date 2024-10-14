class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;

        int temp = k;
        int cnt = 0;
        
        for(int i=0; i<nums.size(); i++) {

            if(temp == 0 && nums[i] == 0){
                maxi = max(maxi, cnt);

                while(i-cnt <= i && nums[i-cnt] != 0) {
                    cnt--;
                }
            }
            else if(nums[i] == 1) {
                cnt++;
            }
            else {
                cnt++;
                temp--;
            }

        }

        maxi = max(maxi, cnt);

        return maxi;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
