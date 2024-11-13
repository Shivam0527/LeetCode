class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        sort(players.begin(), players.end());       
        sort(trainers.begin(), trainers.end());  

        int l = 0, r = 0;
        int maxNum = 0;

        while(l < players.size() && r < trainers.size()) {
            if(players[l] <= trainers[r]) {
                maxNum++;
                l++;
                r++;
            }
            else {
                r++;
            }
        }     

        return maxNum;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
