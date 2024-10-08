class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor1=0;

        for(int i=0; i<nums.size(); i++) {
            xor1 = xor1^nums[i];
        }

        int mask = xor1 & -xor1;

        int v1 = 0, v2 = 0;

        for(int i=0; i<nums.size(); i++) {
            if(mask&nums[i]) {
                v1 ^= nums[i];
            } 
            else {
                v2 ^= nums[i];
            }
        }

        return {v1, v2};
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
