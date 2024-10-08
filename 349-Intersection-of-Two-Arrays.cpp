class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ans;
        
        int pt1 = 0, pt2 = 0;

        while(pt1 < nums1.size() && pt2 < nums2.size()) {
            if(nums1[pt1] == nums2[pt2] && (ans.size() == 0 || ans.back() != nums1[pt1])) {
                ans.push_back(nums1[pt1]);
                pt1++;
                pt2++;
            }
            else if(nums1[pt1] < nums2[pt2]) {
                pt1++;
            }
            else {
                pt2++;
            }
        }

        return ans;
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
