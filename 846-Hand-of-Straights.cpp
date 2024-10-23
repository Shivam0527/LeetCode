class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if(hand.size() % groupSize != 0) return false;

        unordered_map<int, int> mpp;

        for(int it : hand) mpp[it]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto it : mpp) {
            pq.push({it.first, it.second});
        }

        while(!pq.empty()) {

            vector<pair<int, int>> temp;

            int prev = pq.top().first;

            temp.push_back({pq.top().first, pq.top().second - 1});
            pq.pop();

            int i = 1;

            while(i < groupSize) {

                if(pq.top().first == prev + 1) {

                    prev = pq.top().first;

                    temp.push_back({pq.top().first, pq.top().second - 1});
                    pq.pop();

                    i++;
                }
                else {
                    return false;
                }
            }

            for(auto it : temp) {
                if(it.second != 0) {
                    pq.push({it.first, it.second});
                }
            }
        }

        return pq.size() == 0;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();