class Solution {
public:
    int heightChecker(vector<int>& heights) {

        vector<int> temp(heights.begin(), heights.end());

        sort(temp.begin(), temp.end());

        int cnt = 0;

        for(int i=0; i<heights.size(); i++) {
            if(heights[i] != temp[i])
                cnt++;
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
