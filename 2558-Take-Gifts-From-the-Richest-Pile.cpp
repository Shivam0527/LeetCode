class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int> pq;

        for(int it : gifts)
            pq.push(it);

        for(int i=0; i<k; i++) {
            int top = pq.top();
            pq.pop();
            pq.push(sqrt(top));
        }

        long long sum = 0;

        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;        
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
