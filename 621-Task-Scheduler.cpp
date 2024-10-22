class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> map(26, 0);
        priority_queue<int> pq;

        for(char ch : tasks) map[ch - 'A']++;

        for(int i=0; i<26; i++) {
            if(map[i] > 0) {
                pq.push(map[i]);
            }
        }

        int ans = 0;

        while(!pq.empty()) {

            vector<int> temp;

            for(int i=1; i <= n+1; i++) {

                if(!pq.empty()) {

                    int freq = pq.top();

                    pq.pop();
                    freq--;

                    temp.push_back(freq);
                }
            }

            for(int i=0; i<temp.size(); i++) {
                if(temp[i] > 0) {
                    pq.push(temp[i]);
                }
            }

            if(pq.empty()){
                ans += temp.size();
            }
            else {
                ans += (n+1);
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
