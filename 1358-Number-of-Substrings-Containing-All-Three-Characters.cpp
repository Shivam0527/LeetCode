class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        
        int cnt = 0;
        int left = 0, right = 0;
        vector<int> vec(3, 0);

        while(right < n) {
            
            vec[s[right] - 'a']++;

            while(vec[0]>0 && vec[1]>0 && vec[2]>0) {
                cnt += (n - right);
                
                vec[s[left] - 'a']--;

                left++;
            }        

            right++;
        }        

        return cnt;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
