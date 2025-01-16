class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto myComporater = [](int& n1, int& n2){
            string s1 = to_string(n1);
            string s2 = to_string(n2);

            return s1+s2 > s2+s1;
        };

        sort(begin(nums), end(nums), myComporater);

        string ans;

        for(int &s : nums)
            ans += to_string(s);

        if(ans.size() > 0 && ans[0] == '0')
            return \0\;

        return ans;        
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
